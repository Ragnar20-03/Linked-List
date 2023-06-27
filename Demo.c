#include<stdio.h>
#include<stdlib.h>


struct Node 
{
    struct Node * prev ; 
        int data ;
    struct Node * next ;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;


void InsertFirst ( PPNODE Head , PPNODE Tail , int No)
{
    PNODE newn =  (PNODE)  malloc ( sizeof ( NODE));
        newn -> prev = NULL;
        newn -> data = No;
        newn -. next = NULL;
    
    if ( *Head == NULL)
    {
        *Head = newn ; 
        *Tail = newn ;
    }
    else 
    {
        newn -> next = *Head ; 
        *Head -> prev = newn;
        *Head = newn;
    }
    (*Tail) -> next = *Head;
    (*Head) -> prev = *Tail;
}

void InsertLast ( PPNODE Head , PPNODE Tail , int No)
{
    PNODE newn  = (PNODE) malloc (sizeof (NODE));
        newn -> next = NULL;
        newn -> prev = NULL;
        newn -> data = No;
    if ( (*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn ;
        *Tail = newn ;
    }
}

int main()
{
    PNODE First = NULL;
    PNODE Last  = NULL;

    return 0;
}