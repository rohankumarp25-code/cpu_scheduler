#define PROCESS_H
#define PROCESS_H

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

/* Process management functions */

void initializeProcessList(ProcessList *list);

Process createProcess(int processID, int arrivalTime,
                      int burstTime, int priority);

void addProcess(ProcessList *list, Process p);

void displayProcesses(ProcessList *list);

ProcessNode *findProcessByID(ProcessList *list, int processID);

int removeProcess(ProcessList *list, int processID);

int updateProcess(ProcessList *list, int processID,
                  int arrivalTime, int burstTime, int priority);

void freeProcessList(ProcessList *list);
