#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, m;
long long k, T, a[maxn], ans;
long long sum(long long l, long long r){
    if(r < l) return 0;
    return (l + r) * (r - l + 1) / 2 + T * (r - l + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("spasta.inp");
    ofstream cout("spasta.out");
    cin >> m >> k >> n >> T;
    FOR(i, 1, n) cin >> a[i];
    a[n+1] = m+1;
    sort(a+1, a+n+1);
    if(m - n < k) return cout << -1, 0;
    FOR(i, 1, n+1){
        ans += min(sum(a[i-1]+1, a[i]-1), sum(a[i-1]+1, a[i-1]+k));
        k -= min(a[i] - a[i-1] - 1, k);
        if(k <= 0) break;
    }
    cout << ans;
}
