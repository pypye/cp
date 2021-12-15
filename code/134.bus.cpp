#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
using namespace std;
int q;
long long a, b, t1, t2, c;
pair extended_gcd(long long a, long long b){
    long long gcd = __gcd(a, b);
    long long m = a, n = b;
    long long xm = 1, xn = 0;
    while(n){
        long long q = m/n;
        long long r = m - q*n;
        long long xr = xm - q * xn;
        m = n; n = r;
        xm = xn; xn = xr;
    }
    return {xm * c/gcd, ((gcd - a * xm)/b) * c/gcd};

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("bus.inp");
    //ofstream cout("bus.out");
    cin >> q;
    while(q--){
        cin >> a >> b >> t1 >> t2;
        if(t1 < t2){
            swap(t1, t2);
            swap(a, b);
        }
        c = t1 - t2;
        if(c % __gcd(a, b) != 0){
            cout << -1 << '\n';
            continue;
        }
        pair u = extended_gcd(a, b);
        long long r = a/u.first;
        long long k = a - u.first * r;
        cout << a * k + t1 << '\n';
    }
}
