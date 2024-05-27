
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct P {
    int AT, BT, original_BT, ST[20], WT, FT, TAT, pos;
};

int main() {
    int n, i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct P p[n];

    printf("Enter the process numbers: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &(p[i].pos));

    printf("Enter the Arrival time of processes: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &(p[i].AT));

    printf("Enter the Burst time of processes: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &(p[i].BT));
        p[i].original_BT = p[i].BT; // Store original burst time
    }

    int c = n;
    float time = 0;
    int tot_wt = 0, tot_tat = 0;

    // Sorting processes based on arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].AT > p[j + 1].AT) {
                struct P temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int processed[n]; // Track if process is processed or not

    // Initialize processed array to 0
    for (i = 0; i < n; i++)
        processed[i] = 0;

    while (c != 0) {
        int min_bt = INT_MAX;
        int index = -1;
        bool flag = false;

        for (i = 0; i < n; i++) {
            if (p[i].AT <= time && p[i].BT > 0 && p[i].BT < min_bt && !processed[i]) {
                index = i;
                min_bt = p[i].BT;
                flag = true;
            }
        }

        if (!flag) {
            time++;
            continue;
        }

        p[index].BT--;

        if (p[index].BT == 0) {
            c--;
            p[index].FT = time + 1;
            p[index].TAT = p[index].FT - p[index].AT;
            p[index].WT = p[index].TAT - p[index].original_BT; // Using original burst time for wait time calculation
            tot_wt += p[index].WT;
            tot_tat += p[index].TAT;
            processed[index] = 1; // Mark process as processed
        }

        time++;
    }

    printf("Process number ");
    printf("Arrival time ");
    printf(" Burst time "); // Add this line for original burst time
    printf("\tFinal time");
    printf("\tTurnAround Time ");
    printf("\tWait Time \n");

    for(i = 0; i < n; i++) {
        printf("%d \t\t", p[i].pos);
        printf("%d \t\t", p[i].AT);
        printf("%d \t\t", p[i].original_BT); // Print original burst time
        printf("%d \t\t\t", p[i].FT);
        printf("%d \t\t\t", p[i].TAT);
        printf("%d \t\n", p[i].WT);
    }

    // Calculating average wait time and turnaround time
    double avg_wt, avg_tat;
    avg_wt = tot_wt / (float)n;
    avg_tat = tot_tat / (float)n;

    // Printing average wait time and turnaround time
    printf("The average wait time is : %lf\n", avg_wt);
    printf("The average TurnAround time is : %lf\n", avg_tat);

    return 0;
}