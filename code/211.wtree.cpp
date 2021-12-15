#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n;
long long d[maxn], res;
int mod = 1000000007;
vector <pair <int, long long>> a[maxn];
void dfs(int u, int par){
    long long cur = 0;
    for(auto v : a[u]){
        if(v.first == par) continue;
        dfs(v.first, u);
        long long temp = (d[v.first] * v.second) % mod;
        d[u] += temp; d[u] %= mod;
        res += cur * temp; res %= mod;
        cur += temp; cur %= mod;
    }
    res += d[u]++; res %= mod;
    d[u] %= mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    ifstream cin("wtree.inp");
    ofstream cout("wtree.out");
    cin >> n;
    FOR(i, 1, n-1){
        int u, v; long long w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    dfs(1, -1);
    cout << res;
}
