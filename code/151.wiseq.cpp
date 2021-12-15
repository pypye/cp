#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define all(s) s.begin(), s.end()
#define maxn 100005
using namespace std;
int n, w, a[maxn];
long long fen[4*maxn];
void update(int l, int r, int id, int x, int val){
    if(l > x || r < x) return;
    if(l == r){
        fen[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, id*2, x, val);
    update(mid+1, r, id*2+1, x, val);
    fen[id] = fen[id*2] + fen[id*2+1];
}
long long get(int l, int r, int id, int u, int v){
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return fen[id];
    int mid = (l + r) / 2;
    return get(l, mid, id*2, u, v) + get(mid+1, r, id*2+1, u, v);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("wiseq.inp");
    //ofstream cout("wiseq.out");
    cin >> n >> w;
    FOR(i, 1, n) cin >> a[i];
    vector <int> l(n+1, INT_MAX);
    int ans = 0;
    FOR(i, 1, n){
        int k = lower_bound(all(l), a[i]) - l.begin();
        long long x = get(1, n, 1, 1, k) + a[i];
        if(x <= w) ans = max(k + 1, ans);
        update(1, n, 1, k + 1, a[i]);
        l[k] = a[i];
    }
    cout << ans;
}
