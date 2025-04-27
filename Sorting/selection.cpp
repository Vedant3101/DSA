#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i,j,k;
    for (i = 0; i < n-1; i++)
    {
        for( j = k = i; j < n; j++)
        {
            if(arr[j] < arr[k])
            {
                k = j;
            }
        }
        if(k != i)
        {
            swap(arr[i], arr[k]);
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
        
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}