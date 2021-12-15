#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 2005
using namespace std;
int n, r[maxn][maxn];
long long  a[maxn], dp[maxn][maxn], freq[maxn][maxn], sum[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream  cin("optbst.inp");
    ofstream cout("optbst.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i], dp[i][i] = a[i], r[i][i] = i;
    FOR(i, 1, n) sum[i] = sum[i-1] + a[i];
    FOR(i, 1, n)
        FOR(j, i, n) freq[i][j] = sum[j] - sum[i-1];
    FOR(len, 1, n-1){
        FOR(i, 1, n-len){
            int j = i + len;
            dp[i][j] = 1e18;
            FOR(k, r[i][j-1], r[i+1][j]){
                if(dp[i][j] > freq[i][j] + dp[i][k-1] + dp[k+1][j]){
                    dp[i][j] = freq[i][j] + dp[i][k-1] + dp[k+1][j];
                    r[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n];
}
