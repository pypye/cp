#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, m, k, c[maxn];
long long dp[maxn][1 << 6], ans;
vector <int> a[maxn];
int bit(int x, int u){
    return ((x >> u) & 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("colorpath.inp");
    ofstream cout("colorpath.out");
    cin >> n >> m >> k;
    FOR(i, 1, n) cin >> c[i];
    while(m--){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    FOR(u, 1, n) dp[u][1 << (c[u] - 1)] = 1;
    FOR(x, 0, (1 << k) - 1)
        FOR(u, 1, n)
            if(bit(x, c[u] - 1) == 1)
                for(auto v : a[u])
                    if(bit(x, c[v] - 1) == 0){
                        dp[v][x + (1 << (c[v] - 1))] += dp[u][x];
                    }
    FOR(x, 0, (1 << k) - 1)
        FOR(u, 1, n)
            ans += dp[u][x];
    cout << ans - n;
}
