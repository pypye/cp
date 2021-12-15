#include <bits/stdc++.h>

using namespace std;
int a[5];
int main()
{
    freopen("max2.inp", "r", stdin);
    freopen("max2.out", "w", stdout);
    for(int i = 0; i < 5; i++) cin >> a[i];
    sort(a, a+5);
    cout << a[4] << " " << a[3];

}
