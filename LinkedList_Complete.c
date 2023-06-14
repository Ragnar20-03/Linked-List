#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data ;
    struct Node * next ;
}NODE , * PNODE , ** PPNODE;

void Display ( PNODE Head )
{
    printf("Elements of Linked List are : \n");

    while ( Head != NULL)
    {
        printf("%d :",Head -> data);
        Head = Head -> next;
    }
    printf("\n");
}

int Count ( PNODE Head)
{
    int iCount = 0;
    while ( Head != NULL)
    {
        iCount ++;
        Head = Head -> next;
    }
    return iCount;
}

void InsertFirst ( PPNODE Head , int No)
{
    PNODE newn = (PNODE) malloc ( sizeof(NODE));
        newn -> data = No;
        newn -> next = NULL;
    
    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> next = *Head ;
        *Head = newn;
    }
}

void InsertLast ( PPNODE Head , int No)
{
    PNODE newn = (PNODE) malloc (sizeof ( NODE));
        newn -> next = NULL;
        newn -> data = No;
    
    if ( *Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        PNODE temp = *Head;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void InsertAtPos ( PPNODE Head , int No , int iPos)
{
    int iLength = Count (*Head);

    if ( (iPos < 1 ) || ( iPos > iLength + 1))
    {
        printf("InValid Position !!! \n");
        return;
    }
    if ( iPos == 1)
    {
        InsertFirst ( Head , No);
    }
    if ( iPos == iLength + 1)
    {
         InsertLast( Head , No);
    }
    else
    {
        PNODE newn = (PNODE)malloc (sizeof(NODE));
            newn -> next = NULL;
            newn -> data = No;

        PNODE temp = *Head;

        for ( int iCnt = 1; iCnt < iPos -1 ; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
    }
}

void DeleteFirst ( PPNODE Head )
{

    if ( *Head == NULL)
    {
        printf ("LL is Empty : \n");
        return;
    }
    else if ( (*Head )-> next == NULL)
    {
        free ( *Head);
        *Head = NULL;
    }
    else
    {
        PNODE temp = *Head;
        *Head = temp -> next;
        free ( temp);
    }
}

void DeleteLast ( PPNODE Head )
{
    if ( *Head == NULL)
    {
        printf("Linked List is Empty \n");
    }
}

int main()
{
    PNODE First = NULL;
    InsertFirst( &First , 21 );
    InsertFirst( &First , 11 );

    InsertLast ( &First , 101);

    InsertAtPos ( &First , 51 , 3);

    Display ( First);

    DeleteFirst ( &First );

    Display ( First);

    return 0;
}