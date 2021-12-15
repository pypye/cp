//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 100005

using namespace std;
int n, m, ans, d[maxn];
pair <int, int> edge[maxn];
vector <pair <int, int>> a[maxn];
void Tfs(int u, int ban, int lim, int par = -1){
    for(auto v : a[u]){
        if(v.F != par && v.F != ban){
            ans += (v.S <= lim);
            Tfs(v.F, ban, lim, u);
        }
    }
}
void Pfs(int u, int lim, int par = -1){
    for(auto v : a[u]){
        if(v.F != par){
             d[v.F] = d[u] + (v.S <= lim);
             Pfs(v.F, lim, u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("network.inp", "r", stdin);
    freopen("network.out", "w", stdout);
    cin >> n >> m;
    FOR(i, 1, n-1){
        int u, v, w; cin >> u >> v >> w;
        a[u].emplace_back(v, w);
        a[v].emplace_back(u, w);
        edge[i] = {u, v};
    }
    while(m--){
        char ty; cin >> ty;
        if(ty == 'P'){
            int x, y, z; cin >> x >> y >> z;
            memset(d, 0, sizeof d);
            Pfs(x, z);
            cout << d[y] << '\n';
        }
        else{
            int x, y; cin >> x >> y;
            ans = 0;
            Tfs(edge[x].S, edge[x].F, y);
            cout << ans << '\n';
        }
    }
}
