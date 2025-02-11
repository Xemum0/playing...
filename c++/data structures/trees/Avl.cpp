#include <iostream>
using namespace std;
#define globalSpace 5

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int po)
    {
        data = po;
        left = NULL;
        right = NULL;
    }
};
class AvlTree
{
public:
    Node *root;

    AvlTree()
    {
        root = NULL;
    }
    //..................primary func..............................

    int height(Node *r)
    {
        if (r == NULL)
            return -1;
        else
        {

            int left = height(r->left);
            int right = height(r->right);
            if (left > right)
                return (left + 1);
            else
                return (right + 1);
        }
    }
    int getbalanceFactor(Node *r)
    {
        if (r == NULL)
            return -1;
        else
            return (height(r->left) - height(r->right));
    }
    Node *leftrot(Node *r)
    {
        Node *x = r->right;
        Node *temp = x->left;
        x->left = r;
        r->right = temp;
        return x;
    }
    Node *rightrot(Node *r)
    {
        Node *x = r->left;
        Node *temp = x->right;
        x->right = r;
        r->left = temp;
        return x;
    }

    //..................recursive insert..............................
    Node *Insert(Node *r, int item)
    {
        Node *newnode = new Node(item);
        if (r == NULL)
        {
            r = newnode;
        }
        else if (r->data > item)
        {
            r->left = Insert(r->left, item);
        }
        else if (r->data < item)
        {
            r->right = Insert(r->right, item);
        }
        else
        {
            cout << "no dup\n";
            return r;
        }

        int bf = getbalanceFactor(r);
        if (bf > 1 && r->left->data > newnode->data)
            return rightrot(r);
        else if (bf < -1 && r->right->data < newnode->data)
            return leftrot(r);
        else if (bf > 1 && r->left->data < newnode->data)
        {
            r->left = leftrot(r);
            return rightrot(r);
        }
        else if (bf < -1 && r->right->data > newnode->data)
        {
            r->right = rightrot(r);
            return leftrot(r);
        }
        return r;
    }

    void Insert(int item)
    {
        root = Insert(root, item);
    }
    //................................................
    void preorder(Node *r) // root -left-right
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->data << "\t";
        preorder(r->left);
        preorder(r->right);
    }

    void print2D(Node *r, int space)
    {
        if (r == NULL)
            return;
        space += globalSpace;
        print2D(r->right, space);
        cout << "\n";
        for (size_t i = globalSpace; i < space; i++)
        {
            cout << " ";
        }

        cout << r->data << "\n";
        print2D(r->left, space);
    }
    //................................................
    Node *search(Node *r, int item)
    {
        if (r == NULL)
            return NULL;
        else if (r->data == item)
            return r;
        else if (r->data > item)
            return search(r->left, item);
        else
            return search(r->right, item);
    }

    bool search(int key)
    {
        Node *temp = search(root, key);
        return temp == NULL ? false : true;
    }
    //................................................
    Node *minim(Node *r)
    {
        if (r == NULL)
            return NULL;
        else if (r->left == NULL)
            return r;
        else
        {
            return minim(r->left);
        }
    }
    Node *maxim(Node *r)
    {
        if (r == NULL)
            return NULL;
        else if (r->right == NULL)
            return r;
        else
        {
            return maxim(r->right);
        }
    }

    //................................................
    // biggst num on left called predecessor and least num
    // on right called  successor
    //     If there is a path from n1 to n2, then n1 is an
    // ancestor of n2 and n2 is a descendant of n1.
    // • If n1 ≠ n2, then n1 is a proper ancestor of n2
    // and n2 is a proper descendant of n1.
    Node *Deletepre(Node *r, int key)
    {
        if (r == NULL) // Empty Tree
            return NULL;
        if (key < r->data) // Item exists in left sub tree
            r->left = Deletepre(r->left, key);
        else if (key > r->data) // item exists in right sub tree
            r->right = Deletepre(r->right, key);
        else // Found the node to delete
        {
            if (r->left == NULL && r->right == NULL) // leaf node
            {
                delete r;
                r = NULL;
            }
            else if (r->left != NULL && r->right == NULL) // one child on the left
            {
                Node *temp = r;
                r = r->left;
                delete temp;
            }
            else if (r->left == NULL && r->right != NULL) // one child on the right
            {
                Node *temp = r;
                r = r->right;
                delete temp;
            }
            else // node has two children
            {
                Node *predecessor = r->left;
                while (predecessor->right != NULL)
                    predecessor = predecessor->right;
                r->data = predecessor->data;
                r->left = Deletepre(r->left, predecessor->data);
            }
        }
    
        int bf = getbalanceFactor(r);
        if (bf == 2 && getbalanceFactor(r->left) >= 0)
            return rightrot(r);
        else if (bf == 2 && getbalanceFactor(r->left) == -1)
        {
            r->left = leftrot(r);
            return rightrot(r);
        }
        else if (bf == -2 && getbalanceFactor(r->right) <= 0)
        {
            return leftrot(r);
        }
        else if (bf == -2 && getbalanceFactor(r->right) == 1)
        {
            r->right = rightrot(r);
            return leftrot(r);
        }
        return r;
    }

    Node *Deletesuc(Node *r, int key)
    {
        if (r == NULL) // Empty Tree
            return NULL;
        if (key < r->data) // Item exists in left sub tree
            r->left = Deletesuc(r->left, key);
        else if (key > r->data) // item exists in right sub tree
            r->right = Deletesuc(r->right, key);
        else // Found the node to delete
        {
            if (r->left == NULL && r->right == NULL) // leaf node
            {
                delete r;
                r = NULL;
            }
            else if (r->left != NULL && r->right == NULL) // one child on the left
            {
                Node *temp = r;
                r = r->left;
                delete temp;
            }
            else if (r->left == NULL && r->right != NULL) // one child on the right
            {
                Node *temp = r;
                r = r->right;
                delete temp;
            }
            else // node has two children
            {
                Node *successor = r->right;
                while (successor->left != NULL)
                    successor = successor->left;
                r->data = successor->data;
                r->right = Deletesuc(r->right, successor->data);
            }
        }
        return r;
    }
    //................................................
};

int main()
{
    AvlTree tree;
    tree.Insert(45);
    tree.Insert(15);
    tree.Insert(79);
    tree.Insert(90);
    tree.Insert(10);
    tree.Insert(55);
    tree.Insert(20);
    tree.Insert(17);
    cout << "\n--------------------------------------------------------------------\n";
    cout << tree.height(tree.root) << endl;
    tree.preorder(tree.root);
    // cout<<"\n--------------------------------------------------------------------\n";
    // tree.inorder(tree.root);
    // cout<<"\n--------------------------------------------------------------------\n";
    // tree.postorder(tree.root);
    // cout<<"\n--------------------------------------------------------------------\n";
    Node *result = tree.Deletesuc(tree.root, 20);
    cout << "\n preorder After Delete 20 \n ";
    tree.print2D(result, 5);

    result = tree.Deletesuc(tree.root, 45);
    cout << "\n preorder After Delete 45 \n ";
    tree.preorder(result);

    return 0;
}