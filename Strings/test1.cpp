#include <iostream>
#include <cstring> 
using namespace std;

int main()
{
    char A[] = "pynthon";

    int i=0;
    int j = strlen(A) - 1;
    int temp;
    while (i < j)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j--;
    }
    cout << "Reversed string is: " << A << endl;


    

    char B[] = "racecar";
    i = 0;
    j = strlen(B) - 1;

    while (i < j)
    {
        if (B[i] != B[j])
        {
            cout << "Not a palindrome" << endl;
            return 0;
        }
        i++;
        j--;
    }
    cout << "Palindrome" << endl;

    char C[] = "hello";

    long int h = 0 , x;
    for (int i = 0; i < strlen(C); i++)
    {
        x = 1;
        x = x << (C[i] - 'a');
        if ((x & h) > 0)
        {
            cout <<C[i] <<" is duplicate"<< endl;
        }
        else
        {
            h = h | x;
        }
    }
    return 0;
}
