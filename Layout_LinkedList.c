#include<stdio.h>
#include<stdlib.h>

 struct Node{
    int data;
    struct Node * next;
};

typedef struct Node NODE;
typedef struct Node * PNODE ; 
typedef struct Node ** PPNODE;


void InsertLast( PPNODE Head , int iNo)
{
    PNODE temp = *Head;
    PNODE newn = NULL;
    newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*Head == NULL)
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

void InsertFirst( PPNODE Head  , int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc (sizeof(NODE));
    newn -> data = iNo;
    newn -> next = NULL;

    if( *Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> next = *Head;
        *Head = newn;
    }

}

void Display ( PNODE Head)
{
    printf("Linked list is :\n");
    while (Head  != NULL)
    {
        printf("%d\t",Head->data);
        Head = Head -> next;
    }
    printf("\n");
}

void Count ( PNODE Head)
{
    int iCnt = 0;
    printf("CCount of Linked list is :\n");
    while (Head  != NULL)
    {
        iCnt++;
        Head = Head -> next;
    }
    printf("%d \n" , iCnt);
}

int main()
{
    PNODE First = NULL;  // Main Pointer which points to Linked List;

    InsertFirst( &First , 51);
    InsertFirst( &First , 11);
    InsertFirst( &First , 21);

    Display(First);

    printf("After insert Last \n");

    InsertLast(&First , 511);
    InsertLast(&First , 522);

    Display(First);
    Count(First);

    return 0;
}