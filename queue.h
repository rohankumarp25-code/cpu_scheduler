#ifndef QUEUE_H
#define QUEUE_H

#include "process.h"

typedef struct {
    int processIDs[MAX_PROCESSES];
    int front;
    int rear;
    int size;
} Queue;

/* Queue operations */

void initializeQueue(Queue *q);

int isQueueEmpty(Queue *q);

int isQueueFull(Queue *q);

int enqueue(Queue *q, int processID);

int dequeue(Queue *q, int *processID);

#endif