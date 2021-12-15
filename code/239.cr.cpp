#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn
using namespace std;
int m, n, l, x, y, z;
long long s[105][105][5005], t[105][105][5005], ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("cr.inp");
    //ofstream cout("cr.out");
    cin >> m >> n >> l >> x >> y >> z;
    s[1][0][0] = t[0][1][0] = s[1][1][0] = t[1][1][0] = 1;
    FOR(i, 1, m)
        FOR(k, 0, l) if(k >= x) s[i][0][k] += s[i-1][0][k-x];
    FOR(i, 1, n)
        FOR(k, 0, l) if(k >= y) t[0][i][k] += t[0][i-1][k-y];
    FOR(i, 1, m)
        FOR(j, 1, n){
            FOR(k, 1, l){
                if(k >= x) s[i][j][k] += s[i-1][j][k-x];
                if(k >= y) t[i][j][k] += t[i][j-1][k-y];
                if(k >= z * abs(i - j)){
                    s[i][j][k] += t[i-1][j][k-z*abs(i-j)];
                    t[i][j][k] += s[i][j-1][k-z*abs(i-j)];
                }
            }
        }
    FOR(k, 0, l)
        ans += s[m][n][k] + t[m][n][k];
    cout << ans;
}
