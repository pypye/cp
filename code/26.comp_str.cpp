//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <long long, int>
#define F first
#define S second
#define maxn 100005
using namespace std;
int n, m, base = 31, mod = 100000007;
long long p[maxn];
string s;
pair fen[4*maxn];
#define mid (l + r) / 2
void update(int x, int val, int l = 1, int r = m, int id = 1){
    if(l > x || r < x) return;
    if(l == r){
        fen[id].F = val;
        fen[id].S = val ? 1 : 0;
        return;
    }
    update(x, val, l, mid, id*2);
    update(x, val, mid+1, r, id*2+1);
    fen[id].F = (fen[id*2].F + fen[id*2+1].F * p[fen[id*2].S]) % mod;
    fen[id].S = fen[id*2].S + fen[id*2+1].S;
}
pair get(int u, int v, int l = 1, int r = m, int id = 1){
    if(l > v || r < u) return {0, 0};
    if(l >= u && r <= v) return fen[id];
    pair gl = get(u, v, l, mid, id*2);
    pair gr = get(u, v, mid+1, r, id*2+1);
    return {(gl.F + gr.F * p[gl.S]) % mod, gl.S + gr.S};
}
int Find(int x){
    int l = 0, r = m+1;
    while(r - l > 1){
        if(get(1, mid).S >= x) r = mid;
        else l = mid;
    }
    return r;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("comp_str.inp");
    ofstream cout("comp_str.out");
    cin >> s;
    m = s.size();
    s = '@' + s;
    p[0] = 1;
    FOR(i, 1, m) p[i] = (p[i-1] * base) % mod;
    for(int i = 1; s[i]; ++i) update(i, s[i] - '0' + 1);
    cin >> n;
    while(n--){
        char ty; cin >> ty;
        if(ty == '-'){
            int x; cin >> x;
            x = Find(x);
            update(x, 0);
        }
        else{
            int u, v, w; cin >> u >> v >> w;
            int wu = Find(u + w - 1), wv = Find(v + w - 1);
            u = Find(u); v = Find(v);
            if(get(u, wu).F == get(v, wv).F) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
