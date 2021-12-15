//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define F first
#define S second
#define maxn 8005
using namespace std;
int n, q, c[maxn], d[maxn], p[18][maxn], h[maxn];
vector <pair> a[maxn];
void dfs(int u, int par){
    for(auto v : a[u])
        if(v.F != par){
            p[0][v.F] = u;
            h[v.F] = h[u] + 1;
            c[v.F] = c[u] + v.S;
            FOR(i, 0, 17) p[i][u] = p[i-1][p[i-1][u]];
            dfs(v.F, u);
        }
}
int lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    int dt = h[u] - h[v];
    FOR(i, 0, 17) if((dt >> i) & 1) v = p[v][i];
    FORR(i, 17, 0)
        if(p[v][i] != p[u][i]){
            v = p[v][i];
            u = p[u][i];
        }
    if(u != v) return p[0][u];
    return u;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("dquery.inp");
    //ofstream cout("dquery.out");
    cin >> n;
    FOR(i, 1, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].emplace_back(v, w);
        a[v].emplace_back(u, w);
    }
    dfs(1, -1);
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << c[u] + c[v] - 2 * c[lca(u, v)] << '\n';
    }
}
