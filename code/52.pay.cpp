#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, k, a[maxn], f[18][maxn];
long long dp[maxn], s[maxn];
int getmin(int u, int v){
    int k = log2(v-u+1);
    return min(f[k][u], f[k][v - (1 << k) + 1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("pay.inp");
    ofstream cout("pay.out");
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i], s[i] = s[i-1] + a[i], f[0][i] = a[i], dp[i] = 1e18;
    FOR(i, 1, 17)
        FOR(u, 1, n - (1 << i) + 1)
            f[i][u] = min(f[i-1][u], f[i-1][u + (1 << (i-1))]);
    FOR(i, 1, n){
        if(i < k) dp[i] = s[i];
        else{
            dp[i] = min(dp[i], dp[i-k] + s[i] - s[i-k] - getmin(i-k+1, i));
            dp[i] = min(dp[i], dp[i-1] + a[i]);
        }
    }
    cout << dp[n];
}
