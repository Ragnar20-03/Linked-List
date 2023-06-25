#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    struct Node * prev ;
    int data ; 
    struct Node * next ;
};

typedef struct Node * PNODE;
typedef struct Node NODE;
typedef struct Node ** PPNODE;

void Display ( PNODE Head , PNODE Tail)
{  
    if ( (Head != NULL) && ( Tail != NULL))
    {
        printf("Elements of Linked List is : \n");
        do 
        {
            printf ( " %d : ",Head -> data);
            Head = Head -> next;
        }while ( Head != Tail -> next);
        printf("\n");
    }
    else 
    {
        printf ( " \n");
    }
}

int Count ( PNODE Head , PNODE Tail)
{
    if ( (Head != NULL) && ( Tail != NULL) )
    {
        int iCount = 0;
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


void InsrertFisrt ( PPNODE Head , PPNODE Tail , int No)
{
    PNODE newn = (PNODE) malloc (sizeof ( NODE));
        newn -> next = NULL;
        newn -> data = No;
        newn -> prev = NULL;

    if ( (*Head == NULL) && ( *Tail == NULL))
    {
        *Head = newn ;
        *Tail = newn  ;
    }
    else 
    {
        newn -> next = *Head ; 
        (*Head) -> prev = newn ;

        *Head = newn ;
    }
            (*Head) -> prev = *Tail; 
        (*Tail ) -> next = *Head;
} 

void InsertLast ( PPNODE Head , PPNODE Tail , int No)
{
    PNODE newn = (PNODE)malloc (sizeof(NODE));
        newn -> data = No;
        newn -> next = NULL;
        newn -> prev = NULL;

    if ( (*Head == NULL) && ( *Tail == NULL) )
    {
        *Head = newn ;
        *Tail = newn ;
    }
    else 
    {
        (*Tail) -> next = newn ; 
        newn -> prev = *Tail;

        *Tail = newn ;

    }
        (*Head) -> prev = *Tail; 
        (*Tail ) -> next = *Head;
}

void DeleteFirst ( PPNODE Head , PPNODE Tail )
{
    if ( (*Head == NULL ) && ( Tail == NULL ) )
    {
        return ;
    }
    else if (*Head == *Tail)
    {
        free ( *Head);
        *Head = NULL ;
        *Tail = NULL;
    }
    else 
    {
        *Head = (*Head) -> next;
        free ( (*Tail ) -> next );
        
        (*Tail) -> next = *Head;
        (*Head) -> prev = *Tail; 
    }
}
void DeleteLast ( PPNODE Head , PPNODE Tail )
{
    if ( (*Head == NULL ) && ( *Tail == NULL) )
    {
        return;
    }
    else if ( *Tail == *Head )
    {
        free ( *Tail);
        *Tail = NULL;
        *Head = NULL;
    }
    else
    {   
        *Tail = (*Tail) -> prev;
        free ( (*Head ) -> prev );

        (*Tail) -> next = *Head;
        (*Head) -> prev = *Tail; 
    }
}

void DeleteAtPos ( PPNODE Head , PPNODE Tail , int iPos)
{
    int iLength = Count ( *Head , *Tail);
        if ( (iPos < 1) && ( iPos > iLength))
        {
            printf ("Invalid Position \n");
            return ;
        }
    if ( iPos == 1 )
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
        for ( int iCnt  = 1 ; iCnt <  iPos - 1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        free ( temp -> next -> prev);
        temp -> next -> prev = temp ;

    }
}


int main()
{
	PNODE First = NULL:

    InsertLast ( &First , &Last , 89);
    InsrertFisrt( &First , &Last , 11);
    InsertLast ( &First , &Last , 21);
    InsertLast ( &First , &Last , 51);
    InsertLast ( &First , &Last , 78);
    InsertLast ( &First , &Last , 99);

    Display ( First , Last);

    DeleteFirst ( &First , &Last);
    DeleteLast ( &First , &Last);

    Display ( First , Last);

    DeleteAtPos ( &First , &Last , 3);

    Display ( First , Last);

    return 0;
}
