#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) 
{
    int pivot = arr[low];
    int i = low, j = high;
    do
    {
        do 
        {
            i++;

        } while (arr[i] <= pivot);

        do 
        {
            j--;

        } while (arr[j] > pivot);

        if (i < j) 
        {
            swap(arr[i], arr[j]);
        }
    } while (i < j);
    swap(arr[low], arr[j]);
    return j;  
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}