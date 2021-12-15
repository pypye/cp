//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 200005
using namespace std;
int m, s, t, dd[maxn], l[maxn], r[maxn];
vector <pair <int, int>> a[maxn];
vector <int> p;
void compress(){
    p.push_back(s);
    p.push_back(t);
    FOR(i, 1, m){
        p.push_back(l[i]);
        p.push_back(r[i]);
    }
    sort(p.begin(), p.end());
    FOR(i, 1, m){
        l[i] = lower_bound(p.begin(), p.end(), l[i]) - p.begin() + 1;
        r[i] = lower_bound(p.begin(), p.end(), r[i]) - p.begin() + 1;
    }
    s = lower_bound(p.begin(), p.end(), s) - p.begin() + 1;
    t = lower_bound(p.begin(), p.end(), t) - p.begin() + 1;
}
void dfs(int u, int mid){
    dd[u] = 1;
    for(auto v : a[u])
        if(!dd[v.first] && v.second <= mid){
            dfs(v.first, mid);
        }
}
bool check(int s, int mid){
    memset(dd, 0, sizeof dd);
    dfs(s, mid);
    return dd[t];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("addedge.inp");
    ofstream cout("addedge.out");
    cin >> m >> s >> t;
    FOR(i, 1, m) cin >> l[i] >> r[i];
    compress();
    FOR(i, 1, m){
        if(l[i] != r[i]) a[l[i]].push_back(make_pair(r[i], i));
    }
    int l = 0, r = m+1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(s, mid)) r = mid;
        else l = mid;
    }
    if(r > m) cout << 0;
    else cout << r;
}
