#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data ; 
    struct Node * next ;
};

void Display ( struct Node * Head)
{
    printf("Elelments of Linked list is : \n");
    while ( Head != NULL)
    {
        printf("%d : ", Head -> data);
        Head = Head -> next;
    }
    printf("\n");
}

int Count ( struct Node * Head)
{
    int iCount = 0;
    while ( Head != NULL)
    {
        iCount ++;
        Head = Head -> next;
    }
    return iCount;
}


void InsretFirst ( struct Node ** Head , int iNo )
{
    struct Node * newn = (struct Node *) malloc (sizeof (struct Node));

        newn -> data = iNo;
        newn -> next = NULL;
    
    if (* Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> next = *Head;
        *Head = newn;
    }
}

void InsertLast( struct Node ** Head , int iNo)
{
    struct Node * temp = NULL;
    struct Node * newn = (struct Node *) malloc (sizeof (struct Node));

        newn -> data = iNo;
        newn -> next = NULL;

    if (* Head  == NULL)
    {
        *Head = newn;
    }
    else
    {
        temp = *Head;
        while ( temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void DeleteFirst ( struct Node ** Head )
{
    if ( *Head  == NULL)
    {
        printf("Linked List is empty !! \n");
        return;
    }
    else if ((*Head) -> next == NULL )
    {
        free ( *Head) ;
        *Head = NULL;   
    }
    else{
        struct Node * temp = *Head;
        *Head = ( *Head ) -> next;
        free (temp);
    }
}

void DeleteLast ( struct Node ** Head )
{
    if ( *Head == NULL)
    {
         printf("Linked List is Empty  : \n");
         return;
    }
    else if ( (*Head) -> next == NULL)
    {
        free ( *Head);
        *Head = NULL;
    }
    else 
    {
        struct Node * temp = *Head;
        while (temp -> next -> next == NULL)
        {
            temp = temp -> next;
        }
        free ( temp -> next);
        temp -> next = NULL;
    }
}

void InsertAtPos ( struct Node ** Head , int iNo , int iPos)
{
    struct Node * temp = NULL;

    int iLength = Count ( *Head );

    if ( (iPos < 1 ) || ( iPos > iLength + 1) )
    {
        printf("InValid Position !! \n");
        return;
    } 
    if ( iPos == 1)
    {
        InsretFirst ( Head , iNo);
    }
    else if ( iPos == iLength + 1 )
    {
        InsertLast ( Head  , iNo);
    }
    else
    {
        temp = *Head;

        struct Node * newn = (struct Node *) malloc (sizeof (struct Node));

            newn -> next = NULL;
            newn -> data = iNo;

        for ( int iCnt = 1; iCnt < iPos -1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next ;
        temp -> next = newn;
    }
}

void DeleteAtPos ( struct Node ** Head , int iNo , int iPos)
{
    int iLength  = Count ( *Head );
    if ( (iPos < 1 ) || ( iPos > iLength ))
    {
        printf("Invalid Position !! \n");
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
        struct Node * temp = *Head;
        struct Node * tempX = temp -> next;

        for (  int iCnt = 1; iCnt < iPos -1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        temp -> next = tempX -> next;
        free ( tempX);

    }
}


int main()
{


    return 0;
}