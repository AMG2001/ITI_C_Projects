#include <stdio.h>
#include <iostream.h>
#include <conio.h>

class Stack
{
private:
	int top;			// indicator to the top of stack
	int size;			// the max size of the stack
	int *ptr;			// the pointer to create and access the stack elements
	static int counter; // it is not allowed to initialize it here in C++

public:
	int isFull();  // functions using to check, they offer no service
	int isEmpty(); // to the outside world.
	static int getCounter()
	{
		return counter;
	}
	int push(int n);
	int pop(int &n);
	Stack() // The default constructor with stack size is 10 integers
	{
		top = 0; // initialize stack state
		size = 10;
		counter++;
		ptr = new int[size]; // Allocate the stack locations
		cout << "This is the default constructor" << endl;
	}
	Stack(int n) // The default constructor with stack size n integers
	{
		top = 0;
		size = n;
		counter++;
		ptr = new int[size];
		cout <<"This is a constructor with one parameter "<<endl;
	}
	~Stack()
	{
		delete[] ptr;
		size = 0;
		counter--;
		cout << "This is the destructor" << endl;
	}

	friend void viewContent(Stack s);
};

// static variable initialization
int Stack::counter = 0;

	int Stack::isFull()
{
	return (top == size);
}

int Stack::isEmpty()
{
	return (top == 0);
}

int Stack::push(int n)
{
	if (isFull())
		return 0;
	ptr[top] = n;
	top++;
	return 1;
}

void viewContent(Stack s)
{
	for (int i = 0; i < s.top; i++)
		cout <<"\n Element no ("<< i + 1 <<") = "<< s.ptr[i]<<endl;
}

int Stack::pop(int &n)
{
	if (isEmpty())
		return 0;
	top--;
	n = ptr[top];
	return 1;
}

int main()
{
    clrscr();
	cout <<"\nThe number of objects created = "<< Stack::getCounter()<<endl;
	Stack s1, s2(5);
	cout <<"\nThe number of objects created = "<< Stack::getCounter()<<endl;
	{
		Stack s3(10);
		cout <<"\nThe number of objects created = "<< Stack::getCounter()<<endl;
	}
	cout <<"\n the number of objects created = "<< Stack::getCounter()<<endl;
	/**
	 * Push in s2 4 Items :
	 */
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);
	// view 4 items of s2 obj .
	viewContent(s2);

	getch();
	return 0;
}