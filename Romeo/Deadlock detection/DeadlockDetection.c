#include<stdio.h>
#include<stdbool.h>

static int mark[20];
int i, j, np, nr;

int main()
{
    int alloc[10][10], request[10][10], avail[10], r[10], w[10];
    bool executed[20] = {false}; // Array to track whether each process has been executed
    
    printf("\nEnter the number of processes: ");
    scanf("%d", &np);
    printf("\nEnter the number of resources: ");
    scanf("%d", &nr);
    for (i = 0; i < nr; i++)
    {
        printf("\nEnter the total amount of Resource R%d: ", i + 1);
        scanf("%d", &r[i]);
    }
    printf("\nEnter the request matrix:\n");
    for (i = 0; i < np; i++)
        for (j = 0; j < nr; j++)
            scanf("%d", &request[i][j]);

    printf("\nEnter the allocation matrix:\n");
    for (i = 0; i < np; i++)
        for (j = 0; j < nr; j++)
            scanf("%d", &alloc[i][j]);

    for (j = 0; j < nr; j++)
    {
        avail[j] = r[j];
        for (i = 0; i < np; i++)
        {
            avail[j] -= alloc[i][j];
        }
    }

    for (i = 0; i < np; i++)
    {
        int count = 0;
        for (j = 0; j < nr; j++)
        {
            if (alloc[i][j] == 0)
                count++;
            else
                break;
        }
        if (count == nr)
            mark[i] = 1;
    }

    for (j = 0; j < nr; j++)
        w[j] = avail[j];

    bool deadlockDetected = false;
    for (i = 0; i < np; i++)
    {
       if(mark[i] != 1 && !executed[i]) // Check if the process has not been executed yet
        {
            bool canBeProcessed = true;
            for (j = 0; j < nr; j++)
            {
                if (request[i][j] > w[j])
                {
                    canBeProcessed = false;
                    break;
                }
            }
            if (canBeProcessed)
            {
                mark[i] = 1;
                executed[i] = true; // Mark the process as executed
                printf("\nProcess %d executed", i);
                for (j = 0; j < nr; j++)
                    w[j] += alloc[i][j];
            }
        }
    }

    int deadlockProcess = -1;
    for (i = 0; i < np; i++)
    {
        if (mark[i] != 1 && !executed[i]) // Check if the process has not been executed yet
        {
            deadlockProcess = i;
            deadlockDetected = true;
            break;
        }
    }

    if (deadlockDetected)
        printf("\nDeadlock detected at process %d", deadlockProcess);
    else
        printf("\nNo deadlock possible");

    return 0;
}

/*Enter the no of process: 4
Enter the no of resources: 5

Total Amount of the Resource R1: 2
Total Amount of the Resource R2: 1
Total Amount of the Resource R3: 1
Total Amount of the Resource R4: 2
Total Amount of the Resource R5: 1

Enter the request matrix:0 1 0 0 1
0 0 1 0 1
0 0 0 0 1
1 0 1 0 1

Enter the allocation matrix:1 0 1 1 0
1 1 0 0 0
0 0 0 1 0
0 0 0 0 0

 Deadlock detected*/
