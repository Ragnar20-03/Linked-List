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

void InsertAtPos ( PPNODE Head , PPNODE Tail , int No , int iPos)
{
    int iLength = Count ( *Head , *Tail);
        if (( iPos <  1 ) || ( iPos > iLength + 1) )
        {
            printf ("Invalid Position .. \n");
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
        PNODE newn = (PNODE) malloc (sizeof ( NODE));
            newn -> next = NULL;
            newn -> prev = NULL;
            newn -> data = No;

        PNODE temp = *Head ;
        for (int iCnt = 1; iCnt < iPos -1 ; iCnt ++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn ;

        temp -> next = newn;
        newn -> prev = temp;

    }
}

void DeleteAtPos ( PPNODE Head , PPNODE Tail , int iPos )
{
        int iLength = Count ( *Head , *Tail);
        if (( iPos <  1 ) || ( iPos > iLength ) )
        {
            printf ("Invalid Position .. \n");
            return ;
        }
    if ( iPos == 1)
    {
        DeleteFirst ( Head , Tail);
    }
    else if ( iPos == iLength )
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
        temp -> next = temp -> next -> next;
        free ( temp -> next -> prev);
        temp -> next -> prev = temp;
    }
}

int main()
{
    PNODE First = NULL;
    PNODE Last = NULL;
    int iRet = 0;

    InsertFirst(&First,&Last,51);
    InsertFirst(&First,&Last,21);
    InsertFirst(&First,&Last,11);

    InsertLast(&First,&Last,101);
    InsertLast(&First,&Last,111);
    InsertLast(&First,&Last,121);

    Display(First,Last);

    iRet = Count(First,Last);
    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&First, &Last, 55, 4);
    Display(First,Last);

    iRet = Count(First,Last);
    printf("Number of nodes are : %d\n",iRet);

    DeleteAtPos(&First, &Last, 4);
    Display(First,Last);

    iRet = Count(First,Last);
    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&First, &Last);
    DeleteLast(&First, &Last);
    
    Display(First,Last);

    iRet = Count(First,Last);
    printf("Number of nodes are : %d\n",iRet);
    
    return 0;
}