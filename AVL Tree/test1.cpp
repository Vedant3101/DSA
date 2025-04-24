#include<iostream>
using namespace std;

class Node
{
    int data;
    int height;
    Node *left, *right;
    public:

    Node()
    {
        left = right = nullptr;
    }
    Node(int d)
    {
        data = d;
        height = 1; 
        left = right = nullptr;
    }
    void insert(int d);
    void deleteNode(int d);
    int nodeHeight(Node *p);
    int balanceFactor(Node *p);

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

    root -> height = Node::nodeHeight(root);
    int balance = Node::balanceFactor(root);

    if(balance > 1 && d < root->left->data)
    {
        cout << "Left Left Case" << endl;
        Node *temp = root->left;
        root->left = temp->right;
        temp->right = root;
        root = temp;
    }
    else if(balance < -1 && d > root->right->data)
    {
        cout << "Right Right Case" << endl;
        Node *temp = root->right;
        root->right = temp->left;
        temp->left = root;
        root = temp;
    }
    else if(balance > 1 && d > root->left->data)
    {
        cout << "Left Right Case" << endl;
        Node *temp = root->left;
        root->left = temp->right;
        temp->right = root->left;
        
        Node *temp2 = root->left;
        root->left = temp2->right;
        temp2->right = root;
        root = temp2; 
    }
    else if(balance < -1 && d < root->right->data)
    {
        cout << "Right Left Case" << endl;
        Node *temp = root->right;
        root->right = temp->left;
        temp->left = root->right;

        Node *temp2 = root->right;
        root->right = temp2->left;
        temp2->left = root;
        root = temp2; 
    }
    
}

int Node::nodeHeight(Node *p)
{
    int hl,hr;
    if(p == nullptr)
    {
        return 0;
    }
    hl = nodeHeight(p->left);   
    hr = nodeHeight(p->right);

    return (hl > hr) ? hl + 1 : hr + 1;
}

int Node::balanceFactor(Node *p)
{
    if(p == nullptr)
    {
        return 0;
    }
    return nodeHeight(p->left) - nodeHeight(p->right);
}