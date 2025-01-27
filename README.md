DATA STRUCTURES USED:-

    Hanger:-
    Its the data-type which contains the entire frame for storing the skewed adjacency-list.
    It consists of an integer 'stretch' which stores the size of the list of 'deck's.
    The pointer 'deck' consists of an array of decks which is of length ceil(log(n)), where n is the numer of elements fed in.

    Deck:-
    The pointer array of the adjacency list in the 'Hanger' frame is nothing but an array of 'Deck' type.
    It has a pointer 'head' of type 'Node*' which shall point to the head node of the linked list stored at a particular 'level'
    (level:- naming 'level' is used to indicate the index in the 'deck' array)

    Node:-
    The data-type Node is nothing but the fundamental element of a linked list.
    It consists of an integer variable 'val' which stores the value in the node.
    The 'Node*' pointer 'link' points to the next Node of the list and point to NULL if its the end element.

    Functioning---
    once an element is read, a 'node' is created for the respective element and fed into the 'Hanger' through the recursive function 'compete'.
    the node shall occupy the deck at level 0 if its NULL or shall fight with the list there and proceed to the next level recursively.
    In n=powers of 2, the resultant Hanger shall only contain a final linked list at the last_level= hanger->stretch-1 th deck.
    else when n is not power of 2, the residual non-empty decks are cascaded onto each other.

KEY TAKEAWAY:-

    The following simulation helps us to understand how a tournament is conducted and how the winners and losers are arranged accordingly.
    The following implementation can be tweaked with the merge-function to simulate Merge-Sort.
    the number of comparisons in the given alorithm is around n+log(n) which is less than 2*(n-1) in the Brute-Force method of finding second largest element. 
