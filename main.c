
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100
#define MAX_RESOURCES 10
enum ProcessState {
    NEW,
    READY,
    RUNNING,
    TERMINATED
};

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

    enum ProcessState state;
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
void initializeProcessList(ProcessList *list)
{
    list->head = NULL;
    list->size = 0;
}
Process createProcess(int processID, int arrivalTime,
                      int burstTime, int priority)
{
    Process p;

    p.processID = processID;
    p.arrivalTime = arrivalTime;
    p.burstTime = burstTime;
    p.priority = priority;

    p.remainingTime = burstTime;
    p.firstStartTime = -1;
    p.completionTime = -1;
    p.turnaroundTime = 0;
    p.waitingTime = 0;
    p.responseTime = -1;

    p.state = NEW;

    return p;
}

int main(void)
{
    ProcessList processList;

    initializeProcessList(&processList);

    printf("Head: %p\n", (void *)processList.head);
    printf("Size: %d\n", processList.size);

    return 0;
}
