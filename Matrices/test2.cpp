#include <iostream>
using namespace std;

class LowerTriangle
{
    private:
        int n;
        int *A;

public:
    LowerTriangle()
    {
        n = 2;
        A = new int[n*(n + 1)/2];   
    }
    
    LowerTriangle(int n)
    {
        this->n = n;
        A = new int[n*(n + 1)/2];
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();

    ~LowerTriangle()
    {
        delete []A;
    }

};

void LowerTriangle::Set(int i, int j, int x)
{
    if (i >= j)
    {
        A[i*(i-1)/2 + (j - 1)] = x;
    }
}

int LowerTriangle::Get(int i, int j)
{
    if (i >= j)
    {
        return A[i*(i-1)/2 + (j - 1)];
    }
    return 0;
}

void LowerTriangle::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                cout << A[i*(i-1)/2 + j - 1] << " ";
            }
            else
            {
                cout << "0" << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int d;
    cout << "Enter the size of the matrix: ";
    cin >> d;
    LowerTriangle l(d);

    int x;
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            l.Set(i, j, x);
        }
    }
    l.Display();
    return 0;


}