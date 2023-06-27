#include<stdio.h>
#include<stdlib.h>


struct Node 
{
    int data ;
    struct Node * next;
};
typedef struct Node  NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;


void InsertFirst ( PPNODE Head , int No)
{
    PNODE newn  = (PNODE) malloc ( sizeof (NODE));
        newn -> data = No;
        newn -> next = NULL;
    
    if ( *Head == NULL)
    {
        *Head = newn ;
    }
    else
    {
        newn -> next = *Head ;
        *Head = newn ;
    }
}

void InsertLast ( PPNODE Head , int No)
{
    PNODE newn  =  (PNODE) malloc (sizeof ( NODE));
        newn -> data = No;
        newn ->  next = NULL;
    if ( *Head == NULL)
    {
        *Head = newn ;
    }
    else
    {
        PNODE temp = *Head;
        while ( temp -> next != NULL)
        {
            temp = temp -> next;
        }    
        temp -> next = newn;
    }
}

void DeleteFirst ( PPNODE Head )
{
    if ( *Head == NULL)
    {
        return ;
    }
    else if ( (*Head) -> next == NULL)
    {
        free ( *Head);
        *Head = NULL;
    }
    else 
    {
        PNODE temp = *Head;
        *Head = (*Head) -> next;
        free(temp);
    }
}

void DeleteLast ( PPNODE Head )
{
    if ( *Head == NULL)
    {
        return;
    }
    else if  ( (*Head) -> next == NULL)
    {
        free ( *Head );
        *Head = NULL;
    }
    else 
    {
        PNODE temp = *Head;
        while ( temp -> next -> next != NULL )
        {
            temp = temp -> next;
        }
        free ( temp -> next);
        temp -> next = NULL;
    }
}

int  Display ( PNODE Head )
{
    int iCount = 0;
    printf ( "Elemenys of Linked List  are : \n "  );
    while ( Head  != NULL)
    {
        printf(" %d : " , Head -> data);
        Head = Head -> next;
        iCount ++;
    }
    printf("\n Count is : : %d \n" ,iCount);
    return iCount;
}

void InsertAtPos ( PPNODE Head , int No , int iPos)
{
    int iLength = Display ( *Head );
        if (( iPos < 1) || ( iPos > iLength + 1) )
        {
            return ;
        }
    if ( iPos == 1)
    {
        InsertFirst ( Head, No);
    }
    else if ( iPos == iLength + 1)
    {
        InsertLast ( Head , No);
    }
    else 
    {
        PNODE temp = *Head;
        PNODE newn =  (PNODE) malloc ( sizeof ( NODE));
            newn -> next = NULL;
            newn -> data = No;

        for ( int iCnt = 1; iCnt < iPos -1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn ;
    }

}

int main ()
{
    PNODE First = NULL;

    return 0;
}
