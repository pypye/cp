#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, m, a[5005], c[maxn], f[18][maxn], dp[5005];
int getmin(int u, int v){
    int k = log2(v-u+1);
    return min(f[k][u], f[k][v - (1 << k) + 1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("market.inp");
    ofstream cout("market.out");
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i], dp[i] = 1e9;
    sort(a+1, a+n+1);
    FOR(i, 1, m) cin >> c[i];
    FORR(i, m-1, 1) c[i] = min(c[i+1], c[i]);
    FOR(i, 1, n){
        FOR(j, 1, i)
            dp[i] = min(dp[i], dp[j-1] + c[a[i] - a[j] + 1]);
    }
    cout << dp[n];
}
