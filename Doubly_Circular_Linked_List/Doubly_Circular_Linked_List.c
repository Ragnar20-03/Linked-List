#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    struct Node * prev ;
    int data ;
    struct Node * next ;
}NODE , *PNODE , **PPNODE;

void InsertFirst ( PPNODE Head , PPNODE Tail , int No)
{
    PNODE newn = (PNODE) malloc (sizeof ( NODE));
        newn -> next = NULL;
        newn -> prev = NULL;
        newn -> data = No;
    
    if ( (*Head == NULL ) && ( *Tail == NULL))
    {
         newn -> next = *Head ;
         (*Head )-> prev = newn ; 
          *Head = newn ;

        (*Head) -> prev = *Tail;
        (*Tail ) -> next = *Head;
    }
}

void InsertLast ( PPNODE Head  , PPNODE Tail , int No)
{
    PNODE newn = ( PNODE ) malloc ( sizeof (NODE));
            newn -> prev = NULL;
            newn -> data = No;
            newn -> next = NULL;

    if ( (*Head == NULL  )&&  ( *Tail == NULL))
    {
        *Head = newn ;
        *Tail = newn ;

        (*Head ) -> prev = *Tail;
        (*Tail ) -> next = *Head;
    }
    else 
    {
        (*Tail) -> next = newn;
        newn -> prev = *Tail;

        *Tail = (*Tail ) -> next;

       (*Tail ) -> next = *Head;
        (*Head) -> prev = *Tail;
    }
}

int main()
{


    return 0;
}