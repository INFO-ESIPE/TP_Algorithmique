#include <stdlib.h>
#include <stdio.h>

#include <assert.h>
#include "prioqueue.h"
#include "customer.h"
#include "event.h"

#define MAX_QUEUE_SIZE 100

typedef struct _link {
    event* e;
    struct _link* next;
} link;

struct _prioqueue {
    link* first;
    int size;
};

prioqueue *create_pq() {
    prioqueue *q = (prioqueue*)malloc(sizeof(prioqueue));
    q->first = NULL;
    q->size = 0;
    return q;
}

void free_pq(prioqueue *q) {
    free(q);
}

int size_pq(prioqueue *q) {
    return q->size;
}

void insert_pq(prioqueue *q, event *e) {
    assert(q->size < MAX_QUEUE_SIZE);
    link *new = (link*)malloc(sizeof(link));
    new->e = e;
    new->next = NULL;

    /* Is the list is empty*/
    if(q->first == NULL) {
        q->first = new;
        q->size++;
        return;
    }

    /* If its the first element */
    if(q->first->e->etime > e->etime) {
        new->next = q->first;
        q->first = new;
        q->size++;
        return;
    }

    /* Insert in its place order */
    link *l = q->first;
    while(l->next != NULL && l->next->e->etime < e->etime) {
        l = l->next;
    }
    new->next = l->next;
    l->next = new;
    q->size++;

}

/* Remove the event EVENT_LEAVE_QUEUE of the customer c */
void remove_queue_left_event_pq(prioqueue *q, customer *c) {
    link *l;

    /* Check if the linked list is not empty*/
    if(q->first == NULL) {
        return;
    }

    /* Search the element to remove */
    l = q->first;
    while(l->next != NULL && l->next->e->c != c) {
        l = l->next;
    }

    /* If the element is found, we remove it*/
    if(l->next != NULL) {
        link *tmp = l->next;
        l->next = l->next->next;
        free(tmp);
        q->size--;
    }

}


event *remove_min_pq(prioqueue *q) {
    assert(q->size > 0);

    /* Check if the linked list is not empty*/
    if(q->first == NULL) {
        return NULL;
    }

    /* Get the first link*/
    link *l = q->first;
    event *e = l->e;

    /* Remove the first link*/
    q->first = l->next;
    q->size--;

    /* Free the link*/
    free(l);

    return e;
}


void display_pq(prioqueue *pq) {
    link *l = pq->first;
    printf("pq[");
    while(l != NULL) {
        printf("%d ", l->e->etime);
        l = l->next;
    }
    printf("]\n");
}