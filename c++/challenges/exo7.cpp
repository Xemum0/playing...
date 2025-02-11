//check if string is valid
//The types of characters allowed in the string are
// parentheses, curly brackets, and square brackets.
#include<iostream>
#include<string>
using namespace std;



/*
with fun
#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    if (isValid(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is invalid." << endl;
    }
    return 0;
}

*/
class Node {
public:
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(char data) {
        Node* new_node = new Node;
        new_node->data = data;
        if (top == NULL) {
            top = new_node;
            new_node->next = NULL;
        }
        else {
            new_node->next = top;
            top = new_node;
        }
    }

    char pop() {
        if (top == NULL) {
            return ' ';
        }
        else {
            Node* temp = top;
            top = temp->next;
            char c = temp->data;
            delete temp;
            return c;
        }
    }

    char peek() {
        if (top == NULL) {
            return ' ';
        }
        else {
            return top->data;
        }
    }

    bool is_empty() {
        return (top == NULL);
    }
};

int main() {
    Stack stack;
    string str;
    cout << "Enter the string: ";
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
            stack.push(str[i]);
        }
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
            if (stack.is_empty() || (str[i] - stack.peek() > 2 || str[i] - stack.peek() < 1)) {
                cout << "This is not a valid string." << endl;
                return 0;
            }
            stack.pop();
        }
    }
    if (stack.is_empty()) {
        cout << "This is a valid string." << endl;
    }
    else {
        cout << "This is not a valid string." << endl;
    }
    return 0;
}
