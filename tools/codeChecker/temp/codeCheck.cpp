#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long mul (long long x, long long y) {
    long long c = 0;
    for(;y;y/=2,x += x) {
        x %= mod;
        if(y & 1) {
            c += x;
            c %= mod;
        }
    }
    return c;
}

int main(){
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
    long long n, c2n, x;
    cin >> n >> x;
    c2n = mul(n, (2*n - 1));
    if(n == 1) {
        c2n -= (2 * n - 1) % mod;
        c2n %= mod;
        if(c2n < 0) c2n += mod;
        cout << c2n;
    } else {
        c2n -= ((2 * n - 1) + (n-x)) % mod;
        c2n %= mod;
        if(c2n < 0) c2n += mod;
        cout << c2n;
    }
    return 0;

}