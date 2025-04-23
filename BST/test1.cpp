#include<iostream>
using namespace std;

class Node
{
    int data;
    Node *left, *right;
    public:

    Node()
    {
        left = right = nullptr;
    }
    Node(int d)
    {
        data = d;
        left = right = nullptr;
    }
    void insert(int d);
    void inOrder(Node* p);
    void deleteNode(int d);

};

Node* root = nullptr;

void Node::insert(int d)
{
    Node *t = root;
    Node *r = nullptr;
    Node *p = new Node(d);
    if(root == nullptr)
    {
        root = p;
        return;
    }
    while (t != nullptr)
    {
        r = t;
        if(d < t->data)
        {
            t = t->left;
        }
        else if( d> t -> data)
        {
            t = t->right;
        }
        else
        {
            cout << "Duplicate value" << endl;
            return;
        }
    }
    if(d < r->data)
    {
        r->left = p;
    }
    else
    {
        r->right = p;
    } 
}

void Node::inOrder(Node* p)
{
    if(p)
    {
        inOrder(p->left);
        cout << p->data << " ";
        inOrder(p->right);
    }
}

void Node::deleteNode(int d)
{
    Node *t = root;
    Node *r = nullptr;
    while (t != nullptr)
    {
        if(d < t->data)
        {
            r = t;
            t = t->left;
        }
        else if( d> t -> data)
        {
            r = t;
            t = t->right;
        }
        else
        {
            break;
        }
    }
    if(t == nullptr)
    {
        cout << "Element not found" << endl;
        return;
    }
    while(t != nullptr)
    {
        if(t->left == nullptr && t->right == nullptr)
        {
            if(r->left == t)
            {
                r->left = nullptr;
            }
            else
            {
                r->right = nullptr;
            }
            delete t;
        }
        else if(t->left == nullptr || t->right == nullptr)
        {
            Node *temp = (t->left != nullptr) ? t->left : t->right;
            if(r->left == t)
            {
                r->left = temp;
            }
            else
            {
                r->right = temp;
            }
            delete t;
        }
        else
        {
            Node *temp = t->right;
            while (temp && temp->left != nullptr)
            {
                temp = temp->left;
            }
            t->data = temp->data;
            deleteNode(temp->data);
        }
    }
    
}

int main()
{
    Node n;
    int d;
    while (d != -1)
    {
        cout << "Enter the data to be inserted in the BST (-1 to stop): " << endl;
        cin >> d;
        if(d < 0)
            break;
        n.insert(d);
    }

    cout << "Inorder Traversal of the BST: " << endl;
    n.inOrder(root);
    return 0;
}