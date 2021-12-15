#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define F first
#define S second
#define maxn 505
using namespace std;
int n, m, d[maxn][maxn], tr[maxn][maxn], way[maxn][maxn], len[10005], ans[10005];
pair b[10005];
vector <int> a[maxn], qu[maxn];
void ijk(int s){
    priority_queue <pair> q;
    fill(d[s]+1, d[s]+n+1, 1e9);
    q.push({0, s});
    d[s][s] = 0;
    way[s][s] = 1;
    while(q.size()){
        pair u = q.top(); q.pop();
        if(-u.F > d[s][u.S]) continue;
        for(int id : a[u.S]){
            int v = (b[id].F == u.S ? b[id].S : b[id].F);
            if(d[s][v] > d[s][u.S] + len[id]){
                d[s][v] = d[s][u.S] + len[id];
                tr[s][v] = id;
                way[s][v] = way[s][u.S];
                q.push({-d[s][v], v});
            }
            else if(d[s][v] == d[s][u.S] + len[id]) way[s][v] += way[s][u.S];
        }
    }
    FOR(i, 1, n) if(i != s) qu[s].push_back(tr[s][i]);

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("candy.inp");
    ofstream cout("candy.out");
    cin >> n >> m;
    FOR(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        len[i] = w;
        b[i] = {u, v};
        a[u].push_back(i);
        a[v].push_back(i);
    }
    FOR(i, 1, n) ijk(i);
    FOR(i, 1, n)
        FOR(j, i+1, n){
            for(auto k : qu[i]){
                int u = b[k].F, v = b[k].S;
                if(d[i][u] + d[v][j] + len[k] != d[i][j]) swap(u,v);
                if(d[i][u] + d[v][j] + len[k] == d[i][j] && way[i][u] * way[v][j] == way[i][j]) ans[k]++;
            }
        }
    FOR(i, 1, m) cout << ans[i] << '\n';
}
