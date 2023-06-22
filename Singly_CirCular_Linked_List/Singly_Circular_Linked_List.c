#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{   
    int data ; 
    struct Node * next;
 } NODE , *PNODE , **PPNODE;


 void Display ( PNODE Head , PNODE Tail)
 {
    if ( (Head != NULL) && ( Tail != NULL) )
    {
            printf("Elements of Linked List Are : \n");
      do 
        {
        printf(" : %d : " , Head -> data);
        Head = Head -> next;
        }
    while ( Head != Tail -> next);
    printf("\n");
    }
    else
    {
        printf ( "Linked List is Empty  . \n");
    }
 }
  int Count  ( PNODE Head , PNODE Tail)
 {
    int iCount = 0;
        if (( Head != NULL ) && ( Tail != NULL) )
        {
            do
            {
                iCount ++;
                Head = Head -> next;
            }
            while ( Head != Tail -> next);
            return iCount;
        }
        else 
        {
            return 0;
        }
 }

 void InsertFirst ( PPNODE Head , PPNODE Tail , int No)
 {
    PNODE newn =  (PNODE) malloc ( sizeof(NODE));
        newn -> next = NULL;
        newn -> data = No;
    
    if ( (*Head == NULL) && ( *Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
        (*Tail ) -> next = *Head;
    }
    else 
    {
        newn -> next = *Head ;
        *Head = newn;
        (*Tail ) -> next = *Head;
    }
 }

void InsertLast ( PPNODE Head , PPNODE Tail , int No)
{
    PNODE newn = (PNODE) malloc (sizeof(NODE));
        newn -> next = NULL;
        newn -> data = No;
    
    if ( *Head == NULL)
    {
        *Head = newn ;
        *Tail = newn ;
        (*Tail) ->  next = *Head;
    }
    else
    {
        (*Tail )-> next = newn;
        *Tail = (*Tail) -> next;
        (*Tail) -> next = *Head;
    }
}

void DeleteFirst ( PPNODE Head  , PPNODE Tail)
{
    if ( (*Head == NULL) && (*Tail == NULL) )
    {
        return ;
    }
    else if ( *Tail == *Head)
    {
        free ( *Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head) -> next;
        free ( (*Tail ) -> next );
        (*Tail) -> next = *Head;
    }
}

void InsertAtPos ( PPNODE Head , PPNODE Tail , int No , int iPos)
{
    int iLength = Count (*Head , *Tail);
        if ( (iPos < 1) || ( iPos > iLength + 1) )
        {
            printf("InValid Position .. \n");
            return ; 
        }
    if ( iPos == 1)
    {
        InsertFirst ( Head , Tail , No);
    }
    else if ( iPos == iLength + 1)
    {
        InsertLast ( Head , Tail , No);
    } 
    else
    {
        PNODE newn = (PNODE)malloc ( sizeof ( NODE));
            newn -> next  = NULL;
            newn -> data = No;

        PNODE temp = *Head ;
        for (int iCnt = 1; iCnt < iPos - 1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
    }
    
}
void DeleteLast ( PPNODE Head , PPNODE Tail )
{
    if (( *Head == NULL) && (*Tail == NULL) )
    {
        return ;
    }
    else if ( *Head == *Tail )
    {
        free ( *Tail);
        *Tail = NULL;
        *Head = NULL;
    }
    else
    {
        PNODE temp = *Head;
        while ( temp -> next != *Tail)
        {
            temp = temp -> next;
        }
        free ( *Tail );
        *Tail = temp;
        (*Tail) -> next = *Head;
    }
}

void DeleteAtPos ( PPNODE Head , PPNODE Tail , int iPos)
{
    int iLength = Count ( *Head , *Tail);
        if (( iPos < 1) || (iPos > iLength ))
        {
            printf("Invalid Position .. \n");
            return ;
        }
    if ( iPos == 1)
    {
        DeleteFirst ( Head , Tail);
    }
    else if ( iPos == iLength) 
    {
        DeleteLast ( Head , Tail);
    }
    else
    {
        PNODE temp = *Head ; 
         for ( int iCnt = 1; iCnt < iPos -1 ; iCnt ++)
         {
            temp = temp -> next;
         }
        PNODE tempX = temp -> next;
        temp -> next = tempX -> next;
        free (tempX);
    }
}

 int main ()
{
    PNODE First = NULL;
    PNODE Last = NULL;

    InsertFirst ( &First , &Last , 21);
    InsertFirst ( &First , &Last , 11);
    InsertLast ( &First , &Last , 51);

    InsertAtPos ( &First , &Last , 89 , 3);
    InsertAtPos ( &First , &Last , 78 , 3);
    InsertAtPos ( &First , &Last , 509 , 3);

    Display  ( First , Last);

    DeleteLast ( &First , &Last);

    Display  ( First , Last);

    DeleteAtPos ( &First , &Last , 3 );
    DeleteAtPos ( &First , &Last , 3 );

    Display  ( First , Last);

    return 0;
 }