//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define all(s) s.begin(), s.end()
#define F first
#define S second
#define maxn 960005
using namespace std;
int n, m, tr[maxn], fen[4*maxn], laz[4*maxn], dd[maxn], ans[maxn], nn;
struct rect{
    int xl, xr, yl, yr, id;
    bool operator < (const rect &o){
        return xl < o.xl;
    }
}q[maxn], d[maxn];
vector <int> in[maxn], out[maxn], a[maxn], s;
vector <pair <int, int>> point[maxn];
bitset <80005> bs[80005];
void low(int &x){
    x = lower_bound(all(s), x) - s.begin() + 1;
}
void compress(){
    FOR(i, 1, n) s.push_back(q[i].xl), s.push_back(q[i].xr), s.push_back(q[i].yl),s.push_back(q[i].yr);
    FOR(i, 1, m) s.push_back(d[i].xl), s.push_back(d[i].xr);
    sort(all(s));
    nn = s.size();
    FOR(i, 1, n) low(q[i].xl), low(q[i].xr), low(q[i].yl), low(q[i].yr);
    FOR(i, 1, m) low(d[i].xl), low(d[i].xr);
    s.clear();
    FOR(i, 1, m) s.push_back(d[i].yl);
    sort(all(s));
    FOR(i, 1, m) low(d[i].yl);
}
    #define mid (l + r) / 2
void down(int id){
    if(laz[id] != -1){
        fen[id] = laz[id];
        laz[id*2] = laz[id];
        laz[id*2+1] = laz[id];
        laz[id] = -1;
    }
}
void update(int u, int v, int val, int l = 0, int r = nn, int id = 1){
    down(id);
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        laz[id] = val;
        down(id);
        return;
    }
    update(u, v, val, l, mid, id*2);
    update(u, v, val, mid+1, r, id*2+1);
    fen[id] = max(fen[id*2], fen[id*2+1]);
}
int get(int u, int v, int l = 0, int r = nn, int id = 1){
    down(id);
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return fen[id];
    return max(get(u, v, l, mid, id*2), get(u, v, mid+1, r, id*2+1));
}
void dfs(int u){
    dd[u]++;
    for(auto v : a[u]){
        dfs(v);
        bs[u] |= bs[v];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("paint.inp");
    ofstream cout("paint.out");
    cin >> n >> m;
    FOR(i, 1, n){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        q[i] = {u, x, v, y, i};
    }
    sort(q+1, q+n+1);
    FOR(i, 1, m){
        int u, v, c;
        cin >> u >> v >> c;
        d[i] = {u, v, c, 0, 0};
    }
    compress();
    FOR(i, 1, n){
        int u = q[i].xl, x = q[i].xr;
        in[u].push_back(i);
        out[x].push_back(i);
    }
    FOR(i, 1, m){
        int x = d[i].xl, y = d[i].xr, color = d[i].yl;
        point[x].push_back({y, color});
    }
    FOR(x, 0, nn){
        for(auto v : in[x]){
            int u = get(q[v].yl, q[v].yr);
            if(u != 0){
                a[u].push_back(v);
                tr[v] = u;
            }
            update(q[v].yl, q[v].yr, -u);
            update(q[v].yl, q[v].yr, v);
        }
        for(auto v : point[x]){
            int k = get(v.F, v.F);
            bs[k][v.S] = 1;
        }
        for(auto v : out[x]){
            update(q[v].yl, q[v].yr, -v);
            update(q[v].yl, q[v].yr, tr[v]);
        }
    }
    FOR(i, 1, n) if(!dd[i]) dfs(i);
    FOR(i, 1, n) ans[q[i].id] = bs[i].count();
    FOR(i, 1, n) cout << ans[i] << "\n";
}
