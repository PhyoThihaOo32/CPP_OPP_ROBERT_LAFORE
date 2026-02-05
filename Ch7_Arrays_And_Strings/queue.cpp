/*
9.
A queue is a data storage device much like a stack. The difference is that in a
stack the last data item stored is the first one retrieved, while in a queue
the first data item stored is the first one retrieved. That is, a stack uses
a last-in-first-out (LIFO) approach, while a queue uses first-in-first-out (FIFO).
A queue is like a line of customers in a bank: the first one to join the queue is the first one served.
Rewrite the STACKARAY program from this chapter to incorporate a class called queue.
Besides a constructor, it should have two functions: one called put() to put a data item on the queue,
and one called get() to get data from the queue. These are equivalent to push() and pop() in the stack class.
*/

#include <iostream>
using namespace std;

class Queue
{
private:
    static const int SIZE = 10;
    int array[SIZE];
    int front;
    int rear;
    int count;

public:
    Queue() : front(0), rear(-1), count(0) {}

    void put(int value)
    {
        if (count == SIZE)
        {
            cout << "Queue Full." << endl;
            return;
        }

        array[++rear] = value;
        count++;
    }

    int pop()
    {
        if (count == 0)
        {
            cout << "Queue Empty." << endl;
            return -1;
        }

        int val = array[front++];
        count--;

        // Reset when queue becomes empty
        if (count == 0)
        {
            front = 0;
            rear = -1;
        }

        return val;
    }

    void print() const
    {
        for (int i = 0; i < count; i++)
            cout << array[front + i] << " ";
        cout << endl;
    }

    int getSize() const { return SIZE; }
};

int main()
{
    Queue que;

    for (int i = 0; i < que.getSize() - 1; i++)
        que.put(i + 1);

    que.print();

    for (int i = 0; i < que.getSize(); i++)
        cout << que.pop() << " ";

    que.put(100);

    return 0;
}