#include<stdio.h>
#include<stdlib.h>


struct Node {

    int  data ;
    struct Node * next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;


void DeleteFirst()
{

}

void DeleteLast()
{

}

void DeleteAtPos()
{

    
}

int Count ( PNODE Head )
{
    int iCnt = 0;

    while (Head != NULL)
    {
        iCnt++;
        Head = Head -> next;
    }

    return iCnt;
}

void Display ( PNODE Head )
{
    printf( "Elements of Linked List Are : \n");
    while ( Head != NULL)
    {
        printf(" : %d : ", Head -> data);
        Head = Head -> next;
    }
    printf("\n");
}


void InsertLast ( PPNODE Head , int iNo)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if( *Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}


void InsertFirst( PPNODE Head , int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if( *Head == NULL){
        *Head = newn;
    }
    else
    {
        newn -> next = *Head;
        *Head = newn;
    }
}

int main()
{
    int iRet = 0;
    PNODE First = NULL;

    InsertFirst( &First, 51 );
    InsertFirst( &First, 21 );
    InsertFirst( &First, 11 );

    Display( First );

    printf("After InsertLast :\n");

    InsertLast ( &First , 100);
    InsertLast ( &First , 200);
    InsertLast ( &First , 300);
    InsertLast ( &First , 400);

    Display( First);

    iRet = Count ( First);    
    printf("Count is  : %d \n", iRet);

    return 0;
}