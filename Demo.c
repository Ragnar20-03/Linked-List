#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    struct Node * prev;
    int data ; 
    struct Node * next ;
} NODE, *PNODE , ** PPNODE;


void InsertFirst ( PPNODE Head , int No)
{
    PNODE newn =  (PNODE) malloc (sizeof ( NODE));
        newn -> prev = NULL;
        newn -> data = No;
        newn -> next= NULL;
    if ( *Head == NULL)
    {
        *Head = newn ;
    }
    else 
    {
        newn -> next = *Head;
        (*Head) -> prev = newn;
        *Head = newn;
    }
}   
void InsertLast( PPNODE Head , int No)
{
    PNODE newn = (PNODE) malloc (sizeof(NODE));
        newn -> prev = NULL;
        newn -> data = No;
        newn -> next = NULL;
    
    if ( *Head == NULL)
    {
        *Head = newn    ;
    }
    else 
    {
        PNODE temp = *Head;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn ;
        newn -> prev = temp;
    }
}

void DeleteLast ( PPNODE Head )
{
    if ( *Head == NULL)
    {
        return ;
    }
    else if ( (*Head) -> next == NULL)
    {
        free ( *Head );
        *Head = NULL;
    }
    else 
    {
        PNODE temp = *Head ; 
        while ( temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        free ( temp -> next);
        temp -> next = NULL;
    }

}

void DeleteFirst ( PPNODE Head )
{
    if ( *Head == NULL)
    {
        *Head = newn ;
    }
    else if ( (*Head) -> next == NULL )
    {
        free ( *Head );
        *Head = NULL;
    }
    else 
    {
        *Head = (*Head) -> next;
        free ( (*Head) -> prev);
        (*Head) -> prev = NULL;
    }
}

void Display ( PNODE Head )
{
    printf("Elements of Linked List are : \n ");
        
}


int main()
{   
    PNODE First = NULL;

    return 0;
}

