//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 100005

using namespace std;
int n;
long long sum[maxn], dp[maxn], gg[maxn], h[maxn], ans;
queue <int> q;
vector <pair <int, pair <int, int>>> a[maxn];

void dfs(int u, int par = -1){
    for(auto v : a[u]) if(v.F != par){
        if(dp[v.F] < min(dp[u], 1ll*v.S.S) - v.S.F){
            dp[v.F] = min(dp[u], 1ll*v.S.S) - v.S.F;
            dfs(v.F, u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("evacuation.inp");
    ofstream cout("evacuation.out");
    cin >> n;
    FOR(i, 1, n-1){
        int u, v, d, t;
        cin >> u >> v >> d >> t;
        a[u].push_back({v, {d, t}});
        a[v].push_back({u, {d, t}});
    }
    FOR(i, 1, n) dp[i] = -2e9;
    FOR(u, 1, n) if(a[u].size() == 1){
        dp[u] = 2e9;
        dfs(u);
    }
    FOR(i, 1, n) if(dp[i] >= 0) ans++;
    cout << ans;
}
