#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data ;
    struct Node * next;
}NODE , * PNODE , ** PPNODE;

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
void Display( PNODE Head)
{
    printf("Linked List is : \n\n");
    while ( Head != NULL)
    {
        printf("%d : ", Head -> data);
        Head = Head -> next;
    }
    printf("\n");
}


void InsertFirst ( PPNODE Head , int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
        newn -> data = No;
        newn -> next = NULL;
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else 
    {
        newn -> next = *Head;
        *Head = newn;
    }
}
void InsertLast ( PPNODE Head , int No)
{
    PNODE newn = (PNODE) malloc (sizeof (NODE));
        newn -> next = NULL;
        newn -> data = No;
    
    if ( *Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        PNODE temp = *Head ; 
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void InsertAtPos ( PPNODE Head , int No , int Pos)
{
    int iLength = Count ( *Head );
        if (( Pos < 0 ) || (Pos > iLength + 1) )
        {
            printf("Invalid Position .. \n");
            return;
        }  
    if ( Pos == 1)
    {
        InsertFirst ( Head , No);
    }    
    else if ( Pos == iLength + 1)
    {
        InsertLast ( Head , No );
    }
    else
    {
        PNODE newn = (PNODE) malloc (sizeof(NODE));
            newn -> next = NULL;
            newn -> data = No;

        PNODE temp = *Head ;
            for ( int iCnt = 1 ; iCnt < Pos - 1 ; iCnt ++)
            {
                temp = temp -> next;
            }
        newn -> next = temp -> next;
        temp -> next = newn;
        
    }
}

void DeleteFirst ( PPNODE Head)
{
    if ( *Head == NULL)
    {
        return;
    }
    else if ( (*Head) -> next == NULL)
    {
        free ( *Head );
        *Head = NULL;
    }
    else
    {
        PNODE temp = *Head ; 
        *Head = (*Head) -> next;
        free ( temp);
    }
}

void DeleteLast( PPNODE Head )
{
    if ( *Head == NULL)
    {
        return;
    }
    else if ((*Head) -> next == NULL)
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

void DeleteAtPos ( PPNODE Head , int Pos)
{
    int iLength = Count ( *Head );
        if (( Pos < 1) || (Pos > iLength) )
        {
            printf ( "Invalid Position .. \n");
            return;
        }
    if ( Pos == 1)
    {
        DeleteFirst ( Head );
    }
    else if ( Pos == iLength)
    {
        DeleteLast ( Head );
    }
    else 
    {
        PNODE temp = *Head ; 
         for ( int iCnt = 1 ; iCnt < Pos - 1 ; iCnt++)
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

        InsertAtPos ( &First  , 11 , 1 ); 
        InsertAtPos ( &First , 21 , 1 ); 
        InsertAtPos ( &First , 41 , 1 ); 
        InsertAtPos ( &First , 51 , 1 ); 
        InsertAtPos ( &First , 101 , 1 ); 
        InsertAtPos ( &First , 111 , 1 ); 

        Display ( First );

        DeleteAtPos ( &First , 1);
        Display ( First );
        DeleteAtPos ( &First , 5);
        Display ( First );
        DeleteAtPos ( &First , 3);

        Display ( First);

    return 0;
}   