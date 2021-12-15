//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005
using namespace std;
int n, k;
long long f[maxn], rev[maxn], mod = 1000000007, ans = 1;
long long pw(long long x, long long k){
    if(k == 0) return 1;
    long long b = pw(x, k/2);
    b = (b * b) % mod;
    if(k & 1) return (b * x) % mod;
    return b;
}
long long ckn(int n, int k){
    return ((f[n] * rev[k]) % mod * rev[n-k]) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("jfr.inp");
    ofstream cout("jfr.out");
    cin >> n >> k;
    n--;
    f[0] = 1;
    FOR(i, 1, n) f[i] = (f[i-1] * i) % mod;
    rev[n] = pw(f[n], mod - 2); rev[0] = 1;
    FORR(i, n-1, 1) rev[i] = (rev[i+1] * (i+1)) % mod;
    FOR(i, 1, k-1)
        ans = (ans + ckn(n, i)) % mod;
    cout << ans;
}
