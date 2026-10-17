
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100
#define MAX_RESOURCES 10

typedef struct {
    int processID;
    int arrivalTime;
    int burstTime;
    int priority;

    int remainingTime;
    int firstStartTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;

    int state;
} Process;

typedef struct ProcessNode {
    Process data;
    struct ProcessNode *next;
} ProcessNode;

typedef struct {
    ProcessNode *head;
    int size;
} ProcessList;

typedef struct {
    int processIDs[MAX_PROCESSES];
    int front;
    int rear;
    int size;
} Queue;

typedef struct {
    int processID;
    int startTime;
    int endTime;
} GanttEntry;

typedef struct {
    int processCount;
    int resourceCount;

    int total[MAX_RESOURCES];
    int available[MAX_RESOURCES];

    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int maximum[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
} ResourceState;

int main(void) {
    printf("CPU Process and Resource Management Simulator\n");
    return 0;
}
