#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
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
    void insert(int index, int x);
    void deleteNode(int index);
       
};

LinkedList::LinkedList(int A[], int n)
{
    int i;
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head -> next = head;
    last = head;

    for(i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}


void LinkedList::display()
{
    Node *p = head;
    do 
    {
        cout << p->data << " ";
        p = p->next;
    } while(p != head);
}

void LinkedList::insert(int index, int x)
{
    Node *t, *p;
    if(index == 1)
    {
        t = new Node;
        t-> data = x;
        if(head == nullptr)
        {
            head =t;
            head->next = head;
        }
        else
        {
            p = head;
            while(p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
        
    }
    else{
        p = head;   
        for (int i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;    
        t -> next = p -> next;
        p -> next = t;

    }
}

void LinkedList::deleteNode(int index)
{
    Node *p, *t;
    if(index == 1)
    {
        p = head;
        while(p->next != head)
        {
            p = p->next;
        }
        if(head == p)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else{
        p = head;
        for (int i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        t = p->next;
        p->next = t->next;
        delete t;
    }

}


LinkedList::~LinkedList()
{
    if (head == nullptr)
    {
        return;
    }
    Node *p = head;
    while (p != head)
    {
        Node *q = p;
        p = p->next;
        delete q;
    }
}



int main()
{
    int A[] = {2, 4, 6, 8, 10};
    LinkedList list(A, 5);
    list.display();
    cout << endl;
    list.insert(1, 1);
    list.display();
    cout << endl;
    list.insert(3, 3);  
    list.display();
    cout << endl;
    list.deleteNode(1);
    list.display();
    return 0;
}
