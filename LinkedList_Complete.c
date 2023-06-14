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

void Display ( PNODE Head )
{
    printf ("Elements of Linked List is \n");

    while (Head != NULL)
    {
        printf("%d \t ",Head-> data);
        Head = Head -> next;
    }
    printf ("\n");
}

int Count ( PNODE Head )
{
    int iCount = 0;
    while (Head != NULL)
    {
        iCount ++;
        Head = Head -> next;
    }
    return iCount;
}


void InsertLast( PPNODE Head  , int iNo)
{
    PNODE temp = NULL;

    PNODE newn = (struct Node * ) malloc (sizeof(NODE));

        newn -> data = iNo;
        newn -> next = NULL;
    
    if (* Head  == NULL)
    {
        *Head = newn;
    }
    else
    {
        temp = *Head;
        while (temp -> next != NULL )
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }

}


void InsertFirst ( PPNODE Head , int iNo)
{
    PNODE newn = (PNODE) malloc (sizeof(NODE));
    
        newn -> data = iNo;
        newn -> next = NULL;

    if ( *Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> next= *Head ; 
        *Head = newn;
    }
}

void DeleteFirst ( PPNODE Head )
{
    PNODE temp = *Head;
    if (*Head == NULL)
    {
        printf("Linked List s Empty .. \n");
        return;
    }
    else if ( (*Head )-> next == NULL)
    {
        free (*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head) -> next; // OR *Head = temp -> next;
        free (temp);
    }
}

int main()
{
    PNODE First = NULL;

    InsertFirst( &First , 51);
    InsertFirst( &First , 21);
    InsertFirst( &First , 11);

    InsertLast ( &First , 100);
    InsertLast ( &First , 200);

    Display( First);

    DeleteFirst ( &First);

    Display ( First );

    return 0;
}