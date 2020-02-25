#include "assignment_2.h"
#include <stdio.h>

int main()
{
    int len;
    int *arr;
    printf("enter size\n");
    scanf("%d", &len);
    printf("enter elements\n");
    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
    find_second_greatest(arr, len);
}