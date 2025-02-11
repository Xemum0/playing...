#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head;
//........................................

void append(int);
void print();
string tostring(node *);
string itos(int);
void toarray(int arr[], node *);
void sorting(node *);
bool palindrom(node *, node *, int);
void removedup(node *);
void remove_Duplicates(node *head);
//........................................
int main()
{

    head = NULL;
    int x;

    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        append(x);
    }
    print();
    string s = tostring(head);
    cout << s << endl;
    return 0;
}

//........................................
void print()
{
    node *temp = head;
    cout << "your list is : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

//........................................

void append(int data)
{
    node *temp = new node;
    temp->data = data;

    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
        return;
    }
    node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    temp->next = NULL;
}

//........................................

string tostring(node *temp)
{
    if (temp == NULL)
        return "";
    string str = itos(temp->data);
    return str + tostring(temp->next);
}

string itos(int data)
{
    if (data == 0)
        return "";
    char c = data % 10 + 48;
    return itos(data / 10) + c;
}
//........................................
void toarray(int arr[], node *temp)
{
    int i = 0;
    while (temp != NULL)
    {
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }
}
//........................................
void sorting(node *head)
{
    bool flag = true;
    while (head != NULL && flag)
    {
        flag = false;
        node *ptr;
        for (ptr = head->next; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->data > head->data)
                swap(ptr->data, head->data);
            flag = true;
        }

        head = head->next;
    }
}
//........................................
bool palindrom(node *low, node *high, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        high = high->next;
    }
    if (low->data != high->data)
        return false;
    else if (low == high || high == low->next)
        return true;
    else
        return palindrom(low->next, head, size - 1);
}

//........................................

void removedup(node *header)
{
    while (header != 0)
    {
        node *tmp;
        for (tmp = header; tmp != NULL; tmp = tmp->next)
        {
            if (tmp->next->data == header->data)
            {
                node *temp1 = tmp->next->next;
                delete tmp->next;
                tmp->next = temp1;
            }
        }
        header = header->next;
    }
}
//........................................

void remove_Duplicates(node *head)
{
    node *current = head, *pick;

    while (current->next != NULL)
    {

        if (current->data == current->next->data)
        {
            pick = current->next->next;
            delete (current->next);
            current->next = pick;
        }
        else
        {
            current = current->next;
        }
    }
}