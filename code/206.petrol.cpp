#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 50005
using namespace std;
int n, D, f[20][maxn], b[maxn], d[maxn], ans;
pair <int, int> a[maxn];
int get(int u, int v){
    int k = log2(v-u+1);
    return max(f[k][u], f[k][v - (1 << k) + 1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    ifstream cin("petrol.inp");
    ofstream cout("petrol.out");
    cin >> n >> D;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;
    sort(a+1, a+n+1);
    FOR(i, 1, n) b[i] = a[i].F, f[0][i] = a[i].S;
    b[n+1] = 2e9;
    FOR(i, 1, 17)
        FOR(u, 1, n - (1 << i) + 1) f[i][u] = max(f[i-1][u], f[i-1][u + (1 << (i-1))]);
    FOR(i, 1, n){
        int x = lower_bound(b+1, b+n+1, a[i].F - D) - b;
        int y = upper_bound(b+1, b+n+1, a[i].F + D) - b - 1;
        if(get(x, i-1) >= 2 * a[i].S && get(i+1, y) >= 2 * a[i].S) d[i] = 1, ans++;
    }
    cout << ans;
}
