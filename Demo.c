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
        return;
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
        free ( temp -> next -> prev);
        temp -> next -> prev = temp;
    }
}

void InsertAtPos ( PPNODE Head , int iPos , int No)
{
    int iLength = Count ( *Head );
        if (( iPos < 1 ) || ( iPos > iLength + 1) )
        {
            return ;
        }
    
    if ( iPos == 1)
    {
        InsertFirst ( Head , No);
    }
    else if ( iPos == iLength + 1)
    {
        InsertLast ( Head , No);
    }
    else 
    {
        PNODE newn = (PNODE) malloc ( sizeof (NODE));
                newn -> prev = NULL;
                newn -> data = No;
                newn -> next = NULL;

        PNODE temp = *Head;
        for ( int iCnt = 1 ; iCnt < iPos -1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn ;

        temp -> next = newn ;
        newn -> prev = temp;        
    }
}

int main()
{   
    PNODE First = NULL;

    int iRet = 0;

    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);        
    InsertFirst(&First,11);

    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);
    
    InsertLast(&First,111);
    InsertLast(&First,121);

    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);
    
    InsertAtPos(&First, 55, 4);
    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);

    DeleteAtPos(&First, 4);
    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);

    DeleteFirst(&First);
    DeleteLast(&First);

    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);

    return 0;
}

