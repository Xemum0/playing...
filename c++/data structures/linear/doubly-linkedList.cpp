#include <iostream>
using namespace std;

class Node {
public:
    Node* prev, * next;
    int data;
    Node(int data) : prev(nullptr), next(nullptr), data(data) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Check if node exists
    bool isNodeExist(Node* n) {
        Node* ptr = head;
        while (ptr != nullptr) {
            if (ptr == n) {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }

    void append(Node* n) {
        if (isNodeExist(n)) {
            cout << "Node already exists in the chain\n";
            return;
        }

        if (head == nullptr) {
            head = n;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
        }
        cout << "Node appended\n";
    }

    void prepend(Node* n) {
        if (isNodeExist(n)) {
            cout << "Node already exists in the chain\n";
            return;
        }

        if (head != nullptr) {
            n->next = head;
            head->prev = n;
        }
        head = n;
        cout << "Node prepended\n";
    }

    void insertNode(int pos, Node* n) {
        if (isNodeExist(n)) {
            cout << "Node already exists in the chain\n";
            return;
        }

        if (pos == 0) {
            if (head != nullptr) {
                n->next = head;
                head->prev = n;
            }
            head = n;
        }
        else {
            Node* temp = head;
            //starting indexing from 0
            for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }
            if (temp == nullptr || temp->next == nullptr) {
                append(n);
                return;
            }
            n->next = temp->next;
            n->prev = temp;
            temp->next->prev = n;
            temp->next = n;
        }
        cout << "Node inserted\n";
    }

    void deleting(Node* n) {
        if (!isNodeExist(n)) {
            cout << "Node does not exist\n";
            return;
        }

        if (n == head) {
            head = n->next;
        }
        else {
            n->prev->next = n->next;
            if (n->next != nullptr) {
                n->next->prev = n->prev;
            }
        }
        delete n;
        cout << "Node deleted\n";
    }

    void display() {
        Node* temp = head;
        cout << "Linked List:\n";
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DoublyLinkedList list;

    // Example usage
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    list.append(node1);
    list.append(node2);
    list.prepend(node3);
    list.display();
    list.deleting(node2);
    list.display();
    list.insertNode(0,node4);
        list.display();


    return 0;
}
