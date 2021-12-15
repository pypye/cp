//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 10000005
using namespace std;
int n;
long long delta, p, q, m, a[maxn], sum[maxn], ans = 1e18;
pair <long long, int> d[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("period.inp", "r", stdin);
    freopen("period.out", "w", stdout);
    cin >> n >> delta;
    cin >> p >> q >> m;
    if(n <= 1000){
        FOR(i, 1, n) a[i] = a[i+n] = (1ll * p * i) % m + q, sum[i] = 1ll * delta * i;
        FOR(i, 1, n){
            long long res = 0;
            FOR(j, i, i+n-1){
                res = max(res, sum[j-i+1] + a[j]);
            }
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
    else{
        FOR(i, 1, n) a[i] = a[i+n] = (1ll * p * i) % m + q;
        FOR(i, 1, 2*n) sum[i] = 1ll * delta * i;
        int top = 0, bot = -1;
        FOR(i, 1, 2*n){
            while(bot >= top && d[top].S <= i-n) ++top;
            while(bot >= top && d[bot].F < a[i] + sum[i]) --bot;
            d[++bot] = {a[i] + sum[i], i};
            if(i >= n) ans = min(ans, d[top].F - 1ll * (i-n) * delta);
        }
        cout << ans;
    }
}
