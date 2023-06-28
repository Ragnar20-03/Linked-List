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
        while ( Head != NULL)
        {
            printf(" %d : " , Head -> data );
            Head =  Head -> next;
        }
        printf("\n");
}

int Count (PNODE Head)
{
    int iCount  = 0 ;
    while ( Head != NULL)
    {
        Head = Head -> next ; 
        iCount ++;
    }
    return iCount;
}

void DeleteAtPos ( PPNODE Head , int iPos)
{
    int iLength = Count ( *Head );
        if (( iPos < 0 ) || ( iPos > iLength) )
        {
            printf("INVALID Position ... \n");
            return ;
        }
    
    if ( iPos == 1)
    {
        DeleteFirst ( Head);
    }
    else if ( iPos == iLength)
    {
        DeleteLast ( Head);
    }
    else 
    {
        PNODE temp = *Head;
        for ( int iCnt = 1; iCnt < iPos -1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        temp = temp -> next -> next;
        free ( temp -> next -> prev);temp -> next -> prev
        temp -> next -> prev = temp;
    }
}

void InsertAtPos ( PPNODE Head , int iPos , int No)
{
    int iLength = Count ( *Head );
}

int main()
{   
    PNODE First = NULL;

    return 0;
}

