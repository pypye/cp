#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 2005
using namespace std;
int n;
long long c[maxn], dp[maxn][maxn], r[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("optbst.inp");
    ofstream cout("optbst.out");
    cin >> n;
    FOR(i, 1, n) cin >> c[i], dp[i][i] = c[i], r[i][i] = i, c[i] = c[i-1] + c[i];
    FOR(len, 1, n-1)
        FOR(i, 1, n-len){
            int j = i + len;
            dp[i][j] = 1e18;
            FOR(k, r[i][j-1], r[i+1][j]){
                if(dp[i][j] > dp[i][k-1] + dp[k+1][j] + c[j] - c[i-1]){
                    dp[i][j] = dp[i][k-1] + dp[k+1][j] + c[j] - c[i-1];
                    r[i][j] = k;
                }
            }
        }
    cout << dp[1][n];
}
