#include<stdio.h>

void findswappedelements(int arr[],int size)
{
    int x=-1;
    int y=-1;
    int index1=-1;
    int index2=-1;

    for(int i=0;i<size-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            if(x==-1)
            {
                x=arr[i];
                index1=i;
                y=arr[i+1];
                index2=i+1;
            }
            else
            {
                y=arr[i+1];
                index2=i+1;
            }
            
        }
        
    }

    if(x!=-1 && y!=-1)
    {
        printf("\nThe swapped elements are : %d %d",x,y);
        printf("\nposition: %d and %d",index1,index2);
    }
    else
    {
        printf("\nelements are not swapped");
    }
}

int main()
{
    int arr[]={10,2,3,4,5,6,7,8,9,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    findswappedelements(arr,n);
}