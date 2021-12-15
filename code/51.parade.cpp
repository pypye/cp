//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1005
using namespace std;
#define bit(x, i) ((x >> i) & 1)
#define list(x, v) &x - &v[0]
int bin = 1023;
int n, m, h[maxn], p[maxn][11], f[1 << 11], dp[maxn][1 << 11];
vector <int> a[maxn], b[maxn], c[maxn], qu;
vector <pair <int, int>> cnt[maxn];
void dfs(int u){
    for(auto v : a[u])
        if(p[u][0] != v){
            h[v] = h[u] + 1;
            p[v][0] = u;
            FOR(i, 1, 10) p[v][i] = p[p[v][i-1]][i-1];
            dfs(v);
            for(auto w : a[v]) b[u].push_back(w);
            b[u].push_back(v);
        }
}

void Remove(int u, int par){
    for(auto &v : a[u]){
        if(v != par){
            c[u].push_back(v);
            Remove(v, u);
        }
    }
}

int lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    int d = h[v] - h[u];
    FOR(i, 0, 10) if(bit(d, i)) v = p[v][i];
    FORR(i, 10, 0)
        if(p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    return u != v ? p[u][0] : u;
}

int FindPar(int u, int v){
    if(u == v) return u;
    int d = h[u] - h[v] - 1;
    FOR(i, 0, 10) if(bit(d, i)) u = p[u][i];
    return u;
}

void dfs2(int u){
    for(auto v : a[u]) dfs2(v);
    memset(f, 0, sizeof f);
    qu.clear();
    for(auto &v : a[u]){
        int i = list(v, a[u]);
        if(dp[v][v]) qu.push_back(1 << i), f[1 << i] = dp[v][v];
    }
    for(auto v : cnt[u]){
        int p = FindPar(v.first, u);
        int q = FindPar(v.second, u);
        int sp = -1, sq = -1, state = 0;
        for(auto &x : a[u]){
            int i = list(x, a[u]);
            if(p == x) sp = i;
            else if(q == x) sq = i;
        }
        if(sp != -1) state += (1 << sp);
        if(sq != -1) state += (1 << sq);
        if(!f[state]) qu.push_back(state);
        f[state] = max(f[state], dp[p][v.first] + dp[q][v.second] + 1);
    }
    FOR(x, 1, bin){
        FOR(i, 0, 9)
            if(bit(x, i)) f[x] = max(f[x], f[x ^ (1 << i)]);
        for(auto y : qu)
            if((x & y) == y) f[x] = max(f[x], f[x ^ y] + f[y]);
    }
    for(auto &v : a[u]){
        int i = list(v, a[u]);
        for(auto x : b[v]) dp[u][x] = f[bin ^ (1 << i)] + dp[v][x];
        dp[u][v] = f[bin ^ (1 << i)] + dp[v][v];
    }
    dp[u][u] = f[bin];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("parade.inp");
//    ofstream cout("parade.out");
    cin >> n >> m;
    FOR(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    Remove(1, -1);
    FOR(i, 0, n) a[i] = c[i];
    while(m--){
        int u, v;
        cin >> u >> v;
        cnt[lca(u, v)].emplace_back(u, v);
    }
    dfs2(1);
    cout << dp[1][1];
}
