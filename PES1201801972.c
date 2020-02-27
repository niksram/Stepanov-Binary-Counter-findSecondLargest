#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "assignment_2.h"
int comper;

typedef struct Node
{
    int val;
    struct Node *link;
} Node;

typedef struct Deck
{
    Node *head;
} Deck;

typedef struct Hanger //this structure holds the entire skewed multiarray
{
    int stretch; //stretch describes the length of the multiarray heads.
    Deck *deck;int comper;
} Hanger;

void compete(Hanger *, Node *, int);
void find_second_greatest(int *, int);
Hanger *hanger_init(int);
int logceil(int);
Node *create_node(int);
void freelist(Node *);
void print_list(Node *);

void find_second_greatest(int *numbers, int length)
{
    comper=0;
    if(length==1)
    {
        printf("only one element exists\n");
        return;
    }
    Hanger *hanger = hanger_init(length);
    for (int i = 0; i < length; i++)
    {
        Node *node = create_node(numbers[i]);
        compete(hanger, node, 0);
    }
    for (int final = 0; final < hanger->stretch - 1; final++)
        if(hanger->deck[final].head)
            compete(hanger, hanger->deck[final].head, final + 1);

    Node *temp = hanger->deck[hanger->stretch - 1].head->link;
    int slar = temp->val;
    while (temp->link)
    {
        temp = temp->link;
        if (++comper && slar < temp->val)
            slar = temp->val;
    }
    printf("\n%d\n", slar);
    printf("\n%d\n", comper);
}

void compete(Hanger *hanger, Node *pass, int level)
{
    if (!hanger->deck[level].head)
    {
        hanger->deck[level].head = pass;
    }
    else
    {
        Node *win = hanger->deck[level].head;
        Node *lose = pass;
        print_list(win);
        printf("X ");
        print_list(lose);
        if (++comper && win->val < lose->val)
        {
            lose = win;
            win = pass;
        }
        freelist(lose);
        lose->link = win->link;
        win->link = lose;
        hanger->deck[level].head = NULL;
        printf("= ");
        print_list(win);
        printf("\n");
        compete(hanger, win, level + 1);
    }
}

Hanger *hanger_init(int length)
{
    Hanger *hanger = (Hanger *)malloc(sizeof(Hanger));
    hanger->stretch = logceil(length);
    hanger->deck = (Deck *)malloc(hanger->stretch * sizeof(Deck));
    for (int i = 0; i < hanger->stretch; i++)
    {
        hanger->deck[i].head = NULL;
    }
    return hanger;
}

Node *create_node(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->link = NULL;
    node->val = val;
    return node;
}

void freelist(Node *node)
{
    if (node->link)
    {
        freelist(node->link);
        free(node->link);
        node->link = NULL;
    }
}

void print_list(Node *node)
{
    if (node)
    {
        printf("%d ", node->val);
        print_list(node->link);
    }
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