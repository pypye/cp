#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 10005
#define F first
#define S second
using namespace std;
struct data{
    int of, os, nf, ns;
};
vector <data> save;
int n, a[maxn][maxn], dd[maxn], res, l[maxn][maxn];
pair <int, int> d[maxn], f[maxn];
void dfs(int u){
    dd[u] = 1;
    FOR(i, 0, n-1)
        if(a[u][i] && !dd[i]) dfs(i);
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
        f[i] = {u, v};
        if(a[u][v]) l[u][v] = l[v][u] = 1;
    }
    FOR(i, 1, n-1){
        int u = f[i].F, v = f[i].S;
        if(a[u][v]) continue;
        a[u][v] = a[v][u] = 1;
        l[u][v] = l[v][u] = 1;
        FOR(j, 1, n-1) if(!l[d[j].F][d[j].S] && a[d[j].F][d[j].S]){
            int check = 1;
            a[d[j].F][d[j].S] = a[d[j].S][d[j].F] = 0;
            memset(dd, 0, sizeof dd);
            dfs(0);
            FOR(x, 1, n-1) if(!dd[x]) check = 0;
            if(!check) a[d[j].F][d[j].S] = a[d[j].S][d[j].F] = 1;
            else{
                res++;
                save.push_back({d[j].F, d[j].S, u, v});
                break;
            }
        }
    }
    cout << res << '\n';
    for(auto v : save) cout << v.of << " " << v.os << " " << v.nf << " " << v.ns << '\n';

}
