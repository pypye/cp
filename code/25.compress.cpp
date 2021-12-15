#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
int n, k, dp[55][55];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("compress.inp");
    ofstream cout("compress.out");
    cin >> n >> k;
    FOR(i, 1, n) dp[i][0] = 1;
    FOR(i, 1, n)
        FOR(j, 1, k){
            dp[i][j] += dp[i-j][j-1];
        }
    cout << dp[n][k];
}
