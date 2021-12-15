//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define F first
#define S second
#define maxn 300005
using namespace std;
int n, m, q, a[101][101];
long long dp[101][101][101][101];
pair qa[maxn], qb[maxn], qc[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("turtle.inp");
    ofstream cout("turtle.out");
    cin >> n >> m;
    FOR(i, 1, n)
        FOR(j, 1, m){
            char x; cin >> x;
            if(x == '.') a[i][j] = 1;
        }
    FOR(x, 1, n)
        FOR(y, 1, m){
            dp[x][y][x][y] = 1;
            FOR(i, x, n)
                FOR(j, y, m) if(a[i][j]){
                    if(a[i-1][j]) dp[x][y][i][j] += dp[x][y][i-1][j];
                    if(a[i][j-1]) dp[x][y][i][j] += dp[x][y][i][j-1];
                }
        }
    cin >> q;
    while(q--){
        int ans = 0, A, B, C;
        cin >> A;
        FOR(i, 1, A) cin >> qa[i].F >> qa[i].S;
        cin >> B;
        FOR(i, 1, B) cin >> qb[i].F >> qb[i].S;
        cin >> C;
        FOR(i, 1, C) cin >> qc[i].F >> qc[i].S;
        FOR(i, 1, A)
            FOR(j, 1, B)
                FOR(k, 1, C){
                    int ua = qa[i].F, va = qa[i].S;
                    int ub = qb[j].F, vb = qb[j].S;
                    int uc = qc[k].F, vc = qc[k].S;
                    if(dp[ua][va][uc][vc] != dp[ua][va][ub][vb] * dp[ub][vb][uc][vc]) ans++;
                }
        cout << ans << '\n';
    }
}
