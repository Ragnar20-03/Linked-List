#include<iostream>

using namespace std;

typedef struct Node 
{
    int data;
    struct Node * next;
}NODE , *PNODE;


class LinkedList 
{
    private :
        int iCount  ;
        PNODE First ;

    public : 
         LinkedList ();
         ~LinkedList();

         void InsertFirst ( int No);
         void InsertLast ( int No);
         void InsertAtPos ( int No , int iPos);
         void DeleteFirst ( );
         void DeleteLast (  );
         void DeleteAtPos ( int iPos);
         void Display ();
         int Count ();

         void Delete ();
};

LinkedList :: LinkedList()
{
    First = NULL;
    iCount = 0 ;
}

void LinkedList :: InsertFirst ( int No)
{
    PNODE newn = new NODE;
        newn -> data = No;
        newn -> next = NULL;

    if ( First == NULL)
    {
        First = newn ;
    }
    else 
    {
        newn -> next = First ; 
        First = newn ;
    }
    iCount ++;
}

void LinkedList :: InsertLast (int No)
{
    PNODE newn = new NODE;
        newn -> data = No;
        newn -> next = NULL;
    
    if ( First == NULL)
    {
        First = newn ;
    }
    else 
    {
        PNODE temp = First;
            while ( temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newn ;
    }
    iCount ++;
}

void LinkedList :: DeleteFirst ( )
{
    if ( First == NULL )
    {
        return ;
    }
    else  if ( First ->  next == NULL)
    {
        delete First;
        First = NULL;
    }
    else 
    {
        PNODE temp = First ;
        First = First -> next;
        delete temp;
    }
    iCount--;
}

void LinkedList :: DeleteLast ()
{
    if ( First == NULL )
    {
        return;
    }
    else if ( First -> next == NULL )
    {
        delete First ;
        First = NULL;
    }
    else 
    {
        PNODE temp = First ;
        while ( temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next =  NULL;
    }
    iCount --;
}

void LinkedList :: Display ()
{
    PNODE temp = First ;
    while ( temp != NULL )
    {
        cout<< " : "<<temp -> data <<" :";
        temp = temp -> next;
    }
    cout<<" NULL :\n ";
}

int LinkedList :: Count ()
{
    return iCount;
}

void LinkedList :: InsertAtPos ( int No  , int iPos) 
{
        if (( iPos < 1) || ( iPos  >  iCount + 1) )
        {
            return;
        }
    if ( iPos == 1)
    {
        InsertFirst ( No);
    }
    else if ( iPos == iCount + 1)
    {
        InsertLast ( No);
    }
    else
    {
        PNODE newn = new NODE;
            newn -> data = No;
            newn -> next = NULL;
        
        PNODE temp = First;
        for (int iCnt = 1; iCnt < iPos -1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn ;
        iCount ++;
    }
} 

void LinkedList :: DeleteAtPos ( int iPos )
{
            if (( iPos < 1) || ( iPos  >  iCount ) )
        {
            return;
        }
    if ( iPos == 1)
    {
        DeleteFirst();
    }
    else if ( iPos == iCount )
    {
        DeleteLast ();
    }
    else
    {   
        PNODE temp = First;
        for (int iCnt = 1; iCnt < iPos -1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        PNODE tempX = temp -> next;
        temp -> next = temp -> next -> next;
            delete tempX;
            iCount --;
    }
}

void LinkedList :: Delete ()
{
    PNODE temp = First ;
    
    for ( int iCnt = 1; iCnt <= iCount ; iCnt ++)
    {
        temp = First;
        First = First -> next;
        delete temp;
    }
    if ( First == NULL)
    {
        cout<<"Resources Succesfully Deallocated : : \n";
    }
}

LinkedList :: ~LinkedList ()
{
    cout<<"Inside Destuctor ;; \n";
    if ( First == NULL)
    {
        cout<<"Resources Succesfully Deallocated : : \n";
    }
    else{
    Delete ();
    }
}

int main()
{
    LinkedList obj ; 

    int iChoice  =  0 ;
    int iValue = 0;
    int iPosition =  0;

    cout<<"Marvellous Linked List Application \n";

    while (1)
    {
        cout<<"----------------------------------------------------\n";
        cout<<"Please Enter Ypur Choice : \n"<<endl;
        cout<<" 1 : Insert Node at First Position \n";
        cout<<" 2 : Insert Node at Last Position \n";
        cout<<" 3 : Insert Node at Given Position \n";
        cout<<" 4 : Delete Node at First Position \n";
        cout<<" 5 : Delete Node at last Position \n";
        cout<<" 6 : Delete Node at Given Position \n";
        cout<<" 7 : Display Linked List \n";
        cout<<" 8 : Count Numner of Nodes from Linked List  \n";
        cout<<" 9 : Delete Whole  Linked List \n";
        cout<<" 10 : Terminate Application \n";

        cout<<"----------------------------------------------------\n";

        cin >> iChoice ; 

        switch ( iChoice)
        {
            case 1 :
            cout<<"Enter Value \n";
            cin>>iValue;
            obj.InsertFirst ( iValue);
        ////IMP ( obj .  )///
            break;
            
            case 2 :
            cout<<"Enter Value \n";
            cin>>iValue;
            obj.InsertLast ( iValue);
            break;
            
            case 3 :
            cout<<"Enter Value \n";
            cin>>iValue;
            cout<<"Enter Position \n";
            cin>>iPosition;
            obj.InsertAtPos( iValue , iPosition);
            break;

            case 4 :
            obj.DeleteFirst ();
            break;

            case 5 :
            obj.DeleteLast ();
            break;

            case 6 :
            cout<<"Enter Position \n";
            cin>>iPosition;
            obj.DeleteAtPos( iPosition);
            break;

            case 7 :
            obj.Display ();
            break;

            case 8 :
            cout<<"Bumber of Nodes are : "<<obj.Count()<<"\n";
            break;

            case 9 :
            obj.Delete();
            break;

            case 10 :
            cout<<"Thank You for Using the Apllication \n";
            return 0;

            default :
            cout<<"Invalid Choice : \n";
            break;

        }
    }


    return 0;
}