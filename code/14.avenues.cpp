#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 205
using namespace std;
int n, cnt, id[maxn], low[maxn], lt[maxn], tr[maxn], dem, res, dd[maxn][maxn];
vector <int> a[maxn], d[maxn];
stack <int> s;
void Dfs(int u){
    id[u] = low[u] = ++dem;
    s.push(u);
    for(int v : a[u])
        if(!lt[v]){
            if(!id[v]){
                tr[v] = u;
                Dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if(tr[u] != v) low[u] = min(low[u], id[v]);

        }
    if(low[u] == id[u]){
        cnt++;
        int x;
        do{
            x = s.top(), s.pop();
            lt[x] = cnt;
            d[cnt].push_back(x);
        }
        while (x != u);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream  cin("avenues.inp");
    ofstream cout("avenues.out");
    cin >> n;
    FOR(i, 1, n)
        FOR(j, 1, n){
            int x; cin >> x;
            if(x == 1) a[i].push_back(j), dd[i][j] = 1;
        }
    FOR(i, 1, n)
        if(!id[i]) dem = 0, Dfs(i);
    FOR(i, 1, cnt)if(d[i].size() > 1){
        int check = 0;
        for(int x : d[i])
            for(int y : d[i]) if(dd[x][y]) check++;
        res += check - d[i].size();
    }
    cout << res;
}
