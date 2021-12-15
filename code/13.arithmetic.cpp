//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
int n, m, mod = 1000000007;
long long fen[8*maxn], lzy[8*maxn], lzy2[8*maxn];
    #define mid (l + r) / 2
void mul(long long &x, long long y){
    x *= y; x %= mod;
}
void add(long long &x, long long y){
    x += y; x %= mod;
}
void down(int id){
    mul(fen[id*2], lzy2[id]); mul(fen[id*2+1], lzy2[id]);
    add(fen[id*2], lzy[id]);  add(fen[id*2+1], lzy[id]);
    add(lzy[id*2], lzy[id]);  add(lzy[id*2+1], lzy[id]);
    mul(lzy[id*2], lzy2[id]); mul(lzy[id*2+1], lzy2[id]);
    mul(lzy2[id*2], lzy2[id]); mul(lzy2[id*2+1], lzy2[id]);
    lzy[id] = 0; lzy2[id] = 1;
}
void update(bool ty, int u, int v, int val, int l = 1, int r = n, int id = 1){
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        if(ty) add(fen[id], val); else mul(fen[id], val);
        if(ty) add(lzy[id], val); else mul(lzy2[id], val), mul(lzy[id], val);
        return;
    }
    down(id);
    update(ty, u, v, val, l, mid, id*2);
    update(ty, u, v, val, mid+1, r, id*2+1);
    add(fen[id], fen[id*2] + fen[id*2+1]);
}
long long get(int x, int l = 1, int r = n, int id = 1){
    if(l > x || r < x) return 0;
    if(l == r) return fen[id];
    down(id);
    return get(x, l, mid, id*2) + get(x, mid+1, r, id*2+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("arithmetic.inp");
    ofstream cout("arithmetic.out");
    fill(lzy2+1, lzy2+8*maxn+1, 1);
    cin >> n;
    FOR(i, 1, n){
        int x; cin >> x;
        update(1, i, i, x);
    }
    cin >> m;
    while(m--){
        char ty; cin >> ty;
        if(ty == '+'){
            int u, v, d;
            cin >> u >> v >> d;
            update(1, u, v, d);
        }
        else if(ty == '*'){
            int u, v, d;
            cin >> u >> v >> d;
            update(0, u, v, d);
        }
        else{
            int x; cin >> x;
            cout << get(x) << '\n';
        }
    }
}
