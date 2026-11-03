#include "process.h"
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
        printf("The process list  is empty");
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
int updateProcess(ProcessList *list, int processID,
                  int arrivalTime, int burstTime, int priority){
                    ProcessNode *remb= findProcessByID(list,processID);
                    if(remb==NULL){
                        printf("Process doesnt exist");
                        return 0;
                    }
                    else if(remb->data.state==NEW){
                        remb->data.arrivalTime=arrivalTime;
                        remb->data.burstTime=burstTime;
                        remb->data.priority=priority;
                        remb->data.remainingTime=burstTime;
                        remb->data.firstStartTime=-1;
                        remb->data.completionTime=-1;
                        remb->data.turnaroundTime=0;
                        remb->data.waitingTime=0;
                        remb->data.responseTime=-1;
                        remb->data.state=NEW;
                        return 1;
                    }
                    printf("Cannot update a process that has already started scheduling");
                    return 0;
                  }
     void freeProcessList(ProcessList *list){
         ProcessNode *temp=list->head;
         ProcessNode *remb;
         if(!temp){
            printf("process list is empty");
             list->size=0;
         list->head=NULL;
            return;
         }
         while(temp){
            remb=temp->next;
            free(temp);
            temp=remb;
        }
        printf("Now The processlist is empty");
        list->size=0;
         list->head=NULL;
     }
