#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("triangle.inp", "r", stdin);
    freopen("triangle.out", "w", stdout);
    double a, b, c;
    cin >> a >> b >> c;
    double x = (a + b + c) / 2;
    double area = sqrt(x * (x-a) * (x-b) * (x-c));
    cout << fixed << setprecision(2) << a + b + c << " " << area;

}
