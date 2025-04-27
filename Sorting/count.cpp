#include <iostream>
using namespace std;

int findMax(int arr[], int n) 
{
     int max = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n) 
{
    int max,i, j = 0;
    int *count;

    max = findMax(arr, n);
    count = new int[max + 1];

    for (i = 0; i <= max; i++) 
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) 
    {
        count[arr[i]]++;
    }

    while( i < max + 1) 
    {
        if (count[i] > 0) 
        {
            arr[j++] = i;
            count[i]--;
        } 
        else 
        {
            i++;
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
    countSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}