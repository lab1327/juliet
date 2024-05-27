
#include<math.h>
#include<Stdio.h>

void main()
{
    int queue[25],queue1[25], queue2[25];
    int temp , temp1=0 , temp2=0 , seek=0;
    int i ,j, k , n , head, max , diff;
    float avg;


    printf("Enter Max range of disk:\n");
    scanf("%d",&max);

    printf("Enter initial head position:\n");
    scanf("%d",&head);

    printf("Enter no of requests:\n") ;
    scanf("%d",&n);

    printf("Enter requests in order: \n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        if(temp>head)
        {
            queue1[temp1]=temp;
            temp1++;
        }
        else
        {
            queue2[temp2]=temp;
            temp2++;
        }
    }

    for(i=0;i<temp1-1;i++)
    {
        for(j=i+1;j<temp1;j++)
        {
            if(queue1[i]>queue1[j])
            {
                temp=queue1[i];
                queue1[i]=queue1[j];
                queue1[j]=temp;
            }
        }
    }

    for(i=0;i<temp2-1;i++)
    {
        for(j=i+1;j<temp2;j++)
        {
            if(queue2[i]<queue2[j])
            {
                temp=queue2[i];
                queue2[i]=queue2[j];
                queue2[j]=temp;
            }
        }
    }

    for(i=1,j=0;j<temp1;i++,j++)
    {
        queue[i]=queue1[j];
    }

    queue[i]=max;

    for(i=temp1+2,j=0;j<temp2;i++,j++)
    {
        queue[i]=queue2[j];
    }

    queue[i]=0;
    queue[0]=head;

    int length = sizeof(queue)/sizeof(queue[0]);

    printf("The sequence in which disk access has done is: \n");
    for(i=0;i<temp1+temp2+2;i++)
    {
        printf("%d--->",queue[i]);
    }

    for(i=0;i<temp1+temp2+2-1;i++)
    {
        diff=abs(queue[i+1]-queue[i]);
        seek+=diff;
    }

    printf("\nTotal disk Movement is: %d",seek);
}

//MAX RANGE : 199 
//request queue: 82 , 170 , 43 , 140 , 24 , 16 , 190
//