#include <iostream>
using namespace std;
// also caled fifo first in first out

class Node
{
public:
    string data;
    Node *next;
    Node()
    {
        data = "";
        next = NULL;
    }
};
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    //.........................................
    bool isempty()
    {
        return (front == NULL);
    }
    //.........................................

    void enqueue(string data)
    {
        Node *temp = new Node;
        temp->data = data;
        if (rear == NULL)
        {
            rear = temp;
            front = temp;
            temp->next = NULL;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            temp->next = NULL;
        }
    }
    //.........................................
    void display()
    {
        if (front == NULL)
        {
            cout << "the queue is empty" << endl;
            return;
        }

        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    //.........................................
    string peek()
    {
        return front->data;
    }
    //.........................................
    string dequeue()
    {
        string s = "";
        if (front == NULL)
        {
            return s;
        }
        if (front == rear)
        {
            s = front->data;
            delete front;
            front = rear = NULL;
        }
        else
        {
            Node *temp = front->next;
            s = front->data;
            delete front;
            front = temp;
        }
        return s;
    }
    //.........................................
    bool isfound(string s)
    {
        Node *temp = front;
        while (temp != NULL)
        {
            if (temp->data == s)
                return true;
            temp = temp->next;
        }
        return false;
    }
    //.........................................
    void clear()
    {
        while (front != NULL)
        {
            Node *temp = front->next;
            delete front;
            front = temp;
        }
        rear = NULL;
    }
    //.........................................
    void clearothermethod()
    {
        while (!isempty())
        {
            dequeue();
        }
    }
};

int main()
{
    Queue queue1;
    string s;

    for (int i = 0; i < 4; i++)
    {
        cout << "enter : ";
        cin >> s;
        queue1.enqueue(s);
    }
    queue1.display();
    cout << queue1.dequeue() << endl;
    queue1.display();

    return 0;
}