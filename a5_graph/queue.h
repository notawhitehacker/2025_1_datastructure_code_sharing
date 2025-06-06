
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef struct queue_t {
    void** data;
    int size;
    int top;
    int rear;

    void (*print)(void*);
} queue_t;

queue_t* new_queue(int size, void (*print)());
void delete_queue(queue_t* queue);
void enqueue_queue(queue_t* queue, void* item);
void* dequeue_queue(queue_t* queue);
void print_queue(queue_t* queue, char* name);

int queue_is_empty(queue_t* queue);
int queue_is_full(queue_t* queue);

#endif
