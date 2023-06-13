#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next ;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node **PPNODE;


void InsertFirst(PPNODE Head , int No)
{

    PNODE newn = NULL;
    newn = (PNODE) malloc(sizeof(NODE)) ;

    newn-> data = No;
    newn-> next = NULL;

    if( *Head == NULL)
    {
        *Head = newn;
    }
}

int main()
{
    PNODE First = NULL;

    return 0;
}