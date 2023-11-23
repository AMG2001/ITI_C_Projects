#include <iostream.h>
#include <conio.h>

template <class T>
class Stack
{
private:
    int top, size;
    T *ptr;
    static int counter;

public:
    Stack()
    {
        top = 0;
        size = 10;
        ptr = new T[size];
        counter++;
    }
    Stack(int n)
    {
        top = 0;
        size = n;
        ptr = new T[size];
        counter++;
    }
    ~Stack()
    {
        delete[] ptr;
        counter--;
    }
    static int getCounter()
    {
        return counter;
    }
    Stack(Stack &s);
    int push(T);
    int pop(T &n);
    Stack &operator=(Stack &s);
    int isEmpty();
    int isFull();
    friend void viewContent(Stack s);
};

template <class T>
int Stack<T>::counter = 0;

template <class T>
Stack<T>::Stack(Stack<T> &myStk)
{
    top = myStk.top;
    size = myStk.size;
    ptr = new T[size];
    for (int i = 0; i < top; i++)
    {
        ptr[i] = myStk.ptr[i];
    }
    counter++;
}

template <class T>
int Stack<T>::push(T n)
{
    if (isFull())
    {
        return 0;
    }
    else
    {
        ptr[top] = n;
        top++;
        return 1;
    }
};

template <class T>
int Stack<T>::pop(T &data)
{
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        top--;
        data = ptr[top];
        return 1;
    }
}

template <class T>
Stack<T> &Stack<T>::operator=(Stack<T> &myS)
{
    if (ptr)
        delete[] ptr;
    top = myS.top;
    size = myS.size;
    ptr = new T[size];
    for (int i = 0; i < top; i++)
    {
        ptr[i] = myS.ptr[i];
    }
    return *this;
}

template <class T>
void viewContent(Stack<T> myS)
{
    for (int i = 0; i < myS.top; i++)
    {
        cout << myS.ptr[i] << " ";
    }
    cout << endl;
}

template <class T>
int Stack<T>::isFull()
{
	return top == size - 1 ? 1 : 0;
}

template <class T>
int Stack<T>::isEmpty()
{
    return top == 0 ? 1 : 0;
}
void main()
{
    int n;
    clrscr();
    Stack<int> s1(5);
    cout << "\nNo of Int Stacks is:" << Stack<int>::getCounter() << endl;
    s1.push(10);
    s1.push(3);
    s1.push(2);
    s1.pop(n);
    cout << "\n1st integer: " << n << endl;
    s1.pop(n);
    cout << "\n2nd integer: " << n << endl;
    Stack<char> s2;
    char nc;
    cout << "\nNo of Char Stacks is:" << Stack<char>::getCounter() << endl;
    s2.push('q');
    s2.push('r');
    s2.push('s');
    viewContent(s2);
    s2.pop(nc);
    cout << "\n1st character: " << nc << endl;
    s2.pop(nc);
    cout << "\n2nd character: " << nc << endl;
    getch();
}