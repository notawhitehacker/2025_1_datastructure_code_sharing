
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

queue_t* new_queue(int size, void (*print)(void*)) {
    queue_t* q = malloc(sizeof(queue_t));
    q->data = malloc(size * sizeof(void*));
    q->size = size;
    q->top = size-1;
    q->rear = size-1;

    q->print = print;
    return q;
}

void delete_queue(queue_t* q) {
    free(q->data);
    free(q);
}

void enqueue_queue(queue_t* q, void* item) {
    if (queue_is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    q->data[(++q->top)%q->size] = item;
}

void* dequeue_queue(queue_t* q) {
    if (queue_is_empty(q)) {
        printf("Queue is empty\n");
        return NULL;
    }
    void* item = q->data[(++q->rear)%q->size];
    return item;
}

void print_queue(queue_t* q, char* name) {
    printf("%s\n", name);
    for(int i = 0 ; i < q->top - q->rear ; i++) {
        q->print(q->data[(i+q->rear+1)%q->size]);
    }
    printf("\n");
}

int queue_is_empty(queue_t* q) {
    return (q->top - q->rear == 0);
}

int queue_is_full(queue_t* q) {
    return (q->top - q->rear == q->size);
}

