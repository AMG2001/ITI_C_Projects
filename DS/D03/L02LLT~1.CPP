#include <iostream.h>
#include <conio.h>

template <class T>
class Node
{
public:
    T data;
    Node<T> *prev;
    Node<T> *next;
	Node()
    {
        prev = next = NULL;
    }
};

template <class T>
class LinkedList
{
public:
    Node<T> *start;
    Node<T> *end;
    int size;

    LinkedList()
    {
        start = end = NULL;
        size = 0;
    }

    Node<T> *searchOnNode(T key)
    {
        Node<T> *temp = start;
        if (start == NULL)
            return NULL;
        while (temp && temp->data != key)
            temp = temp->next;
        return temp;
    }

    void appendNode(Node<T> *ele)
    {
        if (start == NULL) // Case 1: Empty List
        {
            // this is the first Node<T> in LL.
            start = end = ele;
        }
        else // Case 2: General Case
        {
            ele->prev = end; // 1
            end->next = ele; // 2
            end = ele;       // 3
        }
        size++;
    };

    // Add a Node<T> at the end of the
    void insert(Node<T> *ele)
    {
        Node<T> *temp = start;
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
                temp->prev = ele;       // 3
                ele->next = temp;       // 4
            }
        size++;
    }

    void deleteNode(int key)
    {
        Node<T> *temp;
        if (!start)
            return; // Case 1: Empty List
        temp = searchOnNode(key);
        if (!temp)
            return;                       // Case 2: Not found
        if (start == temp && end == temp) // Case 3: Only one Node<T>
        {
            start = end = NULL;
            delete temp;
        }
        else
        {
            if (start == temp) // Case 4: First Node<T>
            {
                start = start->next; // 1
                start->prev = NULL;  // 2
                delete temp;         // 3
            }
            else if (end == temp) // Case 5: Last Node<T>
            {
                end = end->prev;  // 1
                end->next = NULL; // 2
                delete temp;      // 3
            }
            else
            {                                  // Case 6: General case
                temp->prev->next = temp->next; // 1
                temp->next->prev = temp->prev; // 2
                delete temp;                   // 3
            }
            size--;
        }
    }
    void freeList()
    {
        Node<T> *temp = start;
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
    // Check if it is empty list or not // Return the first Node<T> and remove it
    Node<T> *getFirst()
    {
        if (isEmpty())
            return NULL;
        Node<T> *temp = start;
        // here i made second Node<T> as start one .
        start = start->next;
        // if it is first Node<T> in LL , then make prev = null to empty the tree .
        if (start)
            start->prev = NULL;
        else
            // this line is used to handle if the tree become empty .
            end = NULL;
        // disconnect the Node<T> from the tree .
        temp->prev = temp->next = NULL;
        size--;
        return temp;
    }
    Node<T> *getLast()
    {
        if (isEmpty())
            return NULL;
        Node<T> *temp = end;
        end = end->prev;
        if (end)
            end->next = NULL;
        else
            start = NULL;
        temp->prev = temp->next = NULL;
        size--;
        return temp;
    }
    Node<T> *peekFirst()
    {
        if (isEmpty())
            return NULL;
        Node<T> *temp = new Node<T>();  // or may using the copy constructor
        temp->data = start->data; // ‘=‘ operator must be overloaded if
        // data is object from a class
        temp->prev = temp->next = NULL;
        return temp;
    }
    // Return the first Node<T> without remove it
    Node<T> *peekLast()
    {
        if (isEmpty())
            return NULL;
        Node<T> *temp = new Node<T>();
        temp->data = end->data;
        temp->prev = temp->next = NULL;
        return temp;
    };
    // Return the last Node<T> without remove it
};

void main()
{
    clrscr();
    LinkedList<int> lInt;
    Node<int> n1;
    n1.data = 1;
	lInt.appendNode(&n1);
	n1.data = 2;
    lInt.appendNode(&n1);
    LinkedList<char> lChar;
    getch();
}