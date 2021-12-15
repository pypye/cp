#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 200005
using namespace std;
int n, s, t, dd[maxn], tr[maxn], c[maxn], ok, res, f[maxn];
vector <int> a[maxn];
bool comp(int i, int j){
    return c[i] < c[j];
}
void Find(int u){
    dd[u] = 1;
    for(auto v : a[u])
        if(!dd[v]) tr[v] = u, Find(v);
}
void dfs(int u, int mid){
    if(ok) return;
    dd[u] = 1;
    for(auto v : a[u]) if(!dd[v]){
        f[v] = f[u] + 1;
        res = max(res, f[v]);
        if(res >= mid) ok = 1;
        dfs(v, mid);
    }
}
bool check(int mid){
    memset(dd, 0, sizeof dd);
    memset(f, 0, sizeof f);
    res = 0, ok = 0, f[s] = 1;
    dfs(s, mid);
    memset(f, 0, sizeof f);
    res = 0, ok = 0, f[t] = 1;
    dfs(t, mid);
    if(res < mid) return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("graph19b.inp");
    ofstream cout("graph19b.out");
    cin >> n;
    FOR(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cin >> s >> t;
    Find(s);
    int last = t;
    while(last != s) c[last] = 1, last = tr[last];
    FOR(i, 1, n) sort(a[i].begin(), a[i].end(), comp);
    int l = 0, r = n+1;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l;

}
