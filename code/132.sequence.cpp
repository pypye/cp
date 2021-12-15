#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 3005
using namespace std;
int n;
long long a[maxn], b[maxn], dp[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("sequence.inp");
    //ofstream cout("sequence.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i] -= i, b[i] = a[i];
    sort(b+1, b+n+1);
    FOR(i, 1, n){
        long long k = 1e18;
        FOR(j, 1, n){
            if(k > dp[i-1][j])  = dp[i-1][j], pos = j;
            dp[i][j] = k + abs(a[i] - b[j]);
            tr[i][j] = pos;
        }
    }
    long long ans = 1e18;
    FOR(i, 1, n) ans = min(ans, dp[n][i]);
    cout << ans;
}
