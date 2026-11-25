#include "scheduling.h"
void scheduleFCFS(Process processes[], int count, GanttChart *chart){
    
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