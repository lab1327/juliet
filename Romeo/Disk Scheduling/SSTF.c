#include<math.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{
    int index[50] , req[50], a[50];
    int head , head1;
    int i , k , n ,low_diff_idx , low_diff ;
    int seek=0,j=0;

    printf("\nEnter initial position of head");
    scanf("%d",&head);

    head1 = head;
    printf("\nEnter no of requestes: ");
    scanf("%d",&n);

    printf("\nEnter Request order: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            index[i]=abs(req[i]-head);
        }
        low_diff=index[0];
        low_diff_idx=0;

        for(i=1;i<n;i++)
        {
            if(index[i]<low_diff)
            {
                low_diff=index[i];
                low_diff_idx=i;
            }
        }

        a[j]=req[low_diff_idx];
        head=req[low_diff_idx];
        j++;
        req[low_diff_idx]=999;
    }

    printf("\nThe sequence in which access has done: ");
    printf("\n%d--->",head1);
    for(i=0;i<n;i++)
    {
        printf("%d--->",a[i]);
    }

    printf("\nTotal Seek time: ");
    seek=seek+abs(head1-a[0]);
    for(i=1;i<n;i++)
    {
        seek=seek+abs(a[i]-a[i-1]);
    }
    printf("%d",seek);

}
//MAX RANGE : 199 
//request queue: 82 , 170 , 43 , 140 , 24 , 16 , 190
//