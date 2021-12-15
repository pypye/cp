#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
#define F first
#define S second
using namespace std;
int n, p[maxn], sump;
long long c[maxn], d1[maxn], d[maxn], rmin = 1e18, rmax = -1e18;
vector <pair <int, int>> a[maxn];
void dfs(int u, int par){
    d1[u] = p[u];
    for(auto v : a[u])
        if(v.F != par){
            dfs(v.F, u);
            d1[u] += d1[v.F];
            d[u] += d[v.F] + d1[v.F] * v.S;
        }
}
void dfs2(int u, int par){
    for(auto v : a[u])
        if(v.F != par){
            c[v.F] += c[u] + (sump - d1[v.F]) * v.S + d[u] - d[v.F] - d1[v.F] * v.S;
            dfs2(v.F, u);
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("tranfood.inp");
    ofstream cout("tranfood.out");
    cin >> n;
    FOR(i, 1, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w));
        a[v].push_back(make_pair(u, w));
    }
    FOR(i, 1, n) cin >> p[i], sump += p[i];
    dfs(1, -1);
    dfs2(1, -1);
    FOR(i, 1, n){
        rmin = min(rmin, c[i] + d[i]);
        rmax = max(rmax, c[i] + d[i]);
    }
    cout << rmin << " " << rmax;
}
