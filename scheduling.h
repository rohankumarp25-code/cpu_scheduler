#ifndef SCHEDULING_H
#define SCHEDULING_H

#include "process.h"

#define MAX_GANTT_ENTRIES 1000

typedef struct {
    int processID;
    int startTime;
    int endTime;
} GanttEntry;

typedef struct {
    GanttEntry entries[MAX_GANTT_ENTRIES];
    int count;
} GanttChart;

/* Scheduling algorithms */

void scheduleFCFS(Process processes[], int count, GanttChart *chart);

void scheduleSJF(Process processes[], int count, GanttChart *chart);

void schedulePriority(Process processes[], int count, GanttChart *chart);

void scheduleRoundRobin(Process processes[], int count,
                        int quantum, GanttChart *chart);

/* Scheduling utilities */

void resetSchedulingData(Process processes[], int count);

void calculateMetrics(Process processes[], int count);

void calculateAverages(Process processes[], int count,
                       double *avgWaitingTime,
                       double *avgTurnaroundTime,
                       double *avgResponseTime);

void displayGanttChart(GanttChart *chart);

void compareAlgorithms(Process processes[], int count, int quantum);

#endif
