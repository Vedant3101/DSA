#include<iostream>
using namespace std;

void shellSort(int arr[], int n)
{
    int gap = n / 2;
    for (gap = n/2; gap > 0; gap/=2)
    {
        for ( int i = gap; i < n ; i++)
        {
            int x = arr[i];
            int j = i - gap;
            while( j >= 0 && arr[j] > x)
            {
                arr[j + gap] = arr[j];
                j = j - gap;
            }
            arr[j + gap] = x;
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
    shellSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
