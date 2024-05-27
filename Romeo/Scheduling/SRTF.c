
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct P {
    int AT, orig_BT,BT, ST[20], WT, FT, TAT, pos;
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
    for (i = 0; i < n; i++){
        scanf("%d", &(p[i].BT));
        p[i].orig_BT=p[i].BT;
    }

    int c = n;
    float time = 0;
    int tot_wt = 0, tot_tat = 0;

    while (c != 0) {
        int min_bt = INT_MAX;
        int index = -1;
        bool flag = false;

        for (i = 0; i < n; i++) {
            if (p[i].AT <= time && p[i].BT > 0 && p[i].BT < min_bt) {
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
            p[index].WT = p[index].TAT - p[index].orig_BT;
            tot_wt += p[index].WT;
            tot_tat += p[index].TAT;
        }

        time++;
    }

    printf("Process number ");
printf("Arrival time ");
printf("Burst time ");

printf("\tFinal time");
printf("\tTurnAround Time ");
printf("\tWait Time \n");


for(i=0;i<n;i++){
printf("%d \t\t",p[i].pos);
printf("%d \t\t",p[i].AT);
printf("%d \t",p[i].orig_BT);

printf("%d \t\t",p[i].FT);
printf("%d \t\t\t",p[i].TAT);
printf("%d \t\n",p[i].WT);

}

//Calculating average wait time and turnaround time
double avg_wt,avg_tat;
avg_wt=tot_wt/(float)n;
avg_tat=tot_tat/(float)n;

//Printing average wait time and turnaround time
printf("The average wait time is : %lf\n",avg_wt);
printf("The average TurnAround time is : %lf\n",avg_tat);

    return 0;
}