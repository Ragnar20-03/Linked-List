#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    struct Node * prev ;
    int data ;
    struct Node * next ;
}NODE , *PNODE , **PPNODE;



int Count ( PNODE Head , PNODE Tail)
{
    int iCount = 0;
    if ( (Head != NULL) && (Tail != NULL) )
    {
        do 
        {
            iCount ++;
            Head =  Head -> next;
        }while ( Head != Tail -> next);
        return iCount;
    }
    else 
    {
        return 0;
    }
}

void Display ( PNODE Head , PNODE Tail)
{
    printf("INISIDE Display");
    if ( (Head != NULL) && (Tail != NULL) )
    {
        printf("Elements of Linked List are : \n");
        do 
        {
            printf(": %d : " , Head -> data);
            Head =  Head -> next;
        }while ( Head != Tail -> next);
        printf ( "\n");
    }
    else 
    {
        printf(" Linked List is Empty .. \n");
    }
}    


void InsertFirst ( PPNODE Head , PPNODE Tail , int No)
{ 
    printf ("Inside INSERTFIRST");

    PNODE newn = (PNODE) malloc (sizeof ( NODE));
        newn -> next = NULL;
        newn -> prev = NULL;
        newn -> data = No;
    
    if ( (*Head == NULL ) && ( *Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;

        (*Head) -> prev = *Tail;
        (*Tail ) -> next = *Head;
    }
    else
    {
        newn -> next = *Head ;
        (*Head) -> prev = newn ; 

        *Head = newn;

        (*Head )-> prev = *Tail;
        (*Tail) -> next = *Head;
    }
}

void InsertLast ( PPNODE Head  , PPNODE Tail , int No)
{
    printf ("Inside InsertLast");
    PNODE newn = ( PNODE ) malloc ( sizeof (NODE));
            newn -> prev = NULL;
            newn -> data = No;
            newn -> next = NULL;

    if ( (*Head == NULL  )&&  ( *Tail == NULL))
    {
        *Head = newn ;
        *Tail = newn ;

        (*Head ) -> prev = *Tail;
        (*Tail ) -> next = *Head;
    }
    else 
    {
        (*Tail) -> next = newn;
        newn -> prev = *Tail;

        *Tail = (*Tail ) -> next;

       (*Tail ) -> next = *Head;
        (*Head) -> prev = *Tail;
    }
}
void DeleteFirst ( PPNODE Head , PPNODE Tail )
{
    if ( (*Head == NULL) && (*Tail == NULL) )
    {
        return ;
    }
    else if ( *Head == *Tail)
    {
        free  (*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else 
    {
        *Head = (*Head) -> next;
        free ( (*Tail )-> next);

        (*Tail) -> next = *Head;
        (*Head ) -> prev = *Tail;
    }
}

void DeleteLast ( PPNODE Head , PPNODE Tail)
{
    if ( (*Head == NULL) && ( *Tail == NULL))
    {
        return ;
    }
    else if ( *Head == *Tail)
    {
        free ( *Tail);
        *Tail = NULL;
        *Head = NULL;
    }
    else 
    {
        *Tail = (*Tail) -> prev;
        free ( (*Head )-> prev);

        (*Tail ) -> next = *Head ;
        (*Head) -> prev = *Tail;
    }
}

int main()
{
    PNODE First = NULL;
    PNODE Last = NULL;

    InsertFirst ( &First , &Last , 101 );
    InsertFirst ( &First , &Last , 51 );
    InsertFirst ( &First , &Last , 21);
    InsertLast ( &First , &Last , 11 );

    Display  ( First ,Last);

    DeleteFirst ( &First , &Last);

    Display  ( First ,Last);

    DeleteLast ( &First , &Last);

    Display  ( First ,Last);
    
    return 0;
}