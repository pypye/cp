#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 300005
using namespace std;
int n, q, r[maxn], ans[maxn], last;
struct data{
    int k, v, pos;
    bool operator < (const data &x){
        return k > x.k;
    }
}b[maxn], c[maxn];
vector <data> query;
vector <int> comp;
vector <pair <int, int>> a[maxn];
void compress(){
    sort(comp.begin(), comp.end());
    FOR(i, 1, n-1){
        int w = lower_bound(comp.begin(), comp.end(), b[i].k) - comp.begin() + 1;
        int u = b[i].v, v = b[i].pos;
        a[w].push_back({u, v});
        last = max(last, w);
    }
    FOR(i, 1, q){
        int k = lower_bound(comp.begin(), comp.end(), c[i].k) - comp.begin() + 1;
        query.push_back({k, c[i].v, c[i].pos});
    }
}
int gr(int u){
    return r[u] >= 0 ? r[u] = gr(r[u]) : u;
}
void add(int u, int v){
    int p = gr(u), q = gr(v);
    if(p > q) swap(p, q);
    if(p != q){
        r[p] += r[q];
        r[q] = p;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("cver.inp", "r", stdin);
    freopen("cver.out", "w", stdout);
    cin >> n >> q;
    memset(r, -1, sizeof r);
    FOR(i, 1, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        comp.push_back(w);
        b[i] = {w, u, v};
    }
    FOR(i, 1, q){
        int k, v;
        cin >> k >> v;
        comp.push_back(k);
        c[i] = {k, v, i};
    }
    compress();
    FOR(i, 1, n) sort(a[i].begin(), a[i].end());
    sort(query.begin(), query.end());
    FOR(i, 0, q-1){
        int k = query[i].k, v = query[i].v;
        FORR(w, last, k){
            for(auto x : a[w])
                add(x.first, x.second);
        }
        ans[query[i].pos] = -r[gr(v)] - 1;
        last = k-1;
    }
    FOR(i, 1, q) cout << ans[i] << '\n';
}
