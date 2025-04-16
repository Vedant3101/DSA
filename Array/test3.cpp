#include <iostream>
using namespace std;

class Array
{
public:
    int *A;
    int size;
    int length;

    // Constructor: Allocates memory dynamically
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    // Destructor: Frees allocated memory
    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Insert(int index, int x);
    void Delete(int index);
    void LinearSearch(int x);
    void BinarySearch(int x);
    void Get(int index);
    void Set(int index, int x);
    void Max();
    void Min();
    void SumAvg();
    void Reverse();
    void LeftShift();
    void InsertSorted(int x);
    void IsSorted();
};

// Display elements
void Array::Display()
{
    cout << "Elements are: ";
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

// Insert an element at index
void Array::Insert(int index, int x)
{
    if (index >= 0 && index <= length && length < size)
    {
        for (int i = length; i > index; i--)
            A[i] = A[i - 1];

        A[index] = x;
        length++;
    }
}

// Delete an element at index
void Array::Delete(int index)
{
    if (index >= 0 && index < length)
    {
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];

        length--;
    }
}

// Linear Search
void Array::LinearSearch(int x)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == x)
        {
            cout << "Element found at index: " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}

// Binary Search (Array must be sorted)
void Array::BinarySearch(int x)
{
    int l = 0, h = length - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (A[mid] == x)
        {
            cout << "Element found at index: " << mid << endl;
            return;
        }
        else if (A[mid] < x)
            l = mid + 1;
        else
            h = mid - 1;
    }
    cout << "Element not found" << endl;
}

// Get element at index
void Array::Get(int index)
{
    if (index >= 0 && index < length)
        cout << "Element at index " << index << " is: " << A[index] << endl;
}

// Set element at index
void Array::Set(int index, int x)
{
    if (index >= 0 && index < length)
        A[index] = x;
}

// Find maximum element
void Array::Max()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
        if (A[i] > max)
            max = A[i];

    cout << "Max element is: " << max << endl;
}

// Find minimum element
void Array::Min()
{
    int min = A[0];
    for (int i = 1; i < length; i++)
        if (A[i] < min)
            min = A[i];

    cout << "Min element is: " << min << endl;
}

// Sum and average of elements
void Array::SumAvg()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum += A[i];

    cout << "Sum of elements is: " << sum << endl;
    cout << "Average of elements is: " << (float)sum / length << endl;
}

// Reverse the array
void Array::Reverse()
{
    for (int i = 0, j = length - 1; i < j; i++, j--)
        swap(A[i], A[j]);
}

// Left shift array
void Array::LeftShift()
{
    for (int i = 0; i < length - 1; i++)
        A[i] = A[i + 1];

    A[length - 1] = 0;
}

// Insert element in a sorted array
void Array::InsertSorted(int x)
{
    if (length == size)
        return;

    int i = length - 1;
    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }

    A[i + 1] = x;
    length++;
}

// Check if array is sorted
void Array::IsSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            cout << "Array is not sorted" << endl;
            return;
        }
    }
    cout << "Array is sorted" << endl;
}

// Main function
int main()
{
    Array arr(10); // Create array with size 10

    // Insert some initial elements
    arr.Insert(0, 1);
    arr.Insert(1, 2);
    arr.Insert(2, 3);
    arr.Insert(3, 4);
    arr.Insert(4, 5);

    arr.Display();

    cout << "Enter the element and index to insert: ";
    int x, index;
    cin >> x >> index;
    arr.Insert(index, x);
    arr.Display();

    cout << "Enter the index to delete: ";
    cin >> index;
    arr.Delete(index);
    arr.Display();

    cout << "Enter the element to search (Linear): ";
    cin >> x;
    arr.LinearSearch(x);

    cout << "Enter the element to search (Binary): ";
    cin >> x;
    arr.BinarySearch(x);

    cout << "Enter the index to get: ";
    cin >> index;
    arr.Get(index);

    cout << "Enter the index and element to set: ";
    cin >> index >> x;
    arr.Set(index, x);
    arr.Display();

    arr.Max();
    arr.Min();
    arr.SumAvg();

    arr.InsertSorted(4);
    arr.Display();

    arr.IsSorted();

    return 0;
}
