#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 2005
using namespace std;
int n, a[maxn], ans, mod = 30103, T[maxn][maxn];
void update(int p, int q, int v){
    for(int i = p; i <= n + 5; i += i & -i)
        for(int j = q; j <= 2000; j += j & -j) (T[i][j] += v) %= mod;
}
int get(int p, int q){
    int ans = 0;
    for(int i = p; i; i -= i & -i)
        for(int j = q; j; j -= j & -j) (ans += T[i][j]) %= mod;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("seq2015.inp");
    //ofstream cout("seq2015.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FORR(i, n, 2)
        FORR(j, i-1, 1){
            int F = (get(j-1, 2000) - get(j-1, a[i] + a[j]) + mod + 1) % mod;
            ans = (ans + F - 1 + mod) % mod;
            update(j, a[i] + a[j], F);
        }
    cout << ans;
}
