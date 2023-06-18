#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data ;
    struct Node * next ;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertFirst ( PPNODE Head , int No)
{
    PNODE newn = (PNODE)malloc ( sizeof(NODE));
        newn -> next = NULL;
        newn -> data = No;
    
    if ( *Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> next = *Head ;
        *Head = newn;
    }
}

void DeleteFirst ( PPNODE Head )
{   
    if ( *Head == NULL)
    {
        printf(" Linkde List is Empty .. \n");
        return;
    }
    else if ( (*Head )-> next == NULL)
    {
        free ( *Head );
        *Head = NULL;
    }
    else
    {
        PNODE temp = *Head ; 
        *Head = (*Head )-> next;
        free (temp);
    }
}

void DeleteLast ( PPNODE Head )
{
    if ( *Head == NULL)
    {
        printf("Linked List is Empty ..\n");
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
        free(temp -> next );
        temp -> next = NULL;
    }
}

int main()
{
    PNODE First = NULL;

    return 0;
}