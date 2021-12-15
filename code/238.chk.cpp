#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
#ifdef _DEBUG
#endif // _DEBUG
    #pragma OPtimize("O3")
using namespace std;
int n, q, k, b[maxn], dd[maxn], f[maxn], res;
vector <int> a[maxn];
void reset(){
    memset(dd, 0, sizeof dd);
    memset(f, 0, sizeof f);
    res = 0;
}
void dfs(int u, int par){
    for(auto v : a[u])
        if(v != par){
            dfs(v, u);
            f[u] += f[v];
        }
    if(dd[u]) f[u]++;
    if((f[u] >= 1 && dd[par]) || (f[u] >= 2)){
        res++;
        f[u] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("chk.inp");
    //ofstream cout("chk.out");
    cin >> n;
    FOR(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cin >> q;
    while(q--){
        int check = 0;
        reset();
        cin >> k;
        FOR(i, 1, k) cin >> b[i], dd[b[i]] = 1;
        FOR(u, 1, n)
            for(auto v : a[u]) if(dd[u] && dd[v]) check = 1;
        if(!check){
             dfs(1, -1);
             cout << res << '\n';
        }
        else cout << -1 << '\n';
    }
}
