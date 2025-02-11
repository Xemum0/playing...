#include <iostream>
using namespace std;
// also called lifo:last in first out

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
class Stack
{
private:
    Node *top;

public:
    //...........................................
    Stack()
    {
        top = NULL;
    }
    //...........................................
    bool isempty()
    {
        return (top == NULL);
    }
    //...........................................
    void push(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        if (isempty())
        {
            top = temp;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
    }
    //...........................................
    int pop()
    {
        Node *temp = top->next;
        int x = top->data;
        delete top;
        top = temp;
        return x;
    }
    //...........................................
    int peek()
    {
        return top->data;
    }
    //...........................................
    bool search(int key)
    {
        Node *temp = top;
        while (temp != NULL)
        {
            if (temp->data == key)
                return true;
        }
        return false;
    }
    //...........................................
    bool isfull()
    {
        Node *ptr = new Node();
        if (ptr = NULL)
        {
            return true;
        }
        return false;
    }
    //...........................................
    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    Stack stack1;
    int x;
    for (int i = 0; i < 4; i++)
    {
        cout << "push an elem : ";
        cin >> x;
        stack1.push(x);
    }
    stack1.display();
    cout << "\n"
         << stack1.pop() << endl;
    stack1.display();

    return 0;
}
