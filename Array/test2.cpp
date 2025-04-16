#include<iostream>
using namespace std;

#include<conio.h>

int fact (int n)
{
    int result = 1;
    if (n == 0)
       return 1;
    for (int  i = 1; i < n; i++)
    {
        result = result * i;
    }
    return result;
}
int func(int x, int y)
{

    int t1, t2, t3;
    t1 = fact(x);
    t2 = fact(y);
    t3 = fact(x - y);
    return t1 / (t2 * t3);
}


 int main()
 {
    int n = 4;
    int r = 2;
    cout<<func(n, r);
    return 0;
 }


