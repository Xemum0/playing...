#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int items[5];
    int front, rear;

public:
    CircularQueue()
    {
        for (size_t i = 0; i < 5; i++)
        {
            items[i] = 0;
        }
        front = rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % 5 == front);
    }

    void enqueue(int data)
    {
        if (isFull())
            cout << "Queue is full" << endl;
        else if (isEmpty())
        {
            front = rear = 0;
            items[0] = data;
        }
        else
        {
            rear = (rear + 1) % 5;
            items[rear] = data;
        }
    }

    int dequeue()
    {
        if (isEmpty())
            return -1;
        else if (rear == front)
        {
            int data = items[rear];
            rear = front = -1;
            return data;
        }
        else
        {
            int data = items[front];
            items[front] = 0;
            front = (front + 1) % 5;
            return data;
        }
    }

    void display()
    {
        for (size_t i = 0; i < 5; i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue Q1;
    int s;
    for (size_t i = 0; i < 5; i++)
    {
        cin >> s;
        Q1.enqueue(s);
    }
    Q1.display();
    cout << Q1.dequeue() << endl;
    cout << Q1.dequeue() << endl;
    cout << Q1.dequeue() << endl;
    cin >> s;
    Q1.enqueue(s);
    cin >> s;
    Q1.enqueue(s);
    Q1.display();
    cout << Q1.dequeue() << endl;
    cout << Q1.dequeue() << endl;
    cout << Q1.dequeue() << endl;
    cout << Q1.dequeue() << endl;
    return 0;
}
