#include<stdio.h>
#include<stdlib.h>


void firstfit(int blocksize[], int m , int processize[],int n)
{
    int i , j;
    int allocation[n];
    for(i=0;i<n;i++)
    {
        allocation[i]=-1;
    }    

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(blocksize[j]>=processize[i])
            {
                allocation[i]=j;
                blocksize[j]=blocksize[j]-processize[i];
                break;
            }
        }
    }

    printf("\ntable Showing process allocation ");
    for(i=0;i<n;i++)
    {
        if(allocation[i]!=-1)
        {
            printf("\n%d--->%d",i+1,allocation[i]+1);
        }
        else
        {
            printf("\n%d---> Not allocated",i+1);
        }
    }

}
int main()
{
    int m , n ;
    int blocksize[]={100,500,200,300,600};
    int processize[]={212,417,112,426};
    m=sizeof(blocksize)/sizeof(blocksize[0]);
    n=sizeof(processize)/sizeof(processize[0]);

    firstfit(blocksize, m,processize,n);

    return 0;
}

