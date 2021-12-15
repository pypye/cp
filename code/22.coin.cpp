//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
using Array = int[2*maxn];
int n, m, cnt, dem;
Array id, low, tplt, ans;
vector <int> a[2*maxn], d[2*maxn], res;
stack <int> s;
void dfs(int u){
    low[u] = id[u] = ++dem;
    s.push(u);
    for(auto v : a[u]){
        if(!tplt[v]){
            if(!id[v]){
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else low[u] = min(low[u], id[v]);
        }
    }
    if(low[u] == id[u]){
        cnt++;
        int x;
        do{
            x = s.top(); s.pop();
            tplt[x] = cnt;
            d[cnt].push_back(x);
        }
        while(x != u);
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("coin.inp");
    ofstream cout("coin.out");
    cin >> n >> m;
    FOR(i, 1, m){
        int u, v;
        cin >> u >> v;
        a[u+n].push_back(-v+n);
        a[v+n].push_back(-u+n);
    }
    FOR(i, 0, n+n) if(!id[i]) dfs(i);
    FOR(i, 1, n){
        if(tplt[-i+n] == tplt[i+n]) return cout << "NO", 0;
        ans[i] = (tplt[i+n] < tplt[-i+n]);
    }
    cout << "YES\n";
    FOR(i, 1, n) if(ans[i]) cout << i << " ";
    else cout << -i << " ";
}
