#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005

using namespace std;

int T, n, m;
long long laz[4*maxn], a[maxn];
struct data{
    long long low, high, ans;
} fen[4*maxn];
void add(int id, long long y){
    fen[id].low  += y;
    fen[id].high += y;
    fen[id].ans  += y;
}
void down(int id){
    long long &y = laz[id];
    add(id*2,   y);
    add(id*2+1, y);
    laz[id*2]   += y;
    laz[id*2+1] += y;
    y = 0;
}
void update(int u, int v, int w, int l = 1, int r = n, int id = 1){
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        laz[id] += w;
        fen[id].ans += w;
        fen[id].low += w;
        fen[id].high += w;
        return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, w, l, mid, id*2);
    update(u, v, w, mid+1, r, id*2+1);
    fen[id] = {fen[id*2].low, fen[id*2+1].high, fen[id*2].ans + fen[id*2+1].ans - min(fen[id*2].high, fen[id*2+1].low)};
}
data get(int u, int v, int l = 1, int r = n, int id = 1){
    if(l > v || r < u) return {0, 0, 0};
    if(l >= u && r <= v) return fen[id];
    down(id);
    int mid = (l + r) >> 1;
    data L = get(u, v, l, mid, id*2);
    data R = get(u, v, mid+1, r, id*2+1);
    return {L.low, R.high, L.ans + R.ans - min(L.high, R.low)};
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("construct.inp", "r", stdin);
    freopen("construct.out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n >> m;
        FOR(i, 1, 4*n) fen[i] = {0, 0, 0}, laz[i] = 0;
        FOR(i, 1, n) cin >> a[i], update(i, i, a[i]);
        while(m--){
            int type; cin >> type;
            if(type == 1){
                int l, r, k;
                cin >> l >> r >> k;
                update(l, r, k);
            }
            else{
                int l, r;
                cin >> l >> r;
                cout << get(l, r).ans << '\n';
            }
        }
    }
}
