#include "stdafx.h"
#include<iostream> 

using namespace std;
template <typename T>
class Node     // Node of a singly linked list
{
	public:
	T data;
	Node *next;

	Node(T data, Node *next)
	{
		this->data = data;
		this->next = next;
	}
};

template <typename T>
class SLinkedlist   
{
	Node<T> *head;
	Node<T> *tail;
	int index;
	int size;
public:
	SLinkedlist()
	{
		head = NULL; // EMPTY list
		size = 0;
		tail = NULL;
	}
	SLinkedlist(T data)   // Constructor
	{
		Node<T> *temp = new Node<T>(data, NULL );
		head = temp;
		size = 1;
		tail= temp;
	}
	void append(T data )    // Add node at the end of the list   O(1)
	{
		Node<T> *temp;
		if(tail!=NULL)
		{
			Node<T> *newnode = new Node<T>(data,NULL);
			tail->next = newnode;
			size++;
			tail = newnode;
		}
		else // Empty list
		{
			Node<T> *temp = new Node<T>(data, NULL );
			head = temp;
			size++;
			tail = head;
		}
	}

	void addFirstElement(T data)    // Add Node to the front of the list  O(1)
	{
		if ( head != NULL )
		{
			Node<T> *newnode = new Node<T>(data,head);
			head = newnode;
			size++;
		}
		else
		{
			Node<T> *newnode = new Node<T>(data,NULL);
			head = newnode;
			size++;
			tail = head;
		}
	}

	void insert(T delelement,T newelement)         // Insert given node from the list  O(n)
	{
		Node<T> *temp, *del;
		bool b = false;
		if ( head != NULL )
		{
			del = head;
			while ( del != NULL )
			{
				if ( del->data == delelement )
				{
					Node<T> *newnode = new Node<T>(newelement,del->next);
					temp->next = newnode; 
					if ( newnode->next == NULL )
						tail = newnode;
					delete del;
					b=true;
					break;
				}
					temp = del;
					del = del->next;
			}
			if ( b == false )
				cout<<"element not found";
		}
		else
		{
			cout<<"Empty list";
		}
	}

	void RemoveFirstElement()           // Remove from begining of the list  O(1)
	{
		if ( head!= NULL )
		{
			Node<T> *temp = head;
			head = head->next;
			delete temp;
			size--;
		}
		else
		{
			cout<<"Empty list";
		}
	}

	void RemoveFromLast()              // Remove from end of the list   O(n)
	{
		Node<T> *temp, *del;

		if ( head != NULL )
		{
			if ( head == tail )
			{
				del = head;
				head = head->next;     //make both head and tail null
				tail = head;
				delete del;
				size--;
			}
			else 
			{
				temp = head;
				while ( temp->next != tail )
				{
					temp = temp->next;
				}
				del = tail;
				tail = temp;
				tail->next = del->next;
				delete del;
				size--;
			}
		}
	}

	void Remove(T element)              // Remove given node from the list  O(n)
	{
		Node<T> *trav,*trav1;
		if ( head != NULL && head->next!= NULL) // head->next!=NULL is  not needed
		{
			trav1 = head;
			trav = head;
			while( trav1->data != element )
			{
				trav = trav1;
				trav1 = trav1->next;
			}
			trav->next = trav1->next;
			delete trav1;
			size--;
		}
		else
		{
			cout<<"Empty list";
		}
	}

	void searchElement(T element )       // Search a node within the list O(n)
	{
		Node<T> *trav;
		int index=-1, found = 0;
		if ( head != NULL )
		{
			trav = head;
			while( trav != NULL )
			{
				index++;
				if ( trav->data == element )
				{
					found = 1;
					break;
				}
				trav = trav->next;
			}
			if ( found == 1 )
				cout<<"Element "<<element<<" found at :"<<index;
			else
				cout<<"Element not found";
		}
		else
		{
			cout<<"Empty List";
		}
	}

	void PrintList()                // Output all element in the list   O(n)
	{
		Node<T> *temp;
		if ( head!=NULL )
		{
			temp = head;
			cout<<"\n";
			while( temp != NULL ) // check for empty list
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
		}
		else
			cout<<"Empty list";
	}
	int getsize()
	{
		return(size);
	}
  Node<T>* reverse( Node<T> *head)
	{
		if ( head->next == NULL )
			return head;
		Node<T> *temp = reverse(head->next);
		head->next->next = head;
		head->next = NULL;
		return(temp);
	}

	void recReverseList()
	{
		Node<T> *prev=NULL;
		head=reverse(head);
	}

	~SLinkedlist()
	{
		delete head;
		head = NULL;
		tail = NULL;
	}
  };
int _tmain(int argc, _TCHAR* argv[])
{
SLinkedlist<int> slist(1);
	slist.append(2);
	slist.append(3);
	slist.append(4);
	slist.append(5);
	slist.append(6);
	slist.append(7);
	slist.append(8);
	slist.append(9);
	slist.PrintList();
	slist.recReverseList();
  return 0;
}
