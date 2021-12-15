#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, m, type, root[maxn], p[maxn][18], dd[maxn], h[maxn], d[maxn], d1[maxn], d2[maxn], maxlen, maxu, maxv;
struct data{
    int type, u, v;
};
vector <data> q;
vector <pair <int, int>> a[maxn];
int getroot(int u){
    return root[u] ? root[u] = getroot(root[u]) : u;
}
void dfs(int u){
    dd[u]++;
    for(auto v : a[u]){
        if(!dd[v.first] && p[u][0] != v.first){
            h[v.first] = h[u] + 1;
            d[v.first] = d[u] + v.second;
            p[v.first][0] = u;
            FOR(i, 1, 17) p[v.first][i] = p[p[v.first][i-1]][i-1];
            dfs(v.first);
        }
    }
}
int lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    int del = h[v] - h[u];
    FOR(i, 0, 17) if((del >> i) & 1) v = p[v][i];
    FORR(i, 17, 0)
        if(p[v][i] != p[u][i]){
            u = p[u][i];
            v = p[v][i];
        }
    if(u != v) return p[u][0];
    return u;

}
void check(int u, int v){
    int mid = lca(u, v);
    if(maxlen < d[u] + d[v] - 2 * d[mid]){
        maxlen = d[u] + d[v] - 2* d[mid];
        maxu = u; maxv = v;
    }
}
void update(int u, int v){
    int p = getroot(u), q = getroot(v);
    if(p != q){
        maxlen = 0;
        root[q] = p;
        check(d1[p], d2[p]);
        check(d1[p], d1[q]);
        check(d1[p], d2[q]);
        check(d2[p], d1[q]);
        check(d2[p], d2[q]);
        check(d1[q], d2[q]);
        d1[p] = maxu, d2[p] = maxv;
    }
}
int get(int u){
    int p = getroot(u);
    int mid1 = lca(d1[p], u);
    int mid2 = lca(d2[p], u);
    return max(d[d1[p]] + d[u] - 2*d[mid1], d[d2[p]] + d[u] - 2*d[mid2]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("xayduong.inp");
    ofstream cout("xayduong.out");
    cin >> n >> m;
    while(m--){
        cin >> type;
        if(type == 1){
            int u, v, w;
            cin >> u >> v >> w;
            q.push_back({type, u, v});
            int p = getroot(u), q = getroot(v);
            if(p != q){
                root[p] = q;
                a[u].push_back(make_pair(v, w));
                a[v].push_back(make_pair(u, w));
            }
        }
        else{
            int u;
            cin >> u;
            q.push_back({type, u, 0});
        }
    }
    FOR(i, 1, n) root[i] = 0, d1[i] = d2[i] = i;
    dfs(1);
    for(auto x : q){
        if(x.type == 1) update(x.u, x.v);
        else cout << get(x.u) << '\n';
    }
}
