#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 100005
#define maxm 1000005
using namespace std;
int n, a[maxn], d[maxm];
long long f[maxm], ans, mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("ctree.inp");
    ofstream cout("ctree.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i], d[a[i]] = 1;
    sort(a+1, a+n+1);
    n = unique(a+1, a+n+1) - a-1;
    FOR(i, 1, n) f[a[i]] = 1;
    FOR(i, 1, n){
        FOR(j, 2, sqrt(a[i])){
            if(a[i] % j == 0){
                int k = a[i]/j;
                if(d[j] && d[k]) {
                    if(j == k) f[a[i]] = (f[a[i]] + f[j] * f[k] % mod) % mod;
                    else f[a[i]] = (f[a[i]] + 2ll * f[j] * f[k] % mod) % mod;
                }
            }
        }
    }
    FOR(i, 1, n) ans = (ans + f[a[i]]) % mod;
    cout << ans;
}
