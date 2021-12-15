#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 300005
using namespace std;
int n, m, s[maxn], t[maxn], d[maxn], tree[4*maxn], push[4*maxn];
void init(int l, int r, int id){
    if(l == r){
        tree[id] = d[l];
        return;
    }
    int mid = (l + r) >> 1;
    init(l, mid, id*2);
    init(mid+1, r, id*2+1);
    tree[id] = tree[id*2] + tree[id*2+1];
}
void update(int l, int r, int id, int u, int w){
    if(l > u || r < u) return;
    if(l == r){
        tree[id] += w;
        return;
    }
    int mid = (l + r) >> 1;
    update(l, mid, id*2, u, w);
    update(mid+1, r, id*2+1, u, w);
    tree[id] = tree[id*2] + tree[id*2+1];
}
int get(int l, int r, int id){
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(tree[id*2]) return get(l, mid, id*2);
    return get(mid+1, r, id*2+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("compare2.inp");
    ofstream cout("compare2.out");
    cin >> n >> m;
    FOR(i, 1, n) cin >> s[i];
    FOR(i, 1, n){
        cin >> t[i];
        if(s[i] != t[i]) d[i] = 1;
    }
    init(1, n, 1);
    while(m--){
        int u, v;
        cin >> u >> v; s[u] = v;
        if(s[u] == t[u]) update(1, n, 1, u, -d[u]), d[u] = 0;
        else update(1, n, 1, u, 1 -d[u]), d[u] = 1;
        int r = get(1, n, 1);
        if(s[r] > t[r]) cout << "Y\n";
        else cout << "N\n";
    }
}
