#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1005
using namespace std;
int q, n, T, m, maxflow, c[maxn][maxn], f[maxn][maxn], tr[maxn], s, t;
vector <int> edge[maxn];
void reset(){
    memset(c, 0, sizeof c);
    memset(f, 0, sizeof f);
    FOR(i, 1, n) edge[i].clear();
    maxflow = 0;
}
void add(int u, int v, int w){
    edge[u].push_back(v);
    edge[v].push_back(u);
    c[u][v] = w;
}
bool FindPath(){
    memset(tr, 0, sizeof tr);
    queue <int> q;
    q.push(s);
    tr[s] = -1;
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto v : edge[u]) if(!tr[v] && c[u][v] > f[u][v]){
            tr[v] = u;
            q.push(v);
        }
    }
    return tr[t];
}
void IncFlow(){
    int del = 1e9, u = t;
    while(u != s){
        int v = tr[u];
        del = min(del, c[v][u] - f[v][u]);
        u = v;
    }
    u = t;
    while(u != s){
        int v = tr[u];
        f[u][v] -= del;
        f[v][u] += del;
        u = v;
    }
    maxflow += del;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("star.inp");
    //ofstream cout("star.out");
    cin >> q;
    while(q--){
        cin >> n >> T >> m;
        reset();
        s = 2 * n + 1;
        t = 2 * n + 2;
        while(m--){
            int u, v;
            cin >> u >> v;
            add(u, v+n, 1);
            add(v, u+n, 1);
        }
        FOR(i, 1, n){
            add(s, i, T);
            add(i+n, t, 1);
        }
        while(FindPath()) IncFlow();
        cout << maxflow << '\n';
    }
}
