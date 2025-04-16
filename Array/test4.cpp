#include <iostream>
using namespace std;

class Array
{
public:
    int *A;
    int size;
    int length;

    // Constructor
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    // Destructor
    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Merge(Array &arr1, Array &arr2);
};

// Display elements of the array
void Array::Display()
{
    cout << "Elements are: ";
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Merge two sorted arrays into the current array
void Array::Merge(Array &arr1, Array &arr2)
{
    int i = 0, j = 0, k = 0;
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            A[k++] = arr1.A[i++];
        else
            A[k++] = arr2.A[j++];
    }
    while (i < arr1.length)
        A[k++] = arr1.A[i++];
    while (j < arr2.length)
        A[k++] = arr2.A[j++];
    length = k;
}

int main()
{
    Array arr1(20);
    arr1.A[0] = 1;
    arr1.A[1] = 3;
    arr1.A[2] = 5;
    arr1.A[3] = 7;
    arr1.A[4] = 9;
    arr1.length = 5;
    arr1.Display();

    Array arr2(20);
    arr2.A[0] = 2;
    arr2.A[1] = 4;
    arr2.A[2] = 6;
    arr2.A[3] = 8;
    arr2.A[4] = 10;
    arr2.length = 5;
    arr2.Display();

    Array arr3(20);
    arr3.Merge(arr1, arr2);

    cout << "Merged array: ";
    arr3.Display();

    return 0;
}
