#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 300005
using namespace std;
int n, q, a[maxn], b[maxn], c[maxn], d[4*maxn];
void init(int l, int r, int id){
    if(l == r){
        d[id] = c[l];
        return;
    }
    int mid = (l + r) >> 1;
    init(l, mid, id*2);
    init(mid+1, r, id*2+1);
    d[id] = d[id*2] + d[id*2+1];
}
void update(int l, int r, int id, int u, int w){
    if(l > u || r < u) return;
    if(l == r){
        d[id] += w;
        return;
    }
    int mid = (l + r) >> 1;
    update(l, mid, id*2, u, w);
    update(mid+1, r, id*2+1, u, w);
    d[id] = d[id*2] + d[id*2+1];
}
int get(int l, int r, int id){
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(d[id*2]) return get(l,mid, id*2);
    return get(mid+1, r, id*2+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("compseq.inp");
    ofstream cout("compseq.out");
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    FOR(i, 1, n) if(a[i] != b[i]) c[i] = 1;
    init(1, n, 1);
    while(q--){
        int u, v;
        cin >> u >> v;
        a[u] = v;
        if(a[u] == b[u]) update(1, n, 1, u, -c[u]), c[u] = 0;
        else update(1, n, 1, u, 1-c[u]), c[u] = 1;
        int k = get(1, n, 1);
        cout << ((a[k] > b[k]) ? "Y" : "N") << '\n';
    }
}
