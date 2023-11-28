#include <iostream.h>
#include <conio.h>

	class Node
{
public:
	int data;
	Node *prev;
	Node *next;
	Node()
	{
		prev = next = NULL;
	}
};

class LinkedList
{
public:
	Node *start;
	Node *end;
	int size;

	LinkedList()
	{
		start = end = NULL;

		size = 0;
	}
	// Initialize the linked list Search on a node using the key
	inline Node *searchOnNode(int key)
	{
		Node *temp = start;
		if (start == NULL)
			return NULL;
		while (temp && temp->data != key)
			temp = temp->next;
		return temp;
	};
	void appendNode(Node *ele)
	{
		if (start == NULL) // Case 1: Empty List
		{
			// this is the first node in LL.
			start = end = ele;
		}
		else // Case 2: General Case
		{
			ele->prev = end; // 1
			end->next = ele; // 2
			end = ele;		 // 3
		}
		size++;
	};

	// Add a node at the end of the
	void insert(Node *ele)
	{
		Node *temp = start;
		while (temp && (temp->data < ele->data))
			temp = temp->next;
		// Case 1: Empty list or the new ele has largest data
		if (!temp)
			appendNode(ele);
		else
			// Case 2: New ele has smallest data
			if (temp == start)
			{
				start->prev = ele;
				ele->next = start;
				start = ele;
			}
			// Case 4: General case the suitable place is the place
			// before the temp points to
			else
			{
				temp->prev->next = ele; // 1
				ele->prev = temp->prev; // 2
				temp->prev = ele;		// 3
				ele->next = temp;		// 4
			}
		size++;
	}

	void deleteNode(int key)
	{
		Node *temp;
		if (!start)
			return; // Case 1: Empty List
		temp = searchOnNode(key);
		if (!temp)
			return;						  // Case 2: Not found
		if (start == temp && end == temp) // Case 3: Only one node
		{
			start = end = NULL;
			delete temp;
		}
		else
		{
			if (start == temp) // Case 4: First Node
			{
				start = start->next; // 1
				start->prev = NULL;	 // 2
				delete temp;		 // 3
			}
			else if (end == temp) // Case 5: Last Node
			{
				end = end->prev;  // 1
				end->next = NULL; // 2
				delete temp;	  // 3
			}
			else
			{								   // Case 6: General case
				temp->prev->next = temp->next; // 1
				temp->next->prev = temp->prev; // 2
				delete temp;				   // 3
			}
			size--;
		}
	}
	void freeList()
	{
		Node *temp = start;
		while (temp)
		{
			start = start->next;
			delete temp;
			temp = start;
		}
		end = NULL;
		size = 0;
	}
	int getSize()
	{
		return size;
	}
	int isEmpty()
	{
		return start == NULL;
	}
	// Check if it is empty list or not // Return the first Node and remove it
	Node *getFirst()
	{
		if (isEmpty())
			return NULL;
		Node *temp = start;
		// here i made second node as start one .
		start = start->next;
		// if it is first node in LL , then make prev = null to empty the tree .
		if (start)
			start->prev = NULL;
		else
			// this line is used to handle if the tree become empty .
			end = NULL;
		// disconnect the node from the tree .
		temp->prev = temp->next = NULL;
		size--;
		return temp;
	}
	Node *getLast()
	{
		if (isEmpty())
			return NULL;
		Node *temp = end;
		end = end->prev;
		if (end)
			end->next = NULL;
		else
			start = NULL;
		temp->prev = temp->next = NULL;
		size--;
		return temp;
	}
	Node *peekFirst()
	{
		if (isEmpty())
			return NULL;
		Node *temp = new Node();  // or may using the copy constructor
		temp->data = start->data; // ‘=‘ operator must be overloaded if
		// data is object from a class
		temp->prev = temp->next = NULL;
		return temp;
	}
	// Return the first Node without remove it
	Node *peekLast()
	{
		if (isEmpty())
			return NULL;
		Node *temp = new Node();
		temp->data = end->data;
		temp->prev = temp->next = NULL;
		return temp;
	};
	// Return the last Node without remove it
};

void main(){

    LinkedList ll;
    clrscr();
    Node node;
    node.data = 10;
    ll.appendNode(&node);
	Node *first;
	first = ll.getFirst();
    cout<<"first Node Data : "<<first->data;
    getch();
}