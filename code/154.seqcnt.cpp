#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 5005

using namespace std;
int n, k, mod = 1000000007;
int f[maxn][maxn][2], g[maxn][maxn][2], ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("seqcnt.inp");
    cin >> n >> k;
    if(n == k) return cout << 1, 0;
    f[k][k][0] = f[k][k][1] = 1;
    g[k][k][0] = g[k][k][1] = 1;
    FOR(i, k+1, n){
        g[k][i][0] = (g[k][i-1][0] + f[k][i][0]) % mod;
        g[k][i][1] = (g[k][i-1][1] + f[k][i][1]) % mod;
    }
    FOR(i, k+1, n){
        FOR(j, 1, n)
            if(i >= j + k){
                (f[i][j][0] += g[i-j][j-1][1]) %= mod;
                (f[i][j][1] += g[i-j][n][0] - g[i-j][j][0]) %= mod;
            }
        FOR(j, 1, n){
            g[i][j][0] = (g[i][j-1][0] + f[i][j][0]) % mod;
            g[i][j][1] = (g[i][j-1][1] + f[i][j][1]) % mod;
        }
    }
    FOR(i, 1, n) ans = (ans + 1ll * f[n][i][0] + 1ll * f[n][i][1]) % mod;
    cout << ans;
}
