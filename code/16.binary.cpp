//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 1005
using namespace std;
int n, a[maxn], d[maxn], dif[maxn], r[maxn], ans = 1, mod = 1e9 + 7;
int gr(int u){
    return r[u] ? r[u] = gr(r[u]) : u;
}
void add(int u, int v){
    int p = gr(u), q = gr(v);
    if(p != q){
        d[u] |= d[v];
        r[q] = p;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("binary.inp");
    ofstream cout("binary.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    if(a[1] > 0) return cout << 0, 0;
    FOR(i, 1, n) if(a[i] + i - 1 > n) return cout << 0, 0;
    a[1] = -1;
    FOR(i, 1, n) d[i] = !(a[i] == -1);
    FOR(i, 1, n){
        if(a[i] == -1) continue;
        FOR(len, 0, a[i]-1){
            add(i+len, len+1);
        }
        int x = a[i] + 1;
        int y = a[i] + i;
        if(!dif[x]){
            if(x != y) dif[x] = y;
        }
        else add(dif[x], y);
        if(!dif[y]){
            if(x != y) dif[y] = x;
        }
        else add(dif[y], x);
    }
    FOR(i, 1, n)
        if(gr(i) == gr(dif[i])) return cout << 0, 0;
    FOR(i, 1, n) if(!d[i]) ans = (ans * 2) % mod;
    cout << ans;
}
