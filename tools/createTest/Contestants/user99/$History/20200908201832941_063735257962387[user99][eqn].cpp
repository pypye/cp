#include <bits/stdc++.h>

using namespace std;
double a, b, c;
int main()
{
//    freopen("eqn.inp", "r", stdin);
//    freopen("eqn.out", "w", stdout);
    cin >> a >> b >> c;
    double delta = b*b - 4*a*c;
    if (a == 0) cout << fixed << setprecision(3) << -c/b;
    else{
        if (delta < 0) cout << "NO SOLUTION";
    else if (delta == 0) cout << fixed << setprecision(3) << -1.0*b / (2.0*a);
    else{
        double x = (-1.0*b + sqrt(delta)) / (2.0*a);
        double y = (-1.0*b - sqrt(delta)) / (2.0*a);
        if (x > y) cout << fixed << setprecision(3) << y << " " << x;
        else cout << fixed << setprecision(3) << x << " "<< y;
    }
    }

}
