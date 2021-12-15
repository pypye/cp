//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 800005

using namespace std;
int n, a[maxn], b[maxn], dp[2005][2005];
struct stock{
    int F, S, stonk;
}c[maxn];
bool comp(stock A, stock B){
    return A.stonk > B.stonk;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("acm.inp", "r", stdin);
    freopen("acm.out", "w", stdout);
    cin >> n;
    if(n <= 1000){
        n *= 2;
        FOR(i, 1, n) cin >> a[i] >> b[i];
        FOR(i, 1, n) dp[i][0] = dp[i-1][0] + a[i];
        FOR(i, 1, n) dp[i][i] = dp[i-1][i-1] + b[i];
        FOR(i, 2, n)
            FOR(j, 1, i-1){
                dp[i][j] = min(dp[i-1][j] + a[i], dp[i-1][j-1] + b[i]);
            }
        cout << dp[n][n/2] << '\n';
    }
    else{
        int ans = 0;
        n *= 2;
        FOR(i, 1, n) cin >> c[i].F >> c[i].S, c[i].stonk = c[i].S - c[i].F;
        sort(c+1, c+n+1, comp);
        FOR(i, 1, n/2) ans += c[i].F;
        FOR(i, n/2+1, n) ans += c[i].S;
        cout << ans;
    }

}
