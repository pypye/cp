#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, m, s, t;
long long d[maxn];
vector <pair <int, int>> a[maxn], b[maxn];
void dfs(int u){
    for(auto v : a[u]){
            d[v.first] = max(d[v.first], d[u] + 1ll * v.second);
            //for(auto x : b[v.first]) d[v.first] = max(d[v.first], d[x.first] + 1ll * x.second);
        dfs(v.first);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("dpdag.inp");
    ofstream cout("dpdag.out");
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w));
        b[v].push_back(make_pair(u, w));
    }
    cin >> s >> t;
    fill(d+1, d+n+1, -1e18);
    d[s] = 0;
    dfs(s);
    if(d[t] == -1e18) cout << "NO PATH";
    else cout << d[t];
}
