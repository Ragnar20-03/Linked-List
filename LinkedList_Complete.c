#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data ;
    struct Node * next ;
};
typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;


int Count ( PNODE Head )
{
    int iCount = 0;
    while ( Head != NULL)
    {
        Head = Head -> next ; 
        iCount ++;
    }
    return iCount;
}
void Display ( PNODE Head )
{
    printf ( " || \n");
    while ( Head != NULL)
    {
        printf( " %d :", Head -> data);
        Head = Head -> next ; 
    }
    printf("\n");
}

void InsertFirst ( PPNODE Head , int No)
{
    PNODE newn = (PNODE)malloc ( sizeof (NODE));
        newn -> data = No;
        newn -> next = NULL;
    
    if ( *Head ==NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> next = *Head;
        *Head = newn;
    }
}

void InsertLast( PPNODE Head , int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
        newn -> data = No;
        newn -> next = NULL;
 
    if ( *Head  == NULL)
    {
        *Head = newn;
    }
    else
    {
        PNODE temp = *Head ;
        while ( temp ->  next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;

    }
}

void InsertAtPos ( PPNODE Head , int No , int Pos)
{
    int iLength = Count ( *Head);
    if ((Pos < 1) || ( Pos > iLength +1))
    {
        printf("InValid Position .. \n");
        return;
    }
    if ( Pos == 1)
    {
        InsertFirst ( Head , No);
    }
    else if ( Pos == iLength + 1)
    {
        InsertLast ( Head , No);
    }
    else
    {
        PNODE newn = (PNODE) malloc (sizeof ( NODE));
            newn -> data = No;
            newn -> next = NULL;
        
        PNODE temp = *Head;
        for ( int iCnt = 1 ; iCnt < Pos -1 ; iCnt++)
        {   
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
    }
}

void DeleteFirst ( PPNODE Head  )
{
    if ( *Head == NULL)
    {
       printf("Linked List Is Empty ..");
       return;
    }
    else if ( (*Head) -> next == NULL)
    {
        free ( *Head);
        *Head = NULL;
    }
    else
    {
        PNODE temp = *Head ; 
        *Head = (*Head) -> next ;
        free ( temp);
    }
}

void DeleteLast( PPNODE Head )
{
    if ( *Head == NULL)
    {
        printf("Linked List is Empty || \n");
        return;
    }
    else if ( (*Head ) -> next == NULL)
    {
        free ( *Head );
        *Head == NULL;
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

void DeleteAtPos ( PPNODE Head , int iPos)
{
    int iLength = Count ( *Head );
        if (( iPos < 1) || ( iPos > iLength))
        {
            printf ( " InValid Position \n");
            return;
        }
        if ( iPos == 1)
        {
            DeleteFirst ( Head );
        }
        else if ( iPos == iLength)
        {
            DeleteLast ( Head );
        }
        else 
        {
            PNODE temp = *Head ; 
            for ( int iCnt = 1 ; iCnt < iPos -1; iCnt ++)
            {
                temp = temp -> next;
            }
            PNODE tempX = temp -> next;
            temp -> next = temp -> next -> next;
            free ( tempX);
        }
}

int main()
{
    PNODE First = NULL;

      InsertFirst ( &First , 11);

    InsertAtPos ( &First , 21 , 2);
    InsertAtPos ( &First , 1 , 1);
    InsertAtPos ( &First , 51 , 2);
    InsertAtPos ( &First , 891 , 2);

    Display ( First );

    DeleteAtPos ( &First , 2 );
    DeleteAtPos ( &First , 3);

    Display ( First );

    return 0;
}