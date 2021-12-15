#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, m, node, edge, id[maxn];
long long ans = 1, mod = 1000000007;
vector <int> a[maxn];
void dfs(int u){
    node++;
    id[u]++;
    edge += a[u].size();
    for(auto v : a[u]){
        if(!id[v]) dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    ifstream cin("mroads.inp");
    ofstream cout("mroads.out");
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    FOR(i, 1, n) if(!id[i]){
        edge = node = 0;
        dfs(i);
        edge /= 2;
        if(edge > node) return cout << 0, 0;
        if(edge == node) ans = (ans * 2) % mod;
        if(edge < node) ans = (ans * node) % mod;
    }
    cout << ans;
}
