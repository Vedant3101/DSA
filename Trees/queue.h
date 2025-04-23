#include <iostream>
using namespace std;

class Node;

class Queue 
{
private:
    int size, front, rear;
    Node** arr;
public:
    Queue() {
        size = 5;
        front = rear = -1;
        arr = new Node*[size];
    }
    Queue(int s) {
        size = s;
        front = rear = -1;
        arr = new Node*[size];
    }
    void enqueue(Node* value) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
    }
    Node* dequeue() {
        if (front == rear) {
            cout << "Queue is empty\n";
            return nullptr;
        }
        front = (front + 1) % size;
        return arr[front];
    }
    int isEmpty() {
        return front == rear;
    }
    ~Queue() {
        delete[] arr;
    }
};

class Node {
public:
    int data;
    Node* lchild;
    Node* rchild;
};
