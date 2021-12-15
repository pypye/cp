#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1 << 21
using namespace std;
int n;
long long k, a[21], ans, res;
long long f[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("multiple.inp");
    //ofstream cout("multiple.out");
    cin >> n >> k;
    FOR(i, 0, n-1) cin >> a[i];
    FOR(i, 1, (1 << n)-1) f[i] = 1;
    FOR(i, 1, (1 << n)-1){
        long long cur = 1;
        FOR(x, 0, n-1)
        if((i >> x) & 1){
            long long j = a[x]/__gcd(a[x], cur);
            if(k / cur  >= j) cur *= j;
            else {
                cur = k+1;
                break;
            }
        }
        f[i] = k / cur;
    }
    FOR(i, 1, (1 << n)-1){
        if(__builtin_popcount(i) % 2) ans += f[i];
        else ans -= f[i];
    }
    FOR(i, 1, (1 << n)-1){
        if(__builtin_popcount(i) % 2) res += 1ll * f[i] * __builtin_popcount(i);
        else res -= 1ll * f[i] * __builtin_popcount(i);
    }
    cout << ans << " " << res;
}
