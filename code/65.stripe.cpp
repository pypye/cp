#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1005
using namespace std;
int n, k;
long long a[maxn], f[maxn][maxn], sum[maxn], ans, s[maxn][maxn], mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("stripe.inp");
    ofstream cout("stripe.out");
    cin >> n >> k;
    FOR(i, 1, k) cin >> a[i];
    sum[1] = a[1];
    FOR(i, 2, k-1) sum[i] = (sum[i-1] + a[i] + 1) % mod;
    sum[k] = (sum[k-1] + a[k]) % mod;
    FOR(i, a[1], n) f[1][i] = 1, s[1][i] = (s[1][i-1] + f[1][i]) % mod;
    FOR(i, 2, k){
        FOR(j, sum[i-1] + a[i] + 1, n)
            {
                f[i][j] = (f[i][j] + s[i-1][j-a[i]-1]) % mod;
            }
            //FOR(x, 1, j - a[i] - 1)
                //f[i][j] += f[i-1][x];
        FOR(j, 1, n) s[i][j] = (s[i][j-1] + f[i][j]) % mod;
    }
    FOR(i, 1, n) ans = (ans + f[k][i]) % mod, ans %= mod;
    cout << ans;
}
