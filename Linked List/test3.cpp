#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;

};

class LinkedList
{
    private:
    Node *head;
    public:
    LinkedList()
    {
        head = nullptr;
        
    }
    LinkedList(int A[], int n);
    ~LinkedList();
    void display();
    int count();
    void insert(int index, int x);
    void deleteNode(int index);
    void reverse();
};

LinkedList::LinkedList(int A[], int n)
{
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head -> next = nullptr;
    head -> prev = nullptr;
    last = head;

    for(int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void LinkedList::display()
{
    Node *p = head;
    while(p) 
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int LinkedList::count()
{
    int count = 0;
    Node *p = head;
    while(p) 
    {
        count++;
        p = p->next;
    }
    return count;
}

void LinkedList::insert(int index, int x)
{
    Node *p = head;
    if (index < 0 || index > count())
    {
        return;
    }
    Node *t = new Node;
    t -> data = x;
    if(index == 1)
    {
        if(head == nullptr)
        {
            head = t;
            head -> next = nullptr;
            head -> prev = nullptr;
        }
        else
        {
            t -> prev = nullptr;
            t -> next = head;
            head -> prev = t;
            head = t;
        }
    }
    else 
    {
        for (int i = 0; i < index - 2; i++)
        {
            p = p -> next;
        }
        t ->next = p-> next;
        t -> prev = p;
        if (p->next != nullptr)
        {
            p->next->prev = t;
        }
        p -> next = t;
    }
}

void LinkedList::deleteNode(int index)
{
    Node *p = head;
    if (index < 0 || index > count())
    {
        return;
    }
    if (index == 1)
    {
        head = head -> next;
        if(head != nullptr)
        {
            head -> prev = nullptr;
        }
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p -> next;
        }
        p -> prev -> next = p -> next;
        if(p->next != nullptr)
        {
            p->next -> prev = p -> prev;
        }
        delete p;
    }
}

void LinkedList::reverse()
{
    Node *p = head;
    Node *temp = nullptr;
    while(p != nullptr) 
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev;
    }
    if(temp != nullptr) 
    {
        head = temp->prev;
    }
}

LinkedList::~LinkedList()
{
    Node *p = head;
    while(p) {
        Node *temp = p;
        p = p->next;
        delete temp;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList list(A, 5);
    cout<<list.count();
    cout << endl;
    list.display();;
    cout << endl;
    list.insert(3, 10);
    list.display();
    cout << endl;
    list.deleteNode(3);
    list.display();
    cout << endl;
    list.reverse();
    list.display();
    return 0;
}

