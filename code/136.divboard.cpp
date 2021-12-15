#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1005
using namespace std;
int m, n, a[maxn][maxn], sum[maxn][maxn], top = 1e9, bot = 1e9, ans = 1e9, res[5];
int get(int u, int v, int x, int y){
    return sum[x][y] + sum[u-1][v-1] - sum[u-1][y] - sum[x][v-1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("divboard.inp");
    ofstream cout("divboard.out");
    cin >> m >> n;
    FOR(i, 1, m)
        FOR(j, 1, n){
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    FOR(cut, 1, m){
        top = bot = 1e9;
        FOR(i, 1, n){
            int x = get(1, 1, cut, i);
            int y = get(1, i+1, cut, n);
            if(top > abs(x-y)){
                top = abs(x-y);
                res[1] = x;res[2] = y;
            }
        }
        FOR(i, 1, n){
            int x = get(cut+1, 1, m, i);
            int y = get(cut+1, i+1, m, n);
            if(bot > abs(x-y)){
                bot = abs(x-y);
                res[3] = x; res[4] = y;
            }
        }
        int cur = 0;
        FOR(i, 1, 4)
            FOR(j, i+1, 4){
                cur = max(cur, abs(res[i]-res[j]));
            }
        ans = min(ans, cur);
    }
    cout << ans;
}
