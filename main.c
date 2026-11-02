
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
void addProcess(ProcessList *list, Process p){
    ProcessNode *newNode = malloc(sizeof(ProcessNode));
    if(newNode){
        newNode->data=p;
        newNode->next=NULL;
    }
    else 
    return;
    if(list->head==NULL){
       list->head=newNode;
    }
    else{
        ProcessNode *temp=list->head;
        while(temp->next)
            temp=temp->next;
            temp->next=newNode;
        
    }
    (list->size)++;

}
void displayProcesses(ProcessList *list){
    if(!(list->head)){
        printf("The process list empty is empty");
        return;
    }
         ProcessNode *temp=list->head;
         int i=1;
         while(temp){
            printf("Displaying Data of Process %d\n",i);
        printf("Process ID: %d\n", temp->data.processID);
        printf("Arrival Time: %d\n", temp->data.arrivalTime);
        printf("Burst Time: %d\n", temp->data.burstTime);
        printf("Priority: %d\n", temp->data.priority);
        printf("Remaining Time: %d\n", temp->data.remainingTime);
        printf("First Start Time: %d\n", temp->data.firstStartTime);
        printf("Completion Time: %d\n", temp->data.completionTime);
        printf("Turnaround Time: %d\n", temp->data.turnaroundTime);
        printf("Waiting Time: %d\n", temp->data.waitingTime);
        printf("Response Time: %d\n", temp->data.responseTime);
        printf("State: %d\n", temp->data.state);
        printf("-------------------------\n");
                   i++;
                   temp=temp->next;
         }

}
ProcessNode *findProcessByID(ProcessList *list, int processID){
    if(!(list->head)){
        printf("process List is empty");
        return NULL;
    }
    ProcessNode *temp=list->head;
    while(temp){
        if((temp->data).processID==processID)
        return temp;
        temp=temp->next;
    }
    return NULL;
}
int removeProcess(ProcessList *list, int processID){
    if(!(list->head)){
        printf("process List is empty");
        return 0;
    }
      ProcessNode *temp=list->head;
     if((temp->data).processID==processID){
        ProcessNode *delete=temp;
        list->head=temp->next;
        free(delete);
        list->size--;
        return 1; 
     }
    while(temp&&temp->next){
     if((temp->next->data).processID==processID){
         ProcessNode *remb=temp->next->next;
         ProcessNode *delete=temp->next;
         temp->next=remb;
         free(delete);
         list->size--;
         return 1;
     }
     temp=temp->next;
    }
    return 0;
}

int main(void)
{
    ProcessList processList;

    initializeProcessList(&processList);

    printf("Head: %p\n", (void *)processList.head);
    printf("Size: %d\n", processList.size);

    return 0;
}
