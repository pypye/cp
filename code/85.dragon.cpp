#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair<int, int>
#define maxn 805

using namespace std;
int p, n, m, T[maxn], dd[maxn], ans, dp[maxn][maxn], d[maxn], r[maxn], drg[maxn];
vector <pair> a[maxn], edge[maxn];
void dfs(int u){
    dd[u] = 1;
    for(auto v : a[u]) if(!dd[v.first] && v.second <= T[1]){
        ans = max(ans, T[v.first]);
        dfs(v.first);
    }
}
void ijk(int s){
    FOR(i, 1, n) d[i] = 1e9, drg[i] = 0;
    d[s] = 0;
    drg[s] = T[s];
    priority_queue <pair> q;
    q.push({0, s});
    while(q.size()){
        pair u = q.top(); q.pop();
        int x = u.second;
        if(d[x] < -u.first) continue;
        for(auto v : a[x]){
            if(drg[x] >= v.second && d[v.first] > d[x] + v.second){
                d[v.first] = d[x] + v.second;
                drg[v.first] = max(T[v.first], drg[x]);
                q.push({-d[v.first], v.first});
            }

        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("dragon.inp");
    //ofstream cout("dragon.out");
    cin >> p;
    cin >> n >> m;
    FOR(i, 1, n) cin >> T[i];
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    if(p == 1){
        dfs(1);
        cout << ans;
    }
    else{
        FOR(i, 1, n){
            ijk(i);
            FOR(j, 1, n){
                if(d[j] == 1e9 || i == j) continue;
                edge[i].push_back({j, d[j]});
            }
        }
        FOR(i, 1, n) d[i] = 1e9;
        d[1] = 0;
        priority_queue <pair> q;
        q.push({0, 1});
        while(q.size()){
            pair u = q.top(); q.pop();
            int x = u.second;
            if(d[x] < -u.first) continue;
            for(auto v : edge[x]){
                if(d[v.first] > d[x] + v.second){
                    d[v.first] = d[x] + v.second;
                    q.push({-d[v.first], v.first});
                }

            }
        }
        cout << d[n];
    }
}
