#include<iostream>
using namespace std;

class Queue 
{
    private:
    int size, front, rear;
    int *arr;
    public:
    Queue()
    {
        size = 5;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    Queue(int s)
    {
        size = s;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void enqueue();
    void dequeue();
    void display();
    ~Queue()
    {
        delete[] arr;
    }
};

void Queue::enqueue()
{
    int value;
    cout << "Enter the value to be inserted: ";
    cin >> value;
    if (rear == size - 1)
    {
        cout<<"Queue is full\n";
        return;
    }
    else
    {
        rear++;
        arr[rear] = value;
    }
    
}

void Queue::dequeue()
{
    if (front == rear)
    {
        cout<<"Queue is empty\n";
        return;
    }
    else
    {
        front++;
    }
    cout << "Deleted element: " << arr[front] << endl;
}

void Queue::display()
{
    if (front == rear)
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front + 1; i <= rear; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    Queue q1(10);
    int choice;
    do
    {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                q1.enqueue();
                break;
            case 2:
                q1.dequeue();
                break;
            case 3:
                q1.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);
    return 0;
}

