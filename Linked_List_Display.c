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

int main()
{
    struct Node * First = NULL; 

    InsertFirst( &First , 51);
    InsertFirst( &First , 21);
    InsertFirst( &First , 11);

    Display_Count(First);

    return 0;
}