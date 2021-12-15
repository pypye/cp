#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 100005
using namespace std;
int n, m, ans[maxn], fen[26][4*maxn], laz[26][4*maxn];
void down(int node, int id){
    int &y = laz[node][id];
    if(y == 0){
        fen[node][id*2] = y;
        laz[node][id*2] = y;
        fen[node][id*2+1] = y;
        laz[node][id*2+1] = y;
        y = -1;
    }
    if(y > 0){
        fen[node][id*2] += y;
        laz[node][id*2] += y;
        fen[node][id*2+1] += y;
        laz[node][id*2+1] += y;
        y = -1;
    }
}
void update(int node, int u, int v, int val, int l = 1, int r = n, int id = 1){
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        if(val == 0){
            fen[node][id] = val;
            laz[node][id] = val;
        }
        if(val > 0){
            fen[node][id] += val;
            laz[node][id] += val;
        }
        return;
    }
    down(node, id);
    int mid = (l + r) / 2;
    update(node, u, v, val, l, mid, id*2);
    update(node, u, v, val, mid+1, r, id*2+1);
    fen[node][id] = fen[node][id*2] + fen[node][id*2+1];
}
int get(int node, int u, int v, int l = 1, int r = n, int id = 1){
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return fen[node][id];
    down(node, id);
    int mid = (l + r) / 2;
    return get(node, u, v, l, mid, id*2) + get(node, u, v, mid+1, r, id*2+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    ifstream cin("inp.txt");
#endif // ONLINE_JUDGE
    cin >> n >> m;
    memset(laz, -1, sizeof laz);
    FOR(i, 1, n){
        char x; cin >> x;
        update(x - 'a', i, i, 1);
    }
    while(m--){
        int l, r, k;
        cin >> l >> r >> k;
        if(k){
            int px = l;
            FOR(i, 0, 'z' - 'a'){
                int x = get(i, l, r);
                if(x > 0){
                    update(i, l, r, 0);
                    update(i, px, px+x-1, 1);
                    px += x;
                }

            }
        }
        else{
            int px = l;
            FORR(i, 'z' - 'a', 0){
                int x = get(i, l, r);
                if(x > 0){
                    update(i, l, r, 0);
                    update(i, px, px+x-1, 1);
                    px += x;
                }
            }
        }
    }
    FOR(i, 1, n)
        FOR(j, 0, 'z' - 'a') if(get(j, i, i) == 1) ans[i] = j;
    FOR(i, 1, n) cout << char(ans[i] + 'a');
}
