//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define N 100005
using namespace std;
int n, m, k, s, t, h[N], p[N], key[18][N], Next[18][N], tr[N], res[N];
vector <int> a[N], b[N];
void bfs(int s){
    queue <int> q;
    h[s] = 1;
    q.push(s);
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto v : a[u]){
            if(!h[v]){
                h[v] = h[u] + 1;
                b[h[v]].push_back(v);
                q.push(v);
            }
        }
    }
    k = h[t];
}
void Add(int u){
    key[0][u] = Next[0][u] = tr[u];
    FOR(i, 1, 17){
        Next[i][u] = Next[i-1][Next[i-1][u]];
        key[i][u] = p[h[key[i-1][u]]] < p[h[key[i-1][Next[i-1][u]]]] ? key[i-1][u] : key[i-1][Next[i-1][u]];
    }
}
int Find(int u, int v){
    int fu = u, fv = v;
    int key1 = u, key2 = v;
    FORR(i, 17, 0){
        if(Next[i][u] != Next[i][v]){
            if(p[h[key1]] > p[h[key[i][u]]]){
                key1 = key[i][u];
                key2 = key[i][v];
            }
            u = Next[i][u];
            v = Next[i][v];
        }
    }
    return key1 < key2 ? fu : fv;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("trip.inp");
    ofstream cout("trip.out");
    cin >> n >> m >> s >> t;
    while(m--){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    bfs(s);
    h[0] = k+1;
    int x;
    FOR(i, 1, k) cin >> x, p[x] = i;
    FOR(i, 2, k)
        for(auto v : b[i]){
            for(auto u : a[v])
                if(h[u] + 1 == i) tr[v] = tr[v] ? Find(tr[v], u) : u;
            Add(v);
        }
    int u = t;
    FOR(i, 1, k) res[k-i+1] = u, u = tr[u];
    FOR(i, 1, k) cout << res[i] << " ";
}
