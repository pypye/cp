#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
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
//    ifstream cin("flight.inp");
//    ofstream cout("flight.out");
    cin >> n >> m;
    FOR(i, 1, n){
        int type, x, y;
        cin >> type >> x >> y;
        if(type){
            if(x == y){
                a[x+m].push_back(y);
                continue;
            }
            a[x].push_back(y+m);
            a[y+m].push_back(x);
            a[y].push_back(x+m);
            a[x+m].push_back(y);
        }
        else{
            a[x].push_back(y);
            a[y].push_back(x);
            a[x+m].push_back(y+m);
            a[y+m].push_back(x+m);
        }
    }
    FOR(i, 1, m+m) if(!id[i]) dfs(i);
    FOR(i, 1, m){
        if(tplt[i+m] == tplt[i]) return cout << -1, 0;
        ans[i] = (tplt[i+m] > tplt[i]);
    }
    int res = accumulate(ans+1, ans+m+1, 0);
    cout << res << '\n';
    FOR(i, 1, m) if(ans[i]) cout << i << " ";
}
