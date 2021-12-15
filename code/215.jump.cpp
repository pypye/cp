#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005
using namespace std;
int n, k;
long long g[maxn], rev[maxn], ans, mod = 1e9 + 7, M;
long long power(long long n, long long k){
    if(!k) return 1;
    long long b = power(n, k/2);
    b = (b * b) % mod;
    if(k & 1) return (b * n) % mod;
    return b;
}
long long ckn(int i, int j){
    return ((g[i] * rev[j]) % mod * rev[i-j]) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("jump.inp");
    ofstream cout("jump.out");
    cin >> n >> k >> M;
    g[0] = 1;
    FOR(i, 1, k) g[i] = (g[i-1] * i) % mod;
    rev[k] = power(g[k], mod-2);
    FORR(i, k-1, 1) rev[i] = (rev[i+1] * (i+1)) % mod;
    FOR(i, 0, k)
        if((k - 2 * i) % n == 0) ans = (ans + ckn(k, i)) % M;
    cout << ans;
}
