#include <stdio.h>
#include <limits.h>

struct Process {
    int arrivalTime;
    int burstTime;
    int startTime[20];
    int waitTime;
    int finishTime;
    int turnAroundTime;
    int position;
};

int main() {
    int numberOfProcesses, i;

    printf("Enter the number of processes: ");
    scanf("%d", &numberOfProcesses);
    struct Process processes[numberOfProcesses];

    printf("Enter the process numbers: \n");
    for (i = 0; i < numberOfProcesses; i++)
        scanf("%d", &(processes[i].position));

    printf("Enter the arrival time of processes: \n");
    for (i = 0; i < numberOfProcesses; i++)
        scanf("%d", &(processes[i].arrivalTime));

    printf("Enter the burst time of processes: \n");
    for (i = 0; i < numberOfProcesses; i++) 
        scanf("%d", &(processes[i].burstTime));
       

    float currentTime = 0;
    int totalWaitTime = 0, totalTurnAroundTime = 0;

    for (i = 0; i < numberOfProcesses; i++) {
        if (currentTime < processes[i].arrivalTime)
            currentTime = processes[i].arrivalTime;
        
        processes[i].startTime[0] = currentTime;
        
        currentTime += processes[i].burstTime;
        processes[i].finishTime = currentTime;
        processes[i].turnAroundTime = processes[i].finishTime - processes[i].arrivalTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
        processes[i].waitTime = processes[i].turnAroundTime - processes[i].burstTime;
        totalWaitTime += processes[i].waitTime;
    }

    printf("Process number ");
    printf("Arrival time ");
    printf("Burst time ");
   
    printf("\tFinal time");
    printf("\tTurnAround Time ");
    printf("\tWait Time \n");

    for(i = 0; i < numberOfProcesses; i++) {
        printf("%d \t\t", processes[i].position);
        printf("%d \t\t", processes[i].arrivalTime);
        printf("%d \t\t", processes[i].burstTime); 
        printf("%d \t\t", processes[i].finishTime);
        printf("%d \t\t", processes[i].turnAroundTime);
        printf("%d \t\n", processes[i].waitTime);
    }

    double averageWaitTime, averageTurnAroundTime;
    averageWaitTime = totalWaitTime / (float)numberOfProcesses;
    averageTurnAroundTime = totalTurnAroundTime / (float)numberOfProcesses;

    printf("The average wait time is : %lf\n", averageWaitTime);
    printf("The average TurnAround time is : %lf\n", averageTurnAroundTime);

    return 0;
}
