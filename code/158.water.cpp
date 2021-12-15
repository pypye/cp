#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 200005
using namespace std;
int n, m, p[maxn][22], ans = 1e9;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    ifstream cin("water.inp");
//    ofstream cout("water.out");
    cin >> n >> m;
    FOR(i, 1, m){
        int l, r;
        cin >> l >> r;
        if(r < l){
            p[1][0] = max(p[1][0], r);
            r += n;
        }
        p[l][0] = max(p[l][0], r);
    }
    FOR(u, 1, n){
        p[u][0] = max(p[u][0], p[u-1][0]);
        if(p[u][0] < u) return cout << -1, 0;
        p[u+n][0] = min(n, p[u][0]) + n;
    }
    FOR(i, 0, 20) p[n+n][i] = p[n+n+1][i] = n+n;
    FOR(i, 1, 20)
        FOR(u, 1, n+n-1)
             p[u][i] = p[p[u][i-1] + 1][i-1];
    FOR(u, 1, n){
        int res = 1, x = u;
        FORR(i, 20, 0){
            if(p[x][i] < u+n-1){
                res += (1 << i);
                x = p[x][i] + 1;
            }
        }
        ans = min(ans, res);
    }
    cout << m - ans;
}
