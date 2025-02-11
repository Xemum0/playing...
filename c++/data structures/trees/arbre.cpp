#include <iostream>
using namespace std;
#define globalSpace 5
/*
• A tree is a hierarchical data structure that organizes data elements, called nodes, by connecting them with links, called edges
• Node Types (Cont.)
o Root Node
• A node which has no parent
• 5 is the root node oLeaf Node
• A node which has no child
• 1, 3, 7, 9 are leaf nodes oInterior Node
• A node which is neither a root nor a leaf
• 2, 4, 6, 8 are interior nodes
Root
Nodes
• Height or Depth of Tree is of edges along longest path from the root to a leaf in that tree
• Tree with one node has height O

__Arbre de recherche binaire
• La valeur de l'enfant gauche est inférieure à la racine
• La valeur de l'enfant droit est supérieure ou égale à la racine
Avantages de l'arbre de recherche binaire
• La recherche d'un élément est facile car nous avons toujours un indice indiquant quel sous-arbre contient l'élément souhaité.
Par rapport aux array et aux listes chaînées, les opérations d'insertion et de suppression sont plus rapides dans BST(binary search tree).
*/

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
class binarySearchTree
{
public:
    Node *root;

    binarySearchTree()
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
        return r;
    }

    void Insert(int item)
    {
        root = Insert(root, item);
    }

    //..............insert not recursive---///
    void InsertnoRec(int data)
    {
        Node *new_node = new Node(data);
        if (root == NULL)
            root = new_node;
        else
        {
            Node *ptr = root;
            while (ptr != NULL)
            {
                if (ptr->data == new_node->data)
                    return;
                else if (ptr->data < new_node->data && (ptr->left != NULL))
                {
                    ptr->left = new_node;
                    break;
                }
                else if (ptr->data < new_node->data)
                {
                    ptr = ptr->left;
                }
                else if (ptr->data > new_node->data && (ptr->right != NULL))
                {
                    ptr->right = new_node;
                    break;
                }
                else
                    ptr = ptr->right;
            }
        }
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

    void inorder(Node *r) // left -root-right
    {
        if (r == NULL)
            return;
        inorder(r->left);
        cout << r->data << "\t";
        inorder(r->right);
    }
    void postorder(Node *r) // left -right-root
    {
        if (r == NULL)
            return;
        postorder(r->left);
        postorder(r->right);
        cout << r->data << "\t";
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
    // biggst num on left callsed predecessor and least num
    // on right called  successor
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

    void deleteLeaves(Node *&root)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        deleteLeaves(root->left);
        deleteLeaves(root->right);
    }

    //................................................
};

int main()
{
    binarySearchTree tree;
    tree.Insert(6);
    tree.Insert(2);
    tree.Insert(8);
    tree.Insert(1);
    tree.Insert(4);
    tree.Insert(3);
  tree.Deletesuc(tree.root,4);

    return 0;
}