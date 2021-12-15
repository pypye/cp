#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, k, dp[maxn], f[maxn];
string s, t;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("bw.inp", "r", stdin);
    //freopen("bw.out", "w", stdout);
    cin >> n >> k >> s >> t;
    deque <pair <int, int>> d;
    FOR(i, 2, n) f[i] = f[i-1] + (t[i-2] != t[i-1]);
    d.emplace_back(1, 0);
    FOR(i, 1, n){
        if(s[i-1] == t[i-1]) dp[i] = dp[i-1];
        else dp[i] = min(dp[i-1],d.front().first + f[i] >> 1) + 1;
        int fix = dp[i] * 2 - f[i+1] + 1;
        while (!d.empty() && d.back().first >= fix) d.pop_back();
        d.emplace_back(fix,i);
        if (d.front().second + k <= i) d.pop_front();
    }
    cout << dp[n];
}
