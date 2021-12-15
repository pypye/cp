#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 10000005
using namespace std;
int n, a, b;
long long p[maxn], rev[maxn], mod = 1000000007, ans;
long long POW(long long x, long long k)
{
    if(k == 0) return 1;
    long long b = POW(x, k/2);
    b = (b * b) % mod;
    if(k & 1) b = (b * x) % mod;
    return b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("chiacay.inp", "r", stdin);
    freopen("chiacay.out", "w", stdout);
    cin >> n >> a >> b;
    p[0] = 1;
    FOR(i, 1, n) p[i] = (p[i-1] * i) % mod;
    rev[n] = POW(p[n], mod - 2);
    FORR(i, n-1, 1) rev[i] = (rev[i+1] * (i+1)) % mod;
    FOR(i, a, n-b) (ans += (((p[n] * rev[i]) % mod) * rev[n-i]) % mod) %= mod;
    cout << ans;
}
