#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 300005
#define F first
#define S second
using namespace std;
int n, h, low[maxn], sum[maxn], ans;
pair <int, int> a[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    ifstream cin("glinder.inp");
//    ofstream cout("glinder.out");
    cin >> n >> h;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;
    a[n+1].F = 2e9;
    FOR(i, 1, n){
        low[i] = low[i-1] + a[i+1].F  - a[i].S;
        sum[i] = sum[i-1] + a[i].S - a[i].F;
    }
    FOR(i, 1, n){
        int k = lower_bound(low+1, low+n+1, low[i-1] + h) - low;
        ans = max(ans, sum[k] - sum[i-1] +  h);
    }
    cout << ans;
}
