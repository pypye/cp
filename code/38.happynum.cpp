//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 105
using namespace std;
int n, k, a[105], s[105], sum, mod = 1000000007;
long long pw[55], dp[105][8105], L[105][55][8105], R[105][5][8105];
int sumdigit(int x){
    int ans = 0;
    while(x) ans += x % 10, x /= 10;
    return ans;
}
long long mul(long long x, int y){
    x *= y;
    x %= mod;
    return x;
}
void Calc1(){
    if(sum & 1) cout << 0, exit(0);
    dp[0][0] = 1;
    FOR(j, 1, n)
        FORR(i, n/2, 1)
            FORR(x, sum/2, s[j]){
                dp[i][x] += dp[i-1][x-s[j]];
                dp[i][x] %= mod;
            }
    cout << mul(mul(dp[n/2][sum/2], pw[n/2]), pw[n/2]);
}
long long proc(int i){
    int msum = sum;
    msum = sum - a[i];
    if(msum & 1) return 0;
    msum /= 2;
    long long res = 0;
    FOR(j, 0, i-1)
        FOR(x, 0, msum){
            res += mul(L[i-1][j][x], R[i+1][n/2-j][msum-x]);
            res %= mod;
        }
    return mul(mul(res, pw[n/2]), pw[n/2]);
}
void Calc2(){
    FOR(i, 0, n+1) L[i][0][0] = R[i][0][0] = 1;
    FOR(i, 1, n)
        FOR(j, 1, i)
            FORR(x, sum/2, 0){
                if(x >= s[i]) L[i][j][x] += L[i-1][j-1][x-s[i]] + L[i-1][j][x];
                else L[i][j][x] += L[i-1][j][x];
                L[i][j][x] %= mod;
            }
    FORR(i, n, 1)
        FOR(j, 1, n-i+1)
            FORR(x, sum/2, 0){
                if(x >= s[i]) R[i][j][x] += R[i+1][j-1][x-s[i]] + R[i+1][j][x];
                else R[i][j][x] += R[i+1][j][x];
                R[i][j][x] %= mod;
            }
    long long ans = 0;
    FOR(i, 1, n) ans = (ans + proc(i));
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("happynum.inp", "r", stdin);
    freopen("happynum.out", "w", stdout);
    cin >> n >> k;
    FOR(i, 1, n){
        cin >> a[i];
        s[i] = sumdigit(a[i]);
        sum += s[i];
    }
    pw[0] = 1;
    FOR(i, 1, n/2) pw[i] = (pw[i-1] * i) % mod;
    if(n & 1) Calc2();
    else Calc1();
}
