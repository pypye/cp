#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1005

using namespace std;
using Array = int[maxn][maxn];
int n, m, c;
long long x, y, z;
Array a, b, top, bot, f;
void down(){
    FOR(i, 1, n)
        FOR(j, 1, m) top[i][j] = max(max(top[i-1][j-1], top[i-1][j]), top[i-1][j+1]) + b[i][j];
    FOR(i, 1, n)
        FOR(j, 1, m) if(a[i][j]) x = max(x, 1ll * top[i][j]);
}
void door(){
    FOR(i, 1, n)
        FOR(j, 1, m){
            f[i][j] = max(max(f[i-1][j-1], f[i-1][j]), f[i-1][j+1]) + b[i][j];
            if(a[i][j]) f[i][j] = max(f[i][j], b[i][j]);
        }
    FOR(i, 1, n)
        FOR(j, 1, m) if(a[i][j]) y = max(y, 1ll * f[i][j]);
    FOR(i, 1, m) z = max(z, 1ll * f[n][i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("mdoor.inp");
    ofstream cout("mdoor.out");
    cin >> n >> m >> c;
    FOR(i, 1, n)
        FOR(j, 1, m) cin >> a[i][j];
    FOR(i, 1, n)
        FOR(j, 1, m) cin >> b[i][j], top[i][j] = bot[i][j];
    FOR(i, 0, n)
        FOR(j, 0, m) f[i][j] = -1e9;
    down();
    door();
    if(c == 0) cout << *max_element(top[n]+1, top[n]+m+1);
    else cout << x + 1ll * (c-1) * y + z;
}
