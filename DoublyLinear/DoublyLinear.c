#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data ;
    struct Node * next;
    struct Node * prev;

}NODE , *PNODE, **PPNODE;


int Count ( PNODE Head )
{
    int iCount = 0;
    while ( Head != NULL)
    {
            iCount ++;
            Head = Head -> next;
    }
    return iCount;
}

void Display(PNODE Head)
{
    printf("Elements of Linked List is : \n");
    while (Head != NULL)
    {
        printf(" %d : ", Head -> data);
        Head = Head -> next;
    }
    printf("NULL \n ");
}

void InsertFirst ( PPNODE Head , int No)
{
    PNODE newn = (PNODE) malloc ( sizeof( NODE));
        newn -> data = No;
        newn -> prev= NULL;
        newn -> next = NULL;
    if ( *Head == NULL)
    {
        *Head = newn;
    }
    else 
    {
        newn -> next = *Head ; 
        (*Head )-> prev = newn;
        *Head = newn;
    }
}

void InsertLast ( PPNODE Head , int No)
{
    PNODE newn = (PNODE) malloc ( sizeof ( NODE));
        newn -> data = No;
        newn -> prev = NULL;
        newn -> next = NULL;
    if ( *Head == NULL)
    {
        *Head = newn;
    }
    else 
    {
        PNODE temp = *Head; 
        while ( temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn ;
        newn -> prev = temp;
    }
}

void InsertAtPos ( PPNODE Head , int No , int iPos)
{
    int iLength = 0;
        iLength = Count ( *Head );
        if ( (iPos <  0) || ( iPos > iPos + iLength) )
        {
            printf("Invalid Position !!! \n");
            return ;
        }
    if ( iPos == 1)
    {
        InsertFirst ( Head ,No);
    }
    else if ( iPos == iLength +  1)
    {
        InsertLast ( Head , No );
    }
    else 
    {
        PNODE newn = (PNODE)malloc  (sizeof ( NODE));
            newn -> prev = NULL;
            newn -> next = NULL;
            newn -> data = No;

        PNODE temp = *Head ; 
            for ( int iCnt = 1 ; iCnt < iPos - 1  ; iCnt ++)
            {
                temp = temp -> next;
            }
        newn -> next = temp -> next ;
        temp -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;
    }
}

int main()
{
    PNODE First = NULL;

    return 0;
}