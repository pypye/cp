#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 100005
using namespace std;
int n, res, a[maxn], f[maxn], g[maxn], fen[maxn];
void update(int x, int val){
    for(; x <= maxn; x += x & -x) fen[x] = max(fen[x], val);
}
int get(int x){
    int ans = 0;
    for(; x; x -= x & -x) ans = max(ans, fen[x]);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("seq.inp");
    ofstream cout("seq.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n){
        f[i] = get(a[i]-1) + 1;
        update(a[i], f[i]);
        res = max(res, f[i]);
    }
    memset(fen, 0, sizeof fen);
    FORR(i, n, 1){
        g[i] = get(a[i]-1) + 1;
        update(a[i], g[i]);
        res = max(res, g[i]);
    }
    FOR(i, 1, n) res = max(res, f[i] + g[i] - 1);
    cout << res;
}
