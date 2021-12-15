#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 505
using namespace std;
int n, m, b[maxn][maxn], ans, d[maxn*maxn];
vector <int> a[maxn*maxn];
void dfs(int u, int par){
    for(auto v : a[u]){
        d[v] = d[u] + 1;
        if(v > par)ans = max(ans, d[v]);
        dfs(v, par);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("board.inp");
    ofstream cout("board.out");
    cin >> n >> m;
    FOR(i, 1, n)
        FOR(j, 1, m) cin >> b[i][j];
    FOR(i, 1, n)
        FOR(j, 1, m){
            a[b[i][j]].push_back(b[i+1][j]);
            a[b[i][j]].push_back(b[i][j+1]);
        }
    FOR(i, 1, n*m) {
        memset(d, 0, sizeof d);
        d[i] = 1;
        dfs(i, i);
    }
    cout << ans;
}
