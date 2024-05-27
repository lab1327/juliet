#include<stdio.h>
#include<stdlib.h>

void nextfit(int blocksize[], int m , int processize[], int n)
{
    int i , j , allocation[n];
    for(i=0;i<n;i++)
    {
        allocation[i]=-1;
    }

    j=0;

    for(i=0;i<n;i++)
    {
        int count=0;
        while(count<m)
        {
            if(blocksize[j]>=processize[i])
            {
                allocation[i]=j;
                blocksize[j]-=processize[i];
                break;
            }
            j=(j+1)%m;
            count+=1;
        }
    }

    printf("Table Shwoing Allocation");
    for(i=0;i<n;i++)
    {
        if(allocation[i]!=-1)
        {
            printf("\n%d--->%d",i+1,allocation[i]+1);
        }
        else
        {
            printf("\n%d---> Not Allocated",i+1);
        }
    }
}

int main()
{
    int m;
    int n;
    int blocksize[]={100,500,200,300,600};
    int processize[]={212,417,112,426};
    m=sizeof(blocksize)/sizeof(blocksize[0]);
    n=sizeof(processize)/sizeof(processize[0]);

    nextfit(blocksize, m , processize , n);

    return 0;

}


