#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 505
using namespace std;
int n, m, q, a[maxn][maxn], f[maxn][18][maxn];
int getmin(int i, int u, int v){
    int k = log2(v-u+1);
    return min(f[i][k][u], f[i][k][v - (1 << k) + 1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("minquery2.inp");
    ofstream cout("minquery2.out");
    cin >> n >> m >> q;
    FOR(i, 1, n)
        FOR(j, 1, m) cin >> a[i][j], f[i][0][j] = a[i][j];
    FOR(i, 1, n){
        FOR(j, 1, 17)
            FOR(u, 1, m - (1 << j) + 1)
                f[i][j][u] = min(f[i][j-1][u], f[i][j-1][u + (1 << (j-1))]);
    }
    while(q--){
        int l1, r1, l2, r2, ans = 1e9 + 9;
        cin >> l1 >> r1 >> l2 >> r2;
        FOR(i, l1, l2){
            ans = min(ans, getmin(i, r1, r2));
        }
        cout << ans << '\n';
    }
}
