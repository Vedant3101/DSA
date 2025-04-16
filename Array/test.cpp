#include<iostream>
using namespace std;

#include<conio.h>
/*
int func(int n, int m)
{
   if (n == 0)
      return 0;
   else
   if (m == 0)
      return 1;
   else
      return n * func(n, m - 1);
   
   
}
*/
/*
float func(int n)
{
   float r;
   if (n == 0)
      return 0;
   if (n == 1)
      return 1;
   else
      return func(n- 2) + func(n - 1);
   
} */
      

int func(int n)
{
   int t1 = 1;
   int t0 = 0;
   int s;
   for(int i = 2; i < n ; i++)
   {  
      s = t0 + t1;
      t0 = t1;
      t1 = s;
   }
   return s;
} 
 int main()
 {
    int x = 4;
    cout<<func(x);
    return 0;
 }


