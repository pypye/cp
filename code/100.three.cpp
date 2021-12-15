#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
int n, k, a[maxn];
long long dp[maxn], ans, f[21][5005];
int getmax(int u, int v){
    if(u > v) return 0;
    int k = log2(v-u+1);
    return max(f[k][u], f[k][v - (1 << k) + 1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("three.inp");
    ofstream cout("three.out");
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    if(n <= 100){
        FOR(x, 1, n)
            FOR(y, x+1, n)
                FOR(z, y+1, n)
                    if(abs(x-y) <= k && abs(y-z) <= k && abs(x-z) <= k) ans = max(ans, 1ll * a[x] * a[y] * a[z]);
        cout << ans;
        return 0;
    }
    if(n <= 5000){
        FOR(i, 1, n) f[0][i] = a[i];
        FOR(i, 1, 20)
            FOR(u, 1, n - (1 << i) + 1)
                f[i][u] = max(f[i-1][u], f[i-1][u + (1 << (i-1))]);
        FOR(i, 1, n){
            FOR(j, i+1, min(n, i+k)){
                ans = max(ans, 1ll * a[i] * a[j] * getmax(i+1, j-1));
            }
        }
        cout << ans;
        return 0;

    }
    ans = 0;
    priority_queue <pair> q;
    FOR(i, 1, n){
        if(q.size() >= 2){
            while(q.top().second < i - k) q.pop();
            pair u = q.top(); q.pop();
            while(q.top().second < i - k) q.pop();
            pair v = q.top();
            ans = max(ans, 1ll * a[i] * u.first * v.first);
            q.push({u.first, u.second});
        }
        q.push({a[i], i});
    }
    cout << ans;
}
