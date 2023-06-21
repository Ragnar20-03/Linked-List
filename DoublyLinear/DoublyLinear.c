#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data ;
    struct Node * next;
}NODE , *PNODE, **PPNODE;


int Count ( PNODE Head )
{
    int iCount = 0;
    while ( Head != NULL)
    {
            iCount ++;
            Head = Head -> next;
    }
    return iCount;
}

void Display(PNODE Head)
{
    printf("Elements of Linked List is : \n");
    while (Head != NULL)
    {
        printf(" %d : ", Head -> data);
        Head = Head -> next;
    }
    printf("NULL \n ");
}

int main()
{
    PNODE First = NULL;

    return 0;
}