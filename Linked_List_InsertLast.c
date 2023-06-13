#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data ;
    struct Node * next;
};

void Display_Count( struct Node * Head)
{
    printf("Linked List is : \n");
    int iCnt = 0;
    while (Head != NULL)
    {
        printf(": %d " , Head -> data);
        Head = Head -> next;
        iCnt++;
    }
    printf("\n");
    printf("Count is : %d \n" , iCnt);
}

void InsertFirst( struct Node ** Head  , int iNo)
{
    struct Node * newn = NULL;
    newn = (struct Node *) malloc(sizeof(struct Node));

    newn -> next = NULL;
    newn -> data = iNo;

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

void InsertLast( struct Node ** Head , int iNo)
{
    struct Node * temp = NULL;
    struct Node * newn = NULL ;
    newn = (struct Node * ) malloc (sizeof(struct Node));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        temp = *Head;

        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

int main()
{
    struct Node * First = NULL; 

    InsertFirst( &First , 51);
    InsertFirst( &First , 21);
    InsertFirst( &First , 11);

    Display_Count(First);

    InsertLast( &First , 300);
    InsertLast( &First , 100);
    InsertLast( &First , 200);
    Display_Count(First);


    return 0;
}