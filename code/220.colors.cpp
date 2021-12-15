//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 400005
using namespace std;
int n, m, a[maxn], d[4*maxn], p[maxn], res[maxn];
struct data{
    int l, c, d, val;
};
vector <data> q[maxn];
bool comp(data i, data j){
    return i.l < j.l;
}
void update(int l, int r, int id, int u, int w){
    if(l > u || r < u) return;
    if(l == r){
        d[id] = w;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, id*2, u, w);
    update(mid+1, r, id*2+1, u, w);
    d[id] = min(d[id*2], d[id*2+1]);
}
int get(int l, int r, int id, int u, int v){
    if (v < l || r < u) return 1e9;
    if (u <= l && r <= v) return d[id];
    int mid = (l + r) / 2;
    return min(get(l, mid, id*2, u, v), get(mid+1, r, id*2+1, u, v));
}
int searching(int c, int d, int i){
    int l = c, r = d + 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(get(1, n, 1, l, mid) < i) r = mid;
        else l = mid;
    }
    if(get(1, n, 1, l, l) < i) return l;
    return r;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("colors.inp");
    //ofstream cout("colors.out");
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m){
        int c, d, l, r;
        cin >> c >> d >> l >> r;
        q[r].push_back({l, c, d, i});
    }
    FOR(i, 1, n) sort(q[i].begin(), q[i].end(), comp);
    FOR(i, 1, n){
        p[a[i]] = i;
        update(1, n, 1, a[i], p[a[i]]);
        for(auto v : q[i]){
            if(searching(v.c, v.d, v.l) > v.d) res[v.val] = -1;
            else res[v.val] = searching(v.c, v.d, v.l);
        }
    }
    FOR(i, 1, m) if(res[i] == -1) cout << "OK\n";
    else cout << res[i] << '\n';
}
