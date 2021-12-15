//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <long long, int>
#define F first
#define S second
#define maxn 300005
using namespace std;
int n, m;
long long c[maxn], ans, pos1, pos2, pos3, pos4;
pair d[maxn][3];
vector <int> a[maxn], res;
void check(int u, int v){
    FOR(i, 0, 2)
        FOR(j, 0, 2){
            if(d[u][i].S != v && d[v][j].S != u && d[u][i].S != d[v][j].S){
                if(ans < d[u][i].F + c[u] + c[v] + d[v][j].F){
                    ans = d[u][i].F + c[u] + c[v] + d[v][j].F;
                    pos1 = d[u][i].S;
                    pos2 = u;
                    pos3 = v;
                    pos4 = d[v][j].S;
                }
            }
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("tourist.inp");
    ofstream cout("tourist.out");
    cin >> n >> m;
    FOR(i, 1, n) cin >> c[i];
    while(m--){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    FOR(u, 1, n){
        vector <pair> q;
        for(auto v : a[u]) q.emplace_back(c[v], v);
        sort(q.begin(), q.end());
        FOR(i, 0, 2)if(q.size()){
            d[u][i] = q.back();
            q.pop_back();
        }
    }
    FOR(u, 1, n){
        for(auto v : a[u]) check(u, v);
    }
    if(pos1) res.push_back(pos1);
    if(pos2) res.push_back(pos2);
    if(pos3) res.push_back(pos3);
    if(pos4) res.push_back(pos4);
    cout << res.size() << '\n';
    for(auto v : res) cout << v << " ";
}
