//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
int n, m, T, d[maxn], tr[maxn];
long long ans, c[maxn];
vector <pair> a[maxn];
vector <int> edge[maxn];
void dfs(int u, int par){
    for(auto v : edge[u]){
        if(v != par){
            dfs(v, u);
            c[u] += c[v];
        }
    }
}
void ijk(){
    priority_queue <pair> q;
    q.push({0, 1});
    FOR(i, 1, n) d[i] = 1e9;
    d[1] = 0;
    while(q.size()){
        auto x = q.top(); q.pop();
        int u = x.second;
        if(d[u] < -x.first) continue;
        for(auto v : a[u]){
            if(d[v.first] > d[u] + v.second){
                d[v.first] = d[u] + v.second;
                tr[v.first] = u;
                q.push({-d[v.first], v.first});
            }
            else if(d[v.first] == d[u] + v.second) tr[v.first] = min(tr[v.first], u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("shortcut.inp");
    //ofstream cout("shortcut.out");
    cin >> n >> m >> T;
    FOR(i, 1, n) cin >> c[i];
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    ijk();
    FOR(i, 1, n) edge[tr[i]].push_back(i);
    dfs(1, -1);
     FOR(i, 1, n){
        ans = max(ans, 1ll * (d[i] - T) * c[i]);
    }
    cout << ans;
}
