#include<stdio.h>
#include<stdlib.h>


struct Node 
{
    struct Node * prev ; 
        int data ;
    struct Node * next ;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;


void InsertFirst ( PPNODE Head , PPNODE Tail , int No)
{
    
}

int main()
{
    PNODE First = NULL;
    PNODE Last  = NULL;

    return 0;
}