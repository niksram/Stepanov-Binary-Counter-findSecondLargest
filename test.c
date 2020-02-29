#include<stdio.h>
#include<stdlib.h>

int logceil(int n) 
{
    int c = 1, i = 1;
    while (i < n)
    {
        i *= 2;
        c++;
    }
    return c;
}

int main()
{
    printf("%d\n",logceil(8));
}