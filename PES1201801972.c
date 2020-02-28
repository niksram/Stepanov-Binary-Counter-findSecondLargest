#include <stdio.h>
#include <stdlib.h>
#include "assignment_2.h"

typedef struct Node // structure Node is the node of the linked list used in the implemented framework
{
    int val;
    struct Node *link;
} Node;

typedef struct Deck // structure Deck acts as the start of a linked list by pointing to the head node. 
{                   // Array of "Deck" type results in an adjacency list.
    Node *head;
} Deck;

typedef struct Hanger   //This frame-work holds the entire adjacency list. 
{                       //It behaves like a "Hanger" where all numbers are hanging in some pattern from their respective Decks.
    int stretch;        //stretch describes the length of the array of Decks.
    Deck *deck;
} Hanger;

void compete(Hanger *, Node *, int);    // primary function which involves in moving elements till the last deck based on competition.
void find_second_greatest(int *, int);  
Hanger *hanger_init(int);   // initialises the Hanger frame.
int logceil(int);   // finds ceil of log value
Node *create_node(int); // creates node with the given integer value
void freelist(Node *); // free all the nodes after the entered node in the given list.
void print_list(Node *);    // prints the elements of a list sequentially.

void find_second_greatest(int *numbers, int length)
{
    if(length==1)   // there exists no second larget element when there exists only 1 element
    {
        printf("only one element exists\n");
        return;
    }
    
    Hanger *hanger = hanger_init(length);
    for (int i = 0; i < length; i++)
    {
        Node *node = create_node(numbers[i]);   // a node is created for every element.
        compete(hanger, node, 0);   // the above node is fed into the Hanger Frame through "compete" function.
    }
    for (int final = 0; final < hanger->stretch - 1; final++)   // this for loop calls the 'compete' functions which- 
        if(hanger->deck[final].head)                            //-cascades down all the 'decks' which are remaining-
            compete(hanger, hanger->deck[final].head, final + 1);   //-till the last deck. -> when length is not a power of 2

    Node *temp = hanger->deck[hanger->stretch - 1].head->link; // temp points to the last deck in the hanger.
    int slar = temp->val;
    while (temp->link)  // the last Deck is traversed linearly from the second element to find the second largest element.
    {
        temp = temp->link;
        if (slar < temp->val)
            slar = temp->val;
    }
    printf("\n%d\n", slar);
}

void compete(Hanger *hanger, Node *pass, int level) // Hanger frame is passed, pass points to the list which shall compete with the list at - 
{                                                   //- a particular level. here level refers to the Deck index.
    if (!hanger->deck[level].head)  // if the given location is vacant. the 'pass' list occupies that particular level. (BASE CASE)
    {
        hanger->deck[level].head = pass;
    }
    else
    {
        Node *win = hanger->deck[level].head;   // winner and loser among 'pass' list and the list at a particular level is found.
        Node *lose = pass;
        print_list(win);
        printf("X ");
        print_list(lose);
        if (win->val < lose->val)
        {
            lose = win;
            win = pass;
        }
        freelist(lose); // in the losers list, the elements after the first node are freed.
        lose->link = win->link; // loser head is inserted into the second position in the winners list.
        win->link = lose;
        hanger->deck[level].head = NULL;    // previous level points to NULL. (pass is generally the previous livels list) 
        printf("= ");
        print_list(win);
        printf("\n");
        compete(hanger, win, level + 1);    // compete is called so that the cumulative list can fight with the next level's list.
    }
}

Hanger *hanger_init(int length)
{
    Hanger *hanger = (Hanger *)malloc(sizeof(Hanger));  // memory allocation of hanger.
    hanger->stretch = logceil(length);
    hanger->deck = (Deck *)malloc(hanger->stretch * sizeof(Deck));  // memory allocation for the Deck's
    for (int i = 0; i < hanger->stretch; i++)
    {
        hanger->deck[i].head = NULL; // Deck heads initially shall point to NULL
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