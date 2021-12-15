#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 10005
#define F first
#define S second
using namespace std;
int n, dd[maxn], a[maxn][maxn], l[maxn][maxn];
struct data{
    int of, os, nf, ns;
};

vector <data> res;
pair <int, int> d[maxn], e[maxn];
void dfs(int u){
    dd[u] = 1;
    FOR(v, 0, n-1){
        if(a[u][v] && !dd[v]) dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("resubway.inp");
    //ofstream cout("resubway.out");
    cin >> n;
    FOR(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
        d[i] = {u, v};
    }
    FOR(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        l[u][v] = l[v][u] = 1;
        e[i] = {u, v};
    }
    FOR(i, 1, n-1){
        memset(dd, 0, sizeof dd);
        int u = d[i].first,  v = d[i].second;
        if(!l[u][v]){
            a[u][v] = a[v][u] = 0;
            dfs(u);
            FOR(x, 1, n-1){
                int u = e[x].first, v = e[x].second;
                if(dd[u] ^ dd[v]) {
                    a[u][v] = a[v][u] = 1;
                    res.push_back({d[i].first, d[i].second, u, v});
                    break;
                }
            }
        }
    }
    cout << res.size() << '\n';
    for(auto v : res) cout << v.of << " " << v.os << " " << v.nf << " " << v.ns << '\n';
}
