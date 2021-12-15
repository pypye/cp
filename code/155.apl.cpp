#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005

using namespace std;
int h1, h2, n, mod = 1e9 + 7;
long long g[maxn], rev[maxn];
long long power(long long n, int k){
    long long c = 1;
    for(; k; k /= 2,n = (n * n) % mod)
        if(k & 1) c = (c * n) % mod;
    return c;
}
int calc(int h1, int h2){
    if(h1 > h2) swap(h1, h2);
    int d = h2 - h1, ans = 0;
    FOR(a, 0, n){
        int b = d + a;
        int c = n - a - b;
        if(c < 0) continue;
        ans += (((((g[n] * rev[a]) % mod) * rev[b] % mod) * rev[c]) % mod);
        ans %= mod;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    ifstream cin("apl.inp");
//    ofstream cout("apl.out");
    cin >> h1 >> h2 >> n;
    g[0] = 1;
    FOR(i, 1, n) g[i] = (g[i-1] * i) % mod;
    rev[n] = power(g[n], mod - 2);
    FORR(i, n-1, 0) rev[i] = (rev[i+1] * (i+1)) % mod;
    cout << (calc(h1, h2) - calc(h1, -h2-2) + mod) % mod;
}
