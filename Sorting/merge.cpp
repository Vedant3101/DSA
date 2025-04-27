 #include <iostream>
 using namespace std;


    void merge(int arr[], int low, int mid, int high) 
    {
        int i = low;
        int j = mid + 1;
        int k = low;
        int B[100];

        while( i <= mid && j <= high) 
        {
            if(arr[i] < arr[j]) 
            {
                B[k++] = arr[i++];
            } 
            else 
            {
                B[k++] = arr[j++];
            }
        }
        while(i <= mid) 
        {
            B[k++] = arr[i++];
        }
        while(j <= high) 
        {
            B[k++] = arr[j++];
        }

        for(int i = low; i <= high; i++) 
        {
            arr[i] = B[i];
        }
    }

    void mergeSort(int arr[], int low, int high) 
    {
        if(low < high) 
        {
            int mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
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
        mergeSort(arr, 0, n - 1);
        cout << "Sorted array: \n";
        printArray(arr, n);
        return 0;
    }
