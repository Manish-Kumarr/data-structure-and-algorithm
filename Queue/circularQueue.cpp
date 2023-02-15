#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    Queue()
    {
        front = rear = 0;
        size = 5;
        Q = new int[size];
    }
    void push(int x);
    int pop();
    void display();
};

void Queue::push(int x)
{
    if ((rear + 1) % size == front)
        cout << "Queue is full" << endl;
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int Queue::pop()
{
    int x = -1;
    if (rear == front)
        return x;
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

void Queue::display()
{
    while (front != rear)
    {
        front = (front + 1) % size;
        cout << Q[front] << " ";
    }
}

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.push(1);
    q.push(2);
    q.display();
    return 0;
}
