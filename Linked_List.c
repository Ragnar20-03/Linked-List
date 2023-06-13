#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data ; 
    struct Node * next;

};

void Display(  )
{

}

void InsertFirst(struct Node ** Head , int iNo)
{
    struct Node * newn = NULL;
    newn = (struct node *) malloc (size of (struct Node))

    newn -> data = iNo;
    newn -> next = NULL:

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

    return 0;
}

