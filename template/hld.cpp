#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 100005
using namespace std;
using Array = int[maxn];
int n, m, block, cnt, p[maxn][18];
Array child, par, val, head, chain, node, in, out, h;
vector <pair <int, int>> a[maxn];
pair <int, int> b[maxn];
vector <int> s[4*maxn];
void dfs(int u){
    child[u] = 1;
    for(auto v : a[u])
        if(par[u] != v.F){
            par[v.F] = u;
            val[v.F] = v.S;
            h[v.F] = h[u] + 1;
            p[v.F][0] = u;
            FOR(i, 1, 17) p[v.F][i] = p[p[v.F][i-1]][i-1];
            dfs(v.F);
            child[u] += child[v.F];
        }
}
void hld(int u){
    if(!head[block]) head[block] = u;
    chain[u] = block;
    in[u] = ++cnt;
    node[cnt] = u;
    int heavy = -1;
    for(auto v : a[u])
        if(v.F != par[u])
            if(heavy == -1 || child[v.F] > child[heavy]) heavy = v.F;
    if(heavy > -1) hld(heavy);
    for(auto v : a[u])
        if(v.F != par[u] && v.F != heavy) ++block, hld(v.F);
    out[u] = cnt;
}
#define all(s) s.begin(), s.end()
void build(int l = 1, int r = n, int id = 1){
    if(l == r){
        s[id].push_back(val[node[l]]);
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, id*2);
    build(mid+1, r, id*2+1);
    s[id].resize(s[id*2].size() + s[id*2+1].size());
    merge(s[id*2].begin(), s[id*2].end(), s[id*2+1].begin(), s[id*2+1].end(), s[id].begin());
}
int get(int u, int v, int k, int l = 1, int r = n, int id = 1){
    if(l >= u && r <= v) return upper_bound(all(s[id]), k) - s[id].begin();
    int mid = (l + r) / 2, ans = 0;
    if(u <= mid) ans += get(u, v, k, l, mid, id*2);
    if(v > mid) ans += get(u, v, k, mid+1, r, id*2+1);
    return ans;
}
int lca(int u, int v){
    if(h[u] > h[v]) swap(u,v);
    int delta = h[v] - h[u];
    FOR(i, 0, 17)
        if(((delta >> i) & 1)) v = p[v][i];
    FORR(i, 17, 0)
        if(p[v][i] != p[u][i]){
            u = p[u][i];
            v = p[v][i];
        }
    if(u != v) return p[u][0];
    return u;

}
int query(int v, int k){
    int uchain = chain[1], vchain = chain[v], ans = 0;
    while(true){
        if(uchain == vchain){
            ans += get(in[1], in[v], k);
            break;
        }
        ans += get(in[head[vchain]], in[v], k);
        v = par[head[vchain]];
        vchain = chain[v];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("network.inp");
    ofstream cout("network.out");
    cin >> n >> m;
    FOR(i, 1, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].emplace_back(v, w);
        a[v].emplace_back(u, w);
        b[i] = {u, v};
    }
    val[1] = 1e9;
    dfs(1); hld(1);
    build();
    while(m--){
        char ty; cin >> ty;
        if(ty == 'P'){
            int u, v, k;
            cin >> u >> v >> k;
            cout << query(u, k) + query(v, k) - 2 * query(lca(u, v), k) << '\n';
        }
        else{
            int x, k;
            cin >> x >> k;
            int u = b[x].F, v = b[x].S;
            if(par[v] == u) cout << get(in[v], out[v], k) - (val[v] <= k) << '\n';
            else cout << get(in[1], out[1], k) - (get(in[v], out[v], k) - (val[v] <= k))<< '\n';
        }
    }
}
