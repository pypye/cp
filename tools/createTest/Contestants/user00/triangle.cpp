#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
   double a,b,c;
   cin >> a ; cin >> b; cin >> c;
   if (a+b>c && a+c>b && c+b>a)
    {
    cout << fixed << setprecision(2) << a+b+c ;
    cout << fixed << setprecision(2) << sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a)/16);
    }
    else cout << " khong phai la tam giac";
    return 0;
}
