#include "scheduling.h"
#include "string.h"
void scheduleFCFS(Process processes[], int count, GanttChart *chart)
{
    if (count <= 0)
        return;

    resetSchedulingData(processes, count);
    chart->count = 0;

    // Create an array of indices
    int order[MAX_PROCESSES];

    for (int i = 0; i < count; i++)
        order[i] = i;

    // Stable sorting by arrival time (Bubble Sort)
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (processes[order[j]].arrivalTime >
                processes[order[j + 1]].arrivalTime)
            {
                int temp = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp;
            }
        }
    }

    int currentTime = 0;

    // Schedule processes
    for (int i = 0; i < count; i++)
    {
        int index = order[i];

        // Handle CPU idle time
        if (processes[index].arrivalTime > currentTime)
        {
            chart->entries[chart->count].processID = -1;
            chart->entries[chart->count].startTime = currentTime;
            chart->entries[chart->count].endTime =
                processes[index].arrivalTime;

            chart->count++;

            currentTime = processes[index].arrivalTime;
        }

        // Record execution start
        processes[index].firstStartTime = currentTime;

        // Calculate completion time
        currentTime += processes[index].burstTime;

        processes[index].completionTime = currentTime;
        processes[index].remainingTime = 0;
        processes[index].state = TERMINATED;

        // Add to Gantt chart
        chart->entries[chart->count].processID =
            processes[index].processID;

        chart->entries[chart->count].startTime =
            processes[index].firstStartTime;

        chart->entries[chart->count].endTime =
            processes[index].completionTime;

        chart->count++;
    }

    // Calculate individual metrics
    calculateMetrics(processes, count);
}
void resetSchedulingData(Process processes[], int count)
{
    for (int i = 0; i < count; i++)
    {
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].firstStartTime = -1;
        processes[i].completionTime = -1;
        processes[i].turnaroundTime = 0;
        processes[i].waitingTime = 0;
        processes[i].responseTime = -1;
        processes[i].state = NEW;
    }
}
void calculateMetrics(Process processes[], int count){
    if(count<=0){
        printf("process list is empty");
        return;
    }
    int i=0;
    while(i<count){
        processes[i].turnaroundTime=processes[i].completionTime-processes[i].arrivalTime;
        processes[i].waitingTime=processes[i].turnaroundTime-processes[i].burstTime;
          processes[i].responseTime=processes[i].firstStartTime-processes[i].arrivalTime;
        i++;
    }
   
}
void calculateAverages(Process processes[], int count,
                       double *avgWaitingTime,
                       double *avgTurnaroundTime,
                       double *avgResponseTime){
    if (count <= 0) {
        *avgWaitingTime = 0;
        *avgTurnaroundTime = 0;
        *avgResponseTime = 0;
        return;
    }

    *avgWaitingTime = 0;
    *avgTurnaroundTime = 0;
    *avgResponseTime = 0;
    for (int i = 0; i < count; i++) {
        *avgWaitingTime += processes[i].waitingTime;
        *avgTurnaroundTime += processes[i].turnaroundTime;
        *avgResponseTime += processes[i].responseTime;
    }

    *avgWaitingTime /= count;
    *avgTurnaroundTime /= count;
    *avgResponseTime /= count;
}
void displayGanttChart(GanttChart *chart)
{
    if (chart->count == 0) {
        printf("No Gantt chart data available.\n");
        return;
    }

    printf("\nGantt Chart:\n\n");

    // Print top border
    for (int i = 0; i < chart->count; i++) {
        int width = (chart->entries[i].endTime -
                     chart->entries[i].startTime) * 2;

        if (width < 4)
            width = 4;

        printf("+");
        for (int j = 0; j < width; j++)
            printf("-");
    }
    printf("+\n");

    // Print process IDs
    for (int i = 0; i < chart->count; i++) {
        int width = (chart->entries[i].endTime -
                     chart->entries[i].startTime) * 2;

        if (width < 4)
            width = 4;

        printf("|");
        if (chart->entries[i].processID == -1) {
            int padding = (width - 4) / 2;
            for (int j = 0; j < padding; j++)
                printf(" ");
            printf("IDLE");
            for (int j = 0; j < width - padding - 4; j++)
                printf(" ");
        } else {
            char label[20];
            sprintf(label, "P%d", chart->entries[i].processID);

            int len = strlen(label);
            int padding = (width - len) / 2;

            for (int j = 0; j < padding; j++)
                printf(" ");
            printf("%s", label);
            for (int j = 0; j < width - padding - len; j++)
                printf(" ");
        }
    }
    printf("|\n");

    // Print bottom border
    for (int i = 0; i < chart->count; i++) {
        int width = (chart->entries[i].endTime -
                     chart->entries[i].startTime) * 2;

        if (width < 4)
            width = 4;

        printf("+");
        for (int j = 0; j < width; j++)
            printf("-");
    }
    printf("+\n");

    // Print time markers
    printf("%d", chart->entries[0].startTime);

    for (int i = 0; i < chart->count; i++) {
        int width = (chart->entries[i].endTime -
                     chart->entries[i].startTime) * 2;

        if (width < 4)
            width = 4;

        printf("%*d", width + 1,
               chart->entries[i].endTime);
    }

    printf("\n\n");
}
int main(){

return 0;
}