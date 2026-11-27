#include "scheduling.h"
#include "string.h"
void scheduleFCFS(Process processes[], int count, GanttChart *chart){
    
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