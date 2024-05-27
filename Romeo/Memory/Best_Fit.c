#include<stdio.h>
#include<stdlib.h>

void bestfit(int blocksize[], int mem , int processize[], int n)
{
    int i , j , allocation[n], occupied[mem];
    for(i=0;i<n;i++)
    {
        allocation[i]=-1;
    }

    for(i=0;i<mem;i++)
    {
        occupied[i]=0;
    }

    for(i=0;i<n;i++)
    {
        int indexplaced=-1;
        for(j=0;j<mem;j++)
        {
            if(blocksize[j]>=processize[i] && !occupied[j])
            {
                if(indexplaced==-1)
                {
                    indexplaced=j;
                }
                else if(blocksize[j]<blocksize[indexplaced])
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

    printf("\nTable Showing memory allocation");
    printf("\n");

    for(i=0;i<n;i++)
    {
        if(allocation[i]!=-1)
        {
            printf("\n%d--->%d",i+1,allocation[i]+1);
        }
        else{
            printf("\n%d--->Not allocatde",i+1);
        }
    }

    

}

int main()
{
    int mem; 
    int n;
    int blocksize[]={100,500,200,300,600};
    int processize[]={212,417,112,426};

    mem =sizeof(blocksize)/sizeof(blocksize[0]);
    n=sizeof(processize)/sizeof(processize[0]);

    bestfit(blocksize , mem , processize , n);

    return 0;
}
