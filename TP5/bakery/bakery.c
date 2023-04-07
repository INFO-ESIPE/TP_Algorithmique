#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <time.h>
#include "event.h"
#include "customer.h"
#include "queue.h"
#include "prioqueue.h"

#define N_VENDORS 3
#define CLOSING_TIME 10000
#define ARRIVAL_RATE (1.0/60) 
#define MEAN_SERVICE_TIME 150
#define LEFT_QUEUE_AFTER 60

prioqueue*  event_queue;
queue*      customer_queue;
int current_time;

/* Struct containing statistics */
typedef struct _Stats {
    int nb_clients_servis;
    int nb_clients;
    int temps_attente_total;
    int nb_clients_insatisfaits;
} Stats;
Stats stats;

/* Link for a vendor */
typedef struct _Vendor {
    customer* c;
    struct _Vendor* next;
} Vendor;
Vendor* vendors;

double normal_delay(double mean) {
    return -mean*log(1-((double)rand()/RAND_MAX));
}

/**
 * Search a vendor for the customer. If a vendor is free, the customer will be treated, else, the function add the customer to the priority queue.
 * c: customer pointer
*/
void add_customer(customer *c) {
    event *e_departure;
    event *e_left_queue;

	/* Search a free vendor */
    for(Vendor *v = vendors; v != NULL; v = v->next) {
        if(v->c == NULL) {
            v->c = c;
            e_departure = create_departure(current_time + normal_delay(MEAN_SERVICE_TIME), c);
            insert_pq(event_queue, e_departure);
			return;
        }
    } 

	/* If no vendor found, we add the customer to the queue*/
    e_left_queue = create_event(EVENT_LEAVE_QUEUE, current_time + normal_delay(LEFT_QUEUE_AFTER), c);
    insert_pq(event_queue, e_left_queue);
    enqueue_q(customer_queue, c);
}

void remove_customer(customer *c) {
    event* e;
    Vendor* v;

    /* Search the vendor of the customer */
    for(v = vendors; v != NULL; v = v->next) {
        if(v->c == c) {
            v->c = NULL;
            break;
        }
    }

    /* Free the customer */
    free_customer(c);

    if(size_q(customer_queue) != 0) {
        /* Assign the free vendor to the first in client or the queue*/
        customer *c2 = dequeue_q(customer_queue);
        v->c = c2;

        /* Remove the EVENT_LEAVE_QUEUE of the client */
        /*remove_queue_left_event_pq(event_queue, c2);*/


        e = create_departure(current_time + normal_delay(MEAN_SERVICE_TIME), c2);
        insert_pq(event_queue, e);
    }
}

void process_arrival(event *e) {
    stats.nb_clients++;
    customer* c = create_customer(current_time);
    add_customer(c);
    event *arrival_e = create_arrival(current_time + normal_delay(1.0/ARRIVAL_RATE), c);
    insert_pq(event_queue, arrival_e);
}

void process_departure(event *e) {
    stats.nb_clients_servis++;
    stats.temps_attente_total += current_time - e->c->atime;
    remove_customer(e->c);
}

void process_leave_queue(event *e) {
    stats.nb_clients_insatisfaits++;
    /*
    e = create_departure(current_time, e->c);
    insert_pq(event_queue, e);
    */
}

/* Function to print the bakery state */
void print_bakery() {
    int i;

    /* Print time*/
    printf("%3d | ", current_time);

    /* Print vendors */
    for(Vendor *v = vendors; v != NULL; v = v->next) {
        if(v->c != NULL) {
            printf("X");
        } else {
            printf("_");
        }
    }
    printf(" | ");

    /*Print queue*/
    for(i = 0; i < size_q(customer_queue); i++) {
        printf("X");
    }

    printf("\n");
    
}

int main() {
    int i;
    customer* customer;
    event* event;
    current_time = 0;
    srand(time(NULL));

    /* Init stats */
    stats.nb_clients_servis = 0;
    stats.nb_clients = 0;
    stats.temps_attente_total = 0;
    stats.nb_clients_insatisfaits = 0;
    
    /* Init vendor linked list with N_VENDORS vendors*/
    Vendor* v = malloc(sizeof(Vendor));
    vendors = v;
    for(i = 0; i < N_VENDORS; i++) {
        v->c = NULL;
        if(i != N_VENDORS - 1) {
            v->next = malloc(sizeof(Vendor));
            v = v->next;
        } else {
            v->next = NULL;
        }
    }

    /* Init queue */
    event_queue = create_pq();

    /* Unit */
    customer_queue = create_q();

    /* Create the first customer */
    customer = create_customer(current_time);
    insert_pq(event_queue, create_arrival(current_time, customer));

    /* Open the bakery*/
    while(size_pq(event_queue) != 0 && current_time < CLOSING_TIME) {

        /* Get the first in event*/
        event = remove_min_pq(event_queue);

        /* Update current_time */
        current_time = event->etime;

        /* Create event */
        if(event->type == EVENT_ARRIVAL) {
            process_arrival(event);
        } else if(event->type == EVENT_DEPARTURE) {
            process_departure(event);
        } 
    
        else if(event->type == EVENT_LEAVE_QUEUE) {
            process_leave_queue(event);
        }
        

        /* Print the bakery state at the end of the event loop*/
        print_bakery();
    }

    /* If clients remains in the bakery, vendors will serve them*/
    printf("Backery closing...\n");
    while(size_pq(event_queue) != 0) {
        event = remove_min_pq(event_queue);
        current_time = event->etime;

        /* ignore arrivals when bakery is closed*/
        if(event->type == EVENT_DEPARTURE) {
            process_departure(event);
        }
        print_bakery();

    }

    /* Free memory part */
    printf("Freeing memory...\n");

    /* Free remaning customers of the customer_queue */
    while(size_q(customer_queue) != 0) {
        free_customer(dequeue_q(customer_queue));
    }
    /* Free remaining events of the event_queue*/
    while(size_pq(event_queue) != 0) {
        free_event(remove_min_pq(event_queue));
    }
    
    /* Free vendor linked list*/
    for(v = vendors; v != NULL; v = v->next) {
        free(v);
    }

    free_customer(customer); /* Free the first customer*/
    free_q(customer_queue); /* Free the customer queue ptr*/
    free_pq(event_queue); /* Free the event queue ptr */

    /* Print stats after bakery closing*/
    printf("Number of clients served: %d\n", stats.nb_clients_servis);
    printf("Number of clients unsatisfied: %d\n", stats.nb_clients_insatisfaits);
    printf("Number of clients: %d\n", stats.nb_clients);
    printf("Average waiting time: %ds\n", stats.temps_attente_total/stats.nb_clients_servis);
    
    return 0;
}


