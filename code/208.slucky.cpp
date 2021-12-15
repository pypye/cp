#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, d[maxn], link[maxn], fen[maxn], p[maxn], cnt, ans, t[4*maxn], lz[4*maxn];
stack <int> q;
void update(int x){
    for(; x <= n+1; x += x & -x) fen[x]++;
}
long long get(int x){
    long long ans = 0;
    for(; x; x -= x & (-x)) ans += fen[x];
    return ans;
}
void down(int id){
    t[id*2] = max(t[id*2], lz[id]);
    lz[id*2] = max(lz[id*2], lz[id]);
    t[id*2+1] = max(t[id*2+1], lz[id]);
    lz[id*2+1] = max(lz[id*2+1], lz[id]);
    lz[id] = 0;
}
void update2(int l, int r, int id, int u, int v, int w){
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        t[id] = max(t[id], w);
        lz[id] = max(lz[id], w);
        return;
    }
    down(id);
    int mid = (l + r) / 2;
    update2(l, mid, id*2, u, v, w);
    update2(mid+1, r, id*2+1, u, v, w);
    t[id] = max(t[id*2], t[id*2+1]);
}
int get2(int l, int r, int id, int u, int v){
    if(l > v || r < u) return -1e9;
    if(l >= u && r <= v) return t[id];
    down(id);
    int mid = (l + r) / 2;
    return max(get2(l, mid, id*2, u, v), get2(mid+1, r, id*2+1, u, v));

}
int main()
{
    ios_base::sync_with_stdio(0);
    ifstream cin("slucky.inp");
    ofstream cout("slucky.out");
    cin >> n;
    FOR(i, 1, n){
        char x; cin >> x;
        if(x == '6') q.push(i);
        else if(q.size()){
            int x = q.top(); q.pop();
            link[i] = x;
        }
    }
    int cur = 0;
    FOR(i, 1, n)
        if(link[i]){
            int x = link[i];
            d[x] = get2(1, n, 1, x, i) + 1;
            update2(1, n, 1, x, i, d[x]);
            p[i] = 0;
        }
        else cur = 0, p[i] = i;
    FOR(i, 1, n) if(d[i]){
        p[i] -= get(d[i] - 1) * 2;
        update(d[i]);
    }
    else p[i] = 0;
    FOR(i, 1, n) if(d[i]) ans += p[i];
    cout << ans;
}
