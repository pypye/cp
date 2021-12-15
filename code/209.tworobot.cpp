#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1005
using namespace std;
int T, n, a[maxn][maxn];
long long f[maxn][maxn], g[maxn][maxn], sum[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    ifstream cin("tworobot.inp");
    ofstream cout("tworobot.out");
    cin >> T;
    while(T--){
        cin >> n;
        memset(a, 0, sizeof a);
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        FOR(i, 1, n)
            FOR(j, 1, i) cin >> a[i][j];
        FOR(i, 1, n)
            FOR(j, 1, i){
                f[i][j] = max(f[i][j], f[i-1][j-1] + a[i][j]);
                f[i][j] = max(f[i][j], f[i-1][j]+ a[i][j]) ;
                f[i][j] = max(f[i][j], f[i-1][j+1]+ a[i][j]);
            }
        FORR(j, n, 1)
            FORR(i, n, j){
                g[i][j] = max(g[i][j], g[i-1][j+1] + a[i][j]);
                g[i][j] = max(g[i][j], g[i][j+1] + a[i][j]);
                g[i][j] = max(g[i][j], g[i+1][j+1] + a[i][j]);
            }

        cout << max(max(f[n-1][1] + g[n-1][2], f[n-1][1] + g[n][2]), f[n-1][2] + g[n][2]) + a[n][1] << '\n';

    }
}
