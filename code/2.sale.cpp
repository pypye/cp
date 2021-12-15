//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 1000005
using namespace std;
using Ar = int[maxn];
int n, m, k;
Ar d, g, p, r, dp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("sale.inp");
    ofstream cout("sale.out");
    cin >> n >> m >> k;
    FOR(i, 1, n) cin >> d[i];
    FOR(i, 1, m) cin >> g[i];
    FOR(i, 1, m) cin >> p[i];
    FOR(i, 1, k) cin >> r[i];
    memset(dp,60,sizeof dp);
    dp[0] = 0;
    r[k+1] = 1e9;
    d[0] = -1e9;
    FOR(i, 1, n){
        dp[i] = dp[i-1] + p[1];
        FOR(j, 1, m){
            int range = max(0, d[i] - g[j]);
            int x = upper_bound(d, d+n+1, range) - d - 1;
            int y = upper_bound(r, r+k+1, range) - r;
            int z = lower_bound(d, d+n+1, r[y]) - d - 1;
            dp[i] = min(dp[i], dp[x] + p[j]);
            if(z < 0) continue;
            dp[i] = min(dp[i], dp[z] + p[j] / 2);
        }
    }
    cout << dp[n];
}
