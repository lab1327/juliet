#include<stdio.h>

void fifo(int string[], int n , int size)
{
    int frame_block[n];

    for(int i=0;i<n;i++)
    {
        frame_block[i]=-1;
    }

    int index=-1;

    //counters;

    int page_hit=0;
    int page_miss=0;

    //iterate

    for(int i=0;i<size;i++)
    {
        int symbol=string[i];
        int flag=0;
        for(int j=0;j<n;j++)
        {
            if(symbol==frame_block[j])
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            printf("\nSymbol: %d , Frame_Block: ",string[i]);
            for(int i=0;i<n;i++)
            {
                printf("%d\t",frame_block[i]);
            }
            page_hit++;
        }
        else
        {
            index=(index+1)%n;
            frame_block[index]=symbol;
            page_miss++;
            printf("\nSymbol: %d , Frame_Block: ",string[i]);
            for(int i=0;i<n;i++)
            {
                printf("%d\t",frame_block[i]);
            }

        }
    }

    printf("\nTotal Page hit : %d",page_hit);
    printf("\nTotal Page miss : %d",page_miss);
}

int main()
{
    int ref_string[]={7,0,1,2,0,3,0,4,2,3,0,3,1,2,0};
    int frame_size = 3;
    int size = sizeof(ref_string)/sizeof(ref_string[0]);

    fifo(ref_string,frame_size,size);
}