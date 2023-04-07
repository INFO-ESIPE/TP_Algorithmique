#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "customer.h"


typedef struct _link {
    customer*       c;
    struct _link*   next;
} link;

struct _queue {
    link*   first;
    link*   last;
    int     size;
};

queue *create_q() {
    queue *q = (queue*)malloc(sizeof(queue));
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
    return q;
}

void free_q(queue *q) {
    /*Free the customers memory before freeing the queue*/
    link *l = q->first;
    while(l != NULL) {
        link *tmp = l;
        l = l->next;
        free(tmp);
    }
    
    /* Free the queue */
    free(q);
}

int size_q(queue *q) {
    return q->size;
}


void display_q(queue *q) {
    link *l = q->first;
    printf("QUEUE[");
    while(l != NULL) {
        printf("%d ", l->c->atime);
        l = l->next;
    }
    printf("]\n");
    
}

void enqueue_q(queue *q, customer *c) {

    /* Set the new link*/
    link *l = (link*)malloc(sizeof(link));
    l->c = c;
    l->next = NULL;

    if(q->first == NULL) {
        /* Insert the new link if the linked list is empty*/
        q->first = l;
        q->last = l;
    } else {
        /* Else Insert the new link at the end of the linked list*/
        q->last->next = l;
        q->last = l;
    }
    
    q->size++;
}


customer *dequeue_q(queue *q) {
    /* Check if the linked list is not empty*/
    if(q->first == NULL) {
        return NULL;
    }

    /* Get the first link*/
    link *l = q->first;
    customer *c = l->c;

    /* Remove the first link*/
    q->first = l->next;
    q->size--;

    /* Free the link*/
    free(l);


    return c;

}



/* Test linked list*/
/*int main() {
    queue *q = create_q();
    customer *c1 = (customer*)malloc(sizeof(customer));
    customer *c2 = (customer*)malloc(sizeof(customer));
    customer *c3 = (customer*)malloc(sizeof(customer));
    customer *c4 = (customer*)malloc(sizeof(customer));

    c1->atime = 1;
    c2->atime = 2;
    c3->atime = 3;
    c4->atime = 4;

    enqueue_q(q, c1);
    display_q(q);

    enqueue_q(q, c2);
    enqueue_q(q, c3);
    enqueue_q(q, c4);

    display_q(q);

    dequeue_q(q);
    dequeue_q(q);
    
    display_q(q);

    dequeue_q(q);
    enqueue_q(q, c1);

    display_q(q);

    free_q(q);
    free(c1);
    free(c2);
    free(c3);
    free(c4);

    return 0;

}
*/