#include "assignment_2.h"
#include <stdio.h>
#include<stdlib.h>

int main()
{
    int len,a,n=0;
    int *arr;
    //printf("enter size\n");
    scanf("%d", &len);
    arr=malloc(len*sizeof(int));
    //printf("enter elements\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d %d", &arr[i],&a);
        //printf("%d\n",n++);
    }
    find_second_greatest(arr, len);
    free(arr);
}