#include <iostream>
using namespace std;

class Heap
{
    int *arr;
    int capacity;
    int heap_size;

    public:
    Heap(int c)
    {
        capacity = c;
        heap_size = 0;
        arr = new int[capacity];
    }
    ~Heap()
    {
        delete[] arr;
    }

    void insert(int n);
    void deleteNode(int d);
    void printHeap();
};

void Heap::insert(int n)
{
    int i = heap_size;
    arr[i] = n;
    heap_size++;

    while (i != 0 && arr[(i - 1) / 2] < arr[i])
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

}

void Heap::deleteNode(int index)
{
    if (heap_size <= 0 || index >= heap_size)
    {
        cout << "Invalid delete\n";
        return;
    }

    arr[index] = arr[heap_size - 1];
    heap_size--;

    int i = index;
    while (2 * i + 1 < heap_size)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap_size && arr[left] > arr[largest])
            largest = left;
        if (right < heap_size && arr[right] > arr[largest])
            largest = right;

        if (largest == i)
            break;

        swap(arr[i], arr[largest]);
        i = largest;
    }
}

void Heap::printHeap()
{
    cout << "Heap elements: ";
    for (int i = 0; i < heap_size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    Heap h(10);
    int d;
    while (true)
    {
        cout << "Enter the data to be inserted in the Heap (-1 to stop): " << endl;
        cin >> d;
        if(d < 0)
            break;
        h.insert(d);

    }
    h.printHeap();

    cout << "Enter the index of the node to be deleted: " << endl;
    cin >> d;
    h.deleteNode(d);
    h.printHeap();
    return 0;
}
