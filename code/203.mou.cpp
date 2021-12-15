//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 1000005
using namespace std;
int n, base, a[maxn], mod = 1000000009;
long long dp[maxn];
map <int, long long> M;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("mou.inp");
    ofstream cout("mou.out");
    cin >> n;
    cin >> base;
    FOR(i, 1, n-1){
        int x; cin >> x;
        a[i] = x - base;
        base = x;
    }
    dp[0] = 1;
    FOR(i, 1, n-1){
        dp[i] = (2 * dp[i-1] - M[a[i]] + mod) % mod;
        M[a[i]] = (M[a[i]] + dp[i] - dp[i-1] + mod) % mod;
    }
    cout << dp[n-1] - 1;
}
