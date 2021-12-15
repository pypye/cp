#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, k, a[maxn], b[maxn], dp[maxn], ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("mooomoo.inp");
    ofstream cout("mooomoo.out");
    cin >> n >> k;
    FOR(i, 1, k) cin >> a[i];
    FOR(i, 1, maxn) dp[i] = 1e9;
    dp[0] = 0;
    FOR(i, 1, maxn)
        FOR(x, 1, k)
            if(i >= a[x]) dp[i] = min(dp[i], dp[i-a[x]] + 1);
    FOR(i, 1, n) cin >> b[i];
    ans = 0;
    ans += dp[b[1]];
    FOR(i, 2, n){
        int dis = b[i] - max(0, b[i-1] - 1);
        ans += dp[dis];
    }
    if(ans >= 1e9) cout << -1;
    else cout << ans;
}
