#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data ;
    struct Node * next;
}NODE , *PNODE , **PPNODE;


void Display ( PNODE Head , PNODE Tail )
{
   if ( (*Head != NULL ) && ( *Tail != NULL))
   {
     printf("Elementys of Linked List Are  : \n");
    do
    {
        printf(" %d : " ,Head -> data);
        Head = Head -> next;
    }
    while ( Head != Tail);
    printf("\n");
   }
   else 
   {
    printf("Linked List is Empty ;; \n");
   }
}
int Count ( PNODE Head , PNODE Tail )
{
    int iCount = 0;
    if ( (*Head != NULL ) && ( *Tail != NULL))
    {
        printf("Elementys of Linked List Are  : \n");
    do
    {
        iCount ++;
        Head = Head -> next;
    }
    while ( Head != Tail);
    return iCount;
    }
    else 
    {
        return 0;
    }
}


void InsertFirst ( PPNODE Head , PPNODE Tail , int No)
{
    PNODE newn = (PNODE ) malloc (sizeof(NODE));
        newn -> data = No;
        newn -> next = NULL;
    
    if ( (*Head == NULL) && ( *Tail == NULL) )
    {
        *Head = newn;
        *Tail = newn;
        (*Tail) -> next = *Head ; 
    }
    else 
    {
        newn -> next = *Head ; 
        *Head = newn;
        (*Tail) -> next = *Head;
    }
}

void InsertLast ( PPNODE Head , PPNODE Tail , int No)
{    
    PNODE newn = (PNODE ) malloc (sizeof(NODE));
        newn -> data = No;
        newn -> next = NULL;
    
    if ( (*Head == NULL) || ( *Tail == NULL) )
    {
        *Head  = newn;
        (*Tail ) -> next = *Head ; 
    }
    else 
    {
        (*Tail) -> next = newn;
        *Tail = (*Tail) -> next;
        (*Tail) -> next = *Head;
    }
}

void DeleteFirst ( PPNODE Head , PPNODE Tail )
{
    if ( (*Head == NULL) && ( *Tail == NULL))
    {
        return ;
    }
    else if ( *Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head) -> next;
        free ( (*Tail) -> next);
        (*Tail) -> next = *Head ;
    }
}

void DeleteLast ( PPNODE Head , PPNODE Tail )
{
    if ( (*Head  == NULL ) || (*Tail == NULL))
    {
        return ;
    }
    else if ( *Head == *Tail )
    {
        free( *Tail);
        *Tail = NULL;
        *Head = NULL;
    }
    else 
    {
        PNODE temp = *Head ; 
        while ( temp -> next != *Tail  )
        {
            temp = temp -> next;
        }
        free( temp -> next);
        *Tail = temp;
        (*Tail) -> next = *Head;
        
    }
}

int main()
{
    PNODE First = NULL;
    PNODE Last = NULL;
    Display ( First , Last)

    return 0;
}