//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 105
using namespace std;
int n, k, c[maxn], f[maxn][maxn], d[maxn], res;
vector <int> a[maxn];
void dfs(int u){
    f[u][1] = c[u];
    d[u]++;
    for(auto v : a[u])
        if(!d[v]){
            dfs(v);
            FORR(i, k, 1)
                FORR(j, i-1, 1) f[u][i] = max(f[u][i], f[u][j] + f[v][i-j]);
        }
    FOR(i, 1, k) res = max(res, f[u][i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("option.inp");
    ofstream cout("option.out");
    cin >> n >> k;
    FOR(i, 1, n){
        int x;
        cin >> c[i] >> x;
        while(x--){
            int j; cin >> j;
            a[i].push_back(j);
        }
    }
    FOR(i, 1, n){
        memset(f, 0, sizeof f);
        memset(d, 0, sizeof d);
        dfs(i);
    }
    cout << res;
}
