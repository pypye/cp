//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 1005
using namespace std;
int n, m, k, d[maxn][1 << 10 + 5], s, t, id[maxn];
struct data{
    int u, v, st, w;
}use[maxn];
struct edge{
    int F, st, w;
};
vector <edge> a[maxn];
pair <int, int> q[maxn];
bool check(int st, int x, int c)
{
    int v = st & x;
    int cnt = 0;
    FOR(i, 1, k)
        if((v >> (i-1)) & 1) ++cnt;
    return (c+cnt) & 1;
}
void ijk(int u){
    priority_queue <pair <int, pair <int, int>>> q;
    FOR(i, 1, n)
        FOR(j, 0, (1 << k)-1) d[i][j] = 1e9;
    d[s][0] = 0;
    q.push({0, {s, 0}});
    while(q.size()){
        auto x = q.top(); q.pop();
        int st = x.S.S;
        int u = x.S.F;
        if(-x.F > d[u][st]) continue;
        for(auto v : a[u]){
            if(check(v.w, st, v.st))
                if(d[v.F][st] > d[u][st] + 1){
                    d[v.F][st] = d[u][st] + 1;
                    q.push({-d[v.F][st], {v.F, st}});
                }
            if(id[u]){
                int y = st ^ (1<<(id[u]-1));
                if(check(v.w, y, v.st))
                    if(d[v.F][y] > d[u][st] + 1){
                        d[v.F][y] = d[u][st] + 1;
                        q.push({-d[v.F][y], {v.F, y}});
                    }
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("maze.inp");
    ofstream cout("maze.out");
    cin >> n >> m;
    FOR(i, 1, m){
        int u, v, st;
        cin >> u >> v >> st;
        use[i] = {u, v, st, 0};
    }
    cin >> k;
    FOR(i, 1, k){
        int u, cnt;
        cin >> u >> cnt;
        id[u] = i;
        FOR(x, 1, cnt){
            int v; cin >> v;
            use[v].w += (1 << (i-1));
        }
    }
    FOR(i, 1, m){
        a[use[i].u].push_back({use[i].v, use[i].st, use[i].w});
        a[use[i].v].push_back({use[i].u, use[i].st, use[i].w});
    }
    cin >> s >> t;
    ijk(s);
    int ans = 1e9;
    FOR(i, 0, (1 << k)-1) ans = min(ans, d[t][i]);
    if(ans == 1e9) cout << -1;
    else cout << ans;
}
