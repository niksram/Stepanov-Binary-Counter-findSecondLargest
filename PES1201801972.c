#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "assignment_2.h"

typedef struct Node
{
    int val;
    Node *link;
}

typedef struct Deck
{
    Node *head;
} Deck;

typedef struct Hanger //this structure holds the entire skewed multiarray
{
    int stretch; //stretch describes the length of the multiarray heads.
    Deck *deck;
} Hanger;

void compete(Hanger *hanger, int *ele, int *temp, int level);
void find_second_greatest(int *, int);
Hanger *hanger_init(int);
int logceil(int);
Node *create_node(int);

int main()
{
    printf("%d\n", loger(8));
    int a[8] = {20, 5, 15, 25, 10, 80, 60, 50};
    find_second_greatest(a, 8);
}

void find_second_greatest(int *numbers, int length)
{
    Hanger *hanger = hanger_init(length);
    for (int i = 0; i < length; i++)
    {
        compete(hanger, numbers + i, temp, 0);
    }
}

void compete(Hanger *hanger, int *ele, int *temp, int level)
{
    if (!hanger->deck[level].container && level < hanger->stretch)
    {
        hanger->deck[level].container = 1;
        for (int i = 0; i <= level; i++)
        {
            hanger->deck[level].chart[i] = ele[i];
        }
    }
    else
    {
        hanger->deck[level].container = 0;
        for (int i = 0; i <= level; i++)
        {
            printf("%d ", ele[i]);
        }
        printf("X ");
        for (int i = 0; i <= level; i++)
        {
            printf("%d ", hanger->deck[level].chart[i]);
        }
        printf(" = ");
        int i = 0, j = 0, pos = 0;
        while (i <= level && j <= level)
        {
            if (ele[i] > hanger->deck[level].chart[j])
                temp[pos++] = ele[i++];
            else
                temp[pos++] = hanger->deck[level].chart[j++];
        }
        while (i <= level)
            temp[pos++] = ele[i++];
        while (j <= level)
            temp[pos++] = hanger->deck[level].chart[j++];
        for (int i = 0; i < pos; i++)
        {
            hanger->deck[level].chart[i] = temp[i];
        }
        for (int i = 0; i <= level + 1; i++)
        {
            printf("%d ", temp[i]);
        }
        printf("\n");
        compete(hanger, hanger->deck[level].chart, temp, level + 1);
    }
}

Hanger *hanger_init(int length)
{
    Hanger *hanger = (Hanger *)malloc(sizeof(Hanger));
    hanger->stretch = logceil(length);
    hanger->deck = (Deck *)malloc(hanger->stretch * sizeof(Deck));
    for (int i = 0; i < hanger->stretch; i++)
    {
        hanger->deck[i].list = NULL;
    }
    return hanger;
}

Node *create_node(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->link = NULL;
    node->val = val;
}

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