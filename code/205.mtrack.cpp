//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
int n, q, tree[2][4*maxn];
pair p[maxn];
int D(int i, int j){
    int u = p[i].first, v = p[i].second;
    int x = p[j].first, y = p[j].second;
    return abs(u - x) + abs(v - y);
}
int a(int i){
    return D(i, i+1);
}
int b(int i){
    return D(i, i+2) - D(i, i+1) - D(i+1, i+2);
}
void update(bool ty, int x, int val, int l = 1, int r = n, int id = 1){
    if(l > x || r < x) return;
    if(l == r){
        tree[ty][id] = val;
        return;
    }
    int mid = l + r >> 1;
    update(ty, x, val, l, mid, id*2);
    update(ty, x, val, mid+1, r, id*2+1);
    if(ty) tree[ty][id] = min(tree[ty][id*2], tree[ty][id*2+1]);
    else tree[ty][id] = tree[ty][id*2] + tree[ty][id*2+1];
}
int get(bool ty, int u, int v, int l = 1, int r = n, int id = 1){
    if(l > v || r < u) return (ty ? 1e9 : 0);
    if(l >= u && r <= v) return tree[ty][id];
    int mid = l + r >> 1;
    if(ty) return min(get(ty, u, v, l, mid, id*2), get(ty, u, v, mid+1, r, id*2+1));
    else return get(ty, u, v, l, mid, id*2) + get(ty, u, v, mid+1, r, id*2+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("mtrack.inp");
    ofstream cout("mtrack.out");
    cin >> n >> q;
    FOR(i, 1, n) cin >> p[i].first >> p[i].second;
    FOR(i, 1, n-1) update(0, i, a(i));
    FOR(i, 1, n-2) update(1, i, b(i));
    while(q--){
        char type; cin >> type;
        if(type == 'U'){
            int k, x, y;
            cin >> k >> x >> y;
            p[k] = {x, y};
            FOR(i, 0, 1) update(0, k-i, a(k-i));
            FOR(i, 0, 2) update(1, k-i, b(k-i));
        }
        else{
            int x, y;
            cin >> x >> y;
            cout << get(0, x, y-1) + get(1, x, y-2) << '\n';
        }
    }

}
