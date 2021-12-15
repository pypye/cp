#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
using Array = int[maxn];
int n, m, ans = 1, mod = (int)1e9 + 7;
Array p, q, l, r, d;
int gr(int u){
    return r[u] ? r[u] = gr(r[u]) : u;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("contact.inp");
    ofstream cout("contact.out");
    cin >> n >> m;
    FOR(i, 1, m) cin >> p[i] >> q[i] >> l[i];
    FOR(i, 1, m){
        FOR(len, 0, l[i]-1){
            int u = gr(p[i] + len), v = gr(q[i] + len);
            if(u > v) swap(u, v);
            if(u != v) r[v] = u;
        }
    }
    FOR(i, 1, n) if(!d[gr(i)]){
        ans = (ans * 2) % mod;
        d[gr(i)] = 1;
    }
    cout << ans;
}
