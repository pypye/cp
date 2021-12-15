//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define F first
#define S second
#define maxn 500005
using namespace std;
int n, m, c[maxn], d[maxn], par[maxn];
pair ed[5 + (int)1e6];
vector <int> a[maxn], p[maxn];
void bfs(int x, int c[]){
    queue <int> q;
    q.push(x); c[x] = 1;
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto v : a[u]){
            if(!c[v]){
                q.push(v);
                c[v] = c[u] + 1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("graph.inp");
//    ofstream cout("graph.out");
    cin >> n >> m;
    FOR(i, 1, m){
        cin >> ed[i].F >> ed[i].S;
        a[ed[i].F].push_back(ed[i].S);
        a[ed[i].S].push_back(ed[i].F);
    }
    bfs(1, c);
    bfs(n, d);
    FOR(i, 1, n) p[c[i]].push_back(i), a[i].clear();
    FOR(i, 1, m) a[ed[i].F].push_back(ed[i].S);
    int ans = 1e9;
    FOR(i, 1, n){
        for(auto x : p[i]){
            queue <int> q;
            q.push(x); par[x] = 1;
            while(q.size()){
                int u = q.front(); q.pop();
                if(c[u]) ans = min(ans, i + d[u] - 2);
                for(auto v : a[u]){
                    if(!par[v]){
                        q.push(v);
                        par[v]++;
                    }
                }
            }
        }
    }
    if(ans == 1e9) cout << -1;
    else cout << ans;
}
