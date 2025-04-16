#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node *head = nullptr;
Node *head1 = nullptr;
Node *head2 = nullptr;

void create(int A[], int n)
{
    int i;
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head -> next = nullptr;
    last = head;

    for(i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void create1(int A[], int n)
{
    int i;
    Node *t, *last;
    head1 = new Node;
    head1->data = A[0];
    head1 -> next = nullptr;
    last = head1;

    for(i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}



void display(Node *p)
{
    while(p) 
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int count( Node *p)
{
    int c = 0;
    while(p) 
    {
        p = p->next;
        c++;
    }
    return c;
}

int sum(Node* p)
{
    int sum = 0;
    while(p) 
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int max (Node *p)
{
    int max = 0;
    while(p)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

Node* search(Node *p, int key)
{
    while(p) 
    {
        if(p->data == key)
            return p;
        p = p->next;
    }
    return nullptr;
}

void insert(Node *p, int index, int x)
{
    if (index < 0 || index > count(p))
    {
        return;
    }
    Node *t = new Node;
    t -> data = x;
    if(index == 1)
    {
        t -> next = head;
        head = t;
    }
    else {
        for (int i = 1; i < index - 1; i++)
        {
            p = p -> next;
        }
        t -> next = p -> next;
        p -> next = t;
    }
}

void deleteNode(Node *p, int index)
{
    Node *q = nullptr;
    if (index < 0 || index > count(p))
    {
        return;
    }
    if (index == 0)
    {
        q = head;
        head = head -> next;
        delete q;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p -> next;
        }
        q -> next = p -> next;
        delete p;
    }
}

void sorted(Node *p)
{
    int x  = INT_MIN;
    while(p)
    {
        if (p -> data < x )
        {
            cout<<"Not Sorted";
            return;
        }
        x = p -> data;
        p = p -> next;
    }
    cout<<"Sorted";
    return;

}

void reverse(Node*p)
{
    Node *q = nullptr;
    Node *r = nullptr;
    while(p)
    {
        r= q;
        q = p;
        p = p -> next;
        q -> next = r;
    }
    head = q;
    cout<<"Reversed Linked List: ";
}

void merge (Node *p, Node *q)
{
    Node *last = nullptr;
    if (p -> data > q -> data)
    {
        head2= last = q;
        q = q -> next;
        head2 -> next = nullptr;
    }
    else 
    {
        head2 = last = p;
        p = p -> next;
        head2 -> next = nullptr;
    }
    while (p &&q)
    {
        if ( p -> data  > q -> data)
        {
            last -> next = q;
            last = q;
            q = q -> next;
            last -> next = nullptr;
        }
        else 
        {
            last -> next = p;
            last = p;
            p = p -> next;
            last -> next = nullptr;
        }
    }
    if (p) 
    {
        last -> next = p;
    }
    else 
    {
        last -> next = q;
    }
}

int main()
{
    int A[] = {2, 4, 6, 8, 10};
    create(A, 5);

    int B[] = {1, 3, 5, 7, 9};
    create1(B, 5);

    display(head);
    cout<<endl;

    cout<<count(head);
    cout<<endl;

    cout<<sum(head);
    cout<<endl;

    cout<<max(head);
    cout<<endl;
  
    cout<<search(head, 6);
    cout<<endl;

    insert(head, 2, 5);
    display(head);
    cout<<endl;


    deleteNode(head, 2);
    display(head);
    cout<<endl;

    sorted(head);
    cout<<endl;

    //reverse(head);
    //display(head);

    cout<<endl;
    cout<<"Merged Linked List: ";
    merge(head, head1);
    display(head2);
    cout<<endl;


    


}   




