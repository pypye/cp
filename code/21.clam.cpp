//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 1005
using namespace std;
using Array = int[maxn][4*maxn];
int n, m, T, red, a[maxn][maxn];
Array fen, low, laz, loz;
void downfen(int node, int id, int l, int r){
    int &y = laz[node][id];
    if(y != -1){
        int mid = (l + r) / 2;
        fen[node][id*2] = (mid - l + 1) * y;
        fen[node][id*2+1] = (r - mid) * y;
        laz[node][id*2] = y;
        laz[node][id*2+1] = y;
        y = -1;
    }
}
void downlow(int node, int id){
    int &y = loz[node][id];
    if(y != -1){
        low[node][id*2] = y;
        low[node][id*2+1] = y;
        loz[node][id*2] = y;
        loz[node][id*2+1] = y;
        y = -1;
    }
}
void update(int node, int u, int v, int val, int l = 1, int r = m, int id = 1){
    if(l >= u && r <= v){
        fen[node][id] = (r - l + 1) * val;
        laz[node][id] = val;
        low[node][id] = val;
        loz[node][id] = val;
        return;
    }
    downfen(node, id, l, r);
    downlow(node, id);
    int mid = (l + r) / 2;
    if(u <= mid) update(node, u, v, val, l, mid, id*2);
    if(v > mid) update(node, u, v, val, mid+1, r, id*2+1);
    fen[node][id] = fen[node][id*2] + fen[node][id*2+1];
    low[node][id] = min(low[node][id*2], low[node][id*2+1]);
}
int getmin(int node, int u, int v, int l = 1, int r = m, int id = 1){
    if(l >= u && r <= v) return low[node][id];
    downlow(node, id);
    int mid = (l + r) / 2, ans = 1e9;
    if(u <= mid) ans = min(ans, getmin(node, u, v, l, mid, id*2));
    if(v > mid) ans = min(ans, getmin(node, u, v, mid+1, r, id*2+1));
    return ans;
}
int getfen(int node, int u, int v, int l = 1, int r = m, int id = 1){
    if(l >= u && r <= v) return fen[node][id];
    downfen(node, id, l, r);
    int mid = (l + r) / 2, ans = 0;
    if(u <= mid) ans += getfen(node, u, v, l, mid, id*2);
    if(v > mid) ans += getfen(node, u, v, mid+1, r, id*2+1);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("clam.inp");
    ofstream cout("clam.out");
    cin >> n >> m;
    FOR(i, 1, n)
        FOR(j, 1, m)
            cin >> a[i][j], update(i, j, j, a[i][j]);
    cin >> T >> red;
    while(T--){
        int ty; cin >> ty;
        if(ty == 2) cin >> red;
        else{
            int c, c1, c2, r1, r2, ans = 0;
            bool check = 0;
            cin >> c >> c1 >> r1 >> c2 >> r2;
            FOR(i, r1, r2){
                if(getmin(i, c1, c2) < red){
                    check = 1;
                    break;
                }
            }
            if(check) cout << 0 << '\n';
            else{
                int cnt = 0;
                FOR(i, r1, r2){
                    ++cnt;
                    if(getfen(i, c1, c2) <= c){
                        int d = getfen(i, c1, c2) - red * (c2 - c1 + 1);
                        update(i, c1, c2, red);
                        c -= d;
                        ans += d;
                    }
                    else{
                        if(cnt & 1){
                            FOR(j, c1, c2){
                                int d = min(c, getfen(i, j, j) - red);
                                update(i, j, j, max(red, getfen(i, j, j) - c));
                                c -= d;
                                ans += d;
                                if(c == 0) break;
                            }
                        }
                        else{
                            FORR(j, c2, c1){
                                int d = min(c, getfen(i, j, j) - red);
                                update(i, j, j, max(red, getfen(i, j, j) - c));
                                c -= d;
                                ans += d;
                                if(c == 0) break;
                            }
                        }
                        break;
                    }
                }
                cout << ans << '\n';
            }
        }
    }
}
