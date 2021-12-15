#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 505
using namespace std;
int n, k, r, p, a[maxn][maxn];
long long f[maxn][maxn], ans;
struct point{
    int x, y;
}b[100005];
long long get(int x, int y, int u, int v){
    if(x > u || y > v) return 0;
    return f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("bonus.inp");
    ofstream cout("bonus.out");
    cin >> n >> k >> r >> p;
    FOR(i, 1, n)
        FOR(j, 1, n) cin >> a[i][j];
    FOR(i, 1, n)
        FOR(j, 1, n) f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
    while(k--){
        FOR(i, 0, p-1) cin >> b[i].x >> b[i].y;
        long long res = 0;
        FOR(i, 1, (1 << p)-1){
            int lx = 0, ly = 0, rx = 1e9, ry = 1e9;
            FOR(u, 0, p-1)
                if((i >> u) & 1){
                    lx = max(lx, b[u].x);
                    ly = max(ly, b[u].y);
                    rx = min(rx, b[u].x + r - 1);
                    ry = min(ry, b[u].y + r - 1);
                }
            long long cur = get(lx, ly, rx, ry);
            if(__builtin_popcount(i) % 2) res += cur;
            else res -= cur;
        }
        ans = max(ans, res);
    }
    cout << ans;
}
