#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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


void InsertFirst ( struct Node ** Head , int iNo )
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
        InsertFirst ( Head , iNo);
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

void DeleteAtPos ( struct Node ** Head  , int iPos)
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
    struct Node * First = NULL;

    int iChoice  = 0;
    int iNo = 0;
    int iPos = 0;
    bool bFlag = true;

    while (bFlag)
    {
        printf("\nMenu :: \n 1: InsertFirst \n 2: InsertLast: \n 3 : InsertAtPos \n 4 : DeleteFirst \n 5 : DeleteLast \n 6 : DeleteAtPos \n 7 : Display \n 8 : Count \n");
        printf("\nPress 0 to EXIT ... \n");
        scanf ( "%d" , & iChoice);

    switch ( iChoice)
    {
        case 1: 
        printf("Enter Data : \n");
        scanf ("%d", & iNo);
        InsertFirst( &First , iNo);
        break;

        case 2: 
        printf("Enter Data : \n");
        scanf ("%d", & iNo);
        InsertLast( &First , iNo);
        break;

        case 3: 
        printf("Enter Data : \n");
        scanf ("%d", & iNo);
        printf("Enter Position : \n");
        scanf ( "%d",&iPos);
        InsertLast( &First , iNo);
        break;

        case 4: 
        DeleteFirst( &First );
        break;
        
        case 5: 
        DeleteFirst( &First );
        break;
        
        case 6: 
        printf("Enter Position : \n");
        scanf ( "%d",&iPos);
        DeleteAtPos( &First , iPos);
        break;

        case 7 :
        Display ( First);
        break;

        case 8 :
        Count ( First);
        break;

        default : 
        printf("Incoorect Choice .. \n");
        bFlag = false;
    }
    }


    return 0;
}