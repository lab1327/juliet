#include<stdio.h>
#include<stdlib.h>

int main()
{
    int queue[20], n , head, i ,j , seek , max , diff;

    float avg;

    seek=0;

    printf("\nEnter Maximum range of disk: ");
    scanf("%d",&max);

    printf("\nEnter size of request queue: ");
    scanf("%d",&n);

    printf("\nEnter Each request:\n ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&queue[i]);
    }


    printf("\nEnter current position of head: ");
    scanf("%d",&head);

    queue[0]=head;

    for(j=0;j<=n-1;j++)
    {
        diff=abs(queue[j+1]-queue[j]);
        seek+=diff;
        printf("\nDisk head moves from %d to %d with seek : %d",queue[j],queue[j+1],diff);
    }

    printf("\nTotal seek Time: %d",seek);
    avg=seek/(float)n;

    printf("\nAverage seek time is %f\n",avg);
    return 0;

}
//MAX RANGE : 199 
//request queue: 82 , 170 , 43 , 140 , 24 , 16 , 190
//