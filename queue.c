#include "queue.h"

void initializeQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isQueueEmpty(Queue *q)
{
    return q->size == 0;
}

int isQueueFull(Queue *q)
{
    return q->size == MAX_PROCESSES;
}

int enqueue(Queue *q, int processID)
{
    if (isQueueFull(q))
        return 0;

    q->rear = (q->rear + 1) % MAX_PROCESSES;
    q->processIDs[q->rear] = processID;
    q->size++;

    return 1;
}

int dequeue(Queue *q, int *processID)
{
    if (isQueueEmpty(q))
        return 0;

    *processID = q->processIDs[q->front];
    q->front = (q->front + 1) % MAX_PROCESSES;
    q->size--;

    return 1;
}