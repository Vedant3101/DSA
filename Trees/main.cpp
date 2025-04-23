#include <iostream>
#include "queue.h"
using namespace std;


class Tree {
public:
    Node* root;
    Tree() {
        root = nullptr;
    }
    void createTree();
    void preOrder(Node* p);
    void inOrder(Node* p);
    void postOrder(Node* p);
    void levelOrder(Node* p);
};

void Tree::createTree() {
    Node* p, *t;
    Queue q(100);
    int x;
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);
    while (!q.isEmpty()) {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(Node* p) {
    if (p) {
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void Tree::inOrder(Node* p) {
    if (p) {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

void Tree::postOrder(Node* p) {
    if (p) {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << " ";
    }
}

int height(Node* p) {
    int x = 0, y = 0;
    if (p == nullptr)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

void Tree::levelOrder(Node* p) {
    Queue q(100);
    cout << p->data << " ";
    q.enqueue(p);
    while (!q.isEmpty()) {
        p = q.dequeue();
        if (p->lchild) {
            cout << p->lchild->data << " ";
            q.enqueue(p->lchild);
        }
        if (p->rchild) {
            cout << p->rchild->data << " ";
            q.enqueue(p->rchild);
        }
    }
}

int main() {
    Tree t;
    t.createTree();
    cout << "PreOrder: ";
    t.preOrder(t.root);
    cout << "\nInOrder: ";
    t.inOrder(t.root);
    cout << "\nPostOrder: ";
    t.postOrder(t.root);
    cout << "\nLevelOrder: ";
    t.levelOrder(t.root);
    cout << "\nHeight: " << height(t.root) << endl;
    return 0;
}
