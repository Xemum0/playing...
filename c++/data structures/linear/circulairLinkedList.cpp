#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Method to insert a new node at the beginning
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            newNode->next = newNode;
        }
        else
        {
            newNode->next = head;
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        head = newNode;
    }

    // Method to insert a new node at the end
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Method to delete a node with a given value
    void deleteNode(int value)
    {
        if (head == nullptr)
        {
            std::cout << "List is empty. Deletion not possible." << std::endl;
            return;
        }

        Node *curr = head;
        Node *prev = nullptr;
        while (curr->data != value)
        {
            if (curr->next == head)
            {
                std::cout << "Node with value " << value << " not found." << std::endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        if (curr == head && curr->next == head)
        {
            head = nullptr;
            delete curr;
        }
        else if (curr == head)
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
            delete curr;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
        }
    }

    // Method to display the circular linked list
    void display()
    {
        if (head == nullptr)
        {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node *temp = head;
        do
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};

int main()
{
    CircularLinkedList cll;

    cll.append(10);
    cll.append(20);
    cll.prepend(5);
    cll.append(30);

    std::cout << "Circular Linked List: ";
    cll.display();

    cll.deleteNode(20);
    std::cout << "After deleting 20: ";
    cll.display();

    return 0;
}
