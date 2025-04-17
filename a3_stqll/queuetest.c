
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

void print_char(void* e) {
    printf("%s ", (char*)e);
}

int main() {
    queue_t* q = new_queue(30, print_char);
    char** str = (char**)malloc(30 * sizeof(char*));
    for (int i = 0; i < 24; i++) {
        str[i] = (char*)malloc(2 * sizeof(char));
        str[i][0] = 'a' + i;
        str[i][1] = '\0';
    }

    printf("Queue is empty: %d\n", queue_is_empty(q));

    for(int i = 0; i < 5; i++) {
        enqueue_queue(q, strdup(str[i]));
        printf("top-rear = %d\n", q->top - q->rear);
    }
    print_queue(q, "Queue after enqueue"); 

    for(int i = 0; i < 3; i++) {
        dequeue_queue(q);
    }
    print_queue(q, "Queue after dequeue");
    for(int i = 7; i < 24; i++) {
        enqueue_queue(q, strdup(str[i]));
    }
    print_queue(q, "Queue after enqueue");
    printf("Queue is full: %d\n", queue_is_full(q));
    for(int i = 0; i < 10; i++) {
        dequeue_queue(q);
    }
    print_queue(q, "Queue after dequeue");
    return 0;

}