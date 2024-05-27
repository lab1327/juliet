#include<stdio.h>
#include<stdlib.h>

void worstfit(int blocksize[], int m , int processize[] ,int n)
{
    int i , j , allocation[n], occupied[m];

    for(i=0;i<n;i++)
    {
        allocation[i]=-1;
    }

    for(i=0;i<m;i++)
    {
        occupied[i]=0;
    }

    for(i=0;i<n;i++)
    {
        int indexplaced=-1;
        for(j=0;j<m;j++)
        {
            if(blocksize[j]>=processize[i]&& !occupied[j])
            {
                if(indexplaced==-1)
                {
                    indexplaced=j;
                }
                else if(blocksize[indexplaced]<blocksize[j])
                {
                    indexplaced=j;
                }
            }
        }
        if(indexplaced!=-1)
        {
            allocation[i]=indexplaced;
            occupied[indexplaced]=1;
        }
    }

    printf("\n Table showing memory allocation");
    for(i=0;i<n;i++)
    {
        if(allocation[i]!=-1)
        {
            printf("\n%d--->%d",i+1,allocation[i]+1);
        }
        else
        {
            printf("\n%d--->Not allocated",i+1);
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

    worstfit(blocksize, m, processize, n);
    return 0;
}
