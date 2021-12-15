#include <bits/stdc++.h>
#define FOR(i,x,y) for(int i = x; i <= y ; ++i)
#define FORN(i,x,y) for(int i = x; i >= y ; --i)
#define maxn 100001
#define maxm 100001
#define Task "LCA"
#define pii pair< int , int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
int n, m, k;
vector<int> a[maxn];
int p[maxn][18];
void nhap() 
{
    cin >> n >> k >> m;
    FOR(i, 1, n-1)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
}
int h[maxn];
bool dd[maxn];
void DFS( int u)
{
    dd[u] = 1;
    for (auto v : a[u])
        if(!dd[v] && p[u][0] != v)
        {   h[v] = h[u] + 1;
            p[v][0] = u;
            FOR(i, 1, 17)
                p[v][i] = p[p[v][i-1]][i-1];
            DFS(v);
        }
}
int bit(int v, int i)
{
    return (v >> i)&1;
}
void LCA(int u, int v)
{
    if (h[u] > h[v]) swap(u,v);
    int delta = h[v] - h[u];
    FOR(i,0,17)
            if(bit(delta,i) == 1)
                v = p[v][i];
    FORN(i, 17, 0)
        if(p[v][i] != p[u][i])
        {
            u = p[u][i];
            v = p[v][i];
        }
    if(u!=v) cout << p[u][0] << "\n";
    else cout << u << "\n";

}
int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
    freopen(Task".inp" , "r" , stdin);
    freopen(Task".out" , "w" , stdout);
    nhap();
    DFS(k);
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        LCA(u,v);
    }
}
