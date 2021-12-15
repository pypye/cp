#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 100005
using namespace std;
int n, m, dd[maxn];
long long hx, hy, lx = 1e18, ly = 1e18, ans = 1e18;
struct pii{
    long long F, S;
}b[maxn];
vector <int> a[maxn];
void dfs(int u){
    dd[u] = 1;
    for(auto v : a[u]) if(!dd[v]){
        lx = min(lx, b[v].F);
        hx = max(hx, b[v].F);
        ly = min(ly, b[v].S);
        hy = max(hy, b[v].S);
        dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("jura.inp");
    ofstream cout("jura.out");
    cin >> n >> m;
    FOR(i, 1, n) cin >> b[i].F >> b[i].S;
    while(m--){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    FOR(i, 1, n) if(!dd[i]){
        lx = min(lx, b[i].F);
        hx = max(hx, b[i].F);
        ly = min(ly, b[i].S);
        hy = max(hy, b[i].S);
        dfs(i);
        ans = min(ans, 2 * ((hx - lx) + (hy - ly)));
        hx = hy = 0;
        lx = ly = 1e18;

    }
    cout << ans;
}
