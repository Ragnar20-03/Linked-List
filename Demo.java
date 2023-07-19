import java.util.Scanner;

class Node
{
	public Node prev ; 
	public int data;
	public Node next;

	Node(int value)
	{
		this.data = value;
		this.prev = null;
		this.next = null;
	}
}

class DCL
{
	public Node head ;
	public Node tail ;
	int iCount ;

	DCL()
	{
		this.head = null;
		this.tail = null;
		iCount = 0 ;
	}
	public void DisplayRev()
	{
		Node temp = tail;
		if ( head != null)
		{
			System.out.println(" | Elements of Linked List are : ");

			do 
			{
				System.out.print(" | "+temp.data+" |");
				temp = temp.prev;
			}while(temp!=head.prev);
		}

	}

	public void Display()
	{
		Node temp = head;
		if ( head != null)
		{
			System.out.println(" | Elements of Linked List are : ");

			do 
			{
				System.out.print(" | "+temp.data+" |");
				temp = temp.next;
			}while(temp!=tail.next);
		}
	}
	public int Count()
	{
		return iCount;
	}
	public void InsertFirst(int no)
	{
		Node newn = new Node(no);

		if ( head == null)
		{
			head = newn;
			tail = newn;
		}
		else
		{
			newn.next = head;
			head.prev = newn;
			head = newn;
		}
		head.prev = tail;
		tail.next = head;
		iCount ++;
	}
	public void InsertLast( int no)
	{
		Node newn = new Node(no);

		if ( head == null)
		{
			head = newn;
			tail = newn;
		}
		else
		{
			newn.prev = tail;
			tail.next = newn;
			tail = tail.next;
		}
		head.prev = tail;
		tail.next = head;
		iCount++;
	}
	public void InsertAtPos(int no , int iPos)
	{
		int iLength = Count();
		if (( iPos < 1 ) || ( iPos > iLength +1))
		{
			return;
		}
		if ( iPos == 1)
		{
			InsertFirst(no);
		}
		else if (iPos == iLength + 1)
		{
			InsertFirst(no);
		}
		else 
		{
			Node newn = new Node(no);
			Node temp = head;
			for (int iCnt = 1 ; iCnt < iPos -1; iCnt ++)
			{
				temp = temp.next;
			}
			newn.next = temp.next;
			temp.next.prev = newn;

			temp.next = newn;
			newn.prev = temp;
		}
	}
	public void DeleteFirst()
	{
		if ( head == null)
		{
			return;
		}
		else if ( head.next == null)
		{
			head = null;
			tail = null;
		}
		else 
		{
			head = head.next;
		}
		head.prev = tail;
		tail.next = head;
	}
	public void DeleteLast()
	{
		if ( head == null)
		{
			return;
		}
		else if ( head.next == null)
		{
			head = null;
			tail = null;
		}
		else 
		{
			tail = tail.prev;
		}
		head.prev = tail;
		tail.next = head;
	}
	public void DeleteAtPos(int iPos)
	{
		int iLength = Count();
		if ( (iPos < 1) || ( iPos > iLength))
		{
			return;
		}
		if ( iPos == 1)
		{
			DeleteFirst();
		}
		else if(iPos == iLength)
		{
			DeleteLast();
		}
		else 
		{
			Node temp = head;
			for (int iCnt = 1 ; iCnt < iPos -1 ; iCnt ++)
			{
				temp = temp.next;
			}
			temp.next = temp.next.next;
			temp.next.prev = temp;
		}
	}
}

class Demo
{
	public static void main(String arg[])
	{
		DCL dobj = new DCL();
		dobj.InsertFirst(51);
		dobj.InsertLast(101);
		dobj.InsertFirst(21);
		dobj.InsertFirst(11);
		dobj.InsertLast((889));

		dobj.Display();
		dobj.DisplayRev();

		dobj.DeleteFirst();
		dobj.Display();
		dobj.DisplayRev();

		dobj.DeleteLast();
		dobj.Display();
		dobj.DisplayRev();

		dobj.DeleteAtPos(2);
		dobj.Display();
		dobj.DisplayRev();

	}


}