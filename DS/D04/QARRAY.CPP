#include <iostream.h>
#include <conio.h>

class Queue
{
private:
    int *array;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int cap)
    {
        capacity = cap;
        array = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue()
    {
        delete[] array;
    }

    int isEmpty()
    {
        return size == 0;
    }

    int isFull()
    {
        return size == capacity;
    }

    void enqueue(int item)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = item;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1; // Return a special value to indicate an error
        }
        return array[front];
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
	clrscr();
	Queue myQueue(5); // Create a queue with capacity 5

	myQueue.enqueue(1);
	myQueue.enqueue(2);
	myQueue.enqueue(3);

	cout << "Size of the queue: " << myQueue.getSize() << endl;
	cout << "Front element: " << myQueue.peek() << endl;

	myQueue.dequeue();

	cout << "Size of the queue after dequeue: " << myQueue.getSize() << endl;
	getch();
    return 0;
}
