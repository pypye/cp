#include <bits/stdc++.h>
#define FOR(i,x,y) for(int i = x; i <= y ; ++i)
#define maxn 501
#define maxm 501
using namespace std;
int n, m, q, x, x1, x2, y2, y1 ;
int f[10][10][maxm][maxn];
int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
    freopen(Task".inp" , "r" , stdin);
    freopen(Task".out" , "w" , stdout);
    cin >> m >> n;
    FOR(i, 1, m)
        FOR(j, 1, n)
            cin >> x, f[0][0][i][j] = x;
    FOR(i,1,9)
        FOR(u, 1, m)
            FOR(v, 1, n- (1<< i) + 1 )
                f[0][i][u][v] = min(f[0][i-1][u][v], f[0][i-1][u][v+(1<<(i-1))]);
    FOR(i, 1 , 9)
        FOR(j, 0, 9)
            FOR(u, 1, m - (1 << i) +1)
                FOR(v, 1, n)
                    f[i][j][u][v] = min(f[i-1][j][u][v], f[i-1][j][u + (1<<(i-1))][v]);
    cin >> q;
    while(q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int k1 = log2(x2-x1+1);
        int k2 = log2(y2-y1+1);
        cout << min(min (f[k1][k2][x1][y1], f[k1][k2][x1][y2- (1<<k2)+1]), min(f[k1][k2][x2-(1<< k1)+1][y1],f[k1][k2][x2-(1<<k1)+1][y2-(1 << k2)+1])) << "\n";
    }

}
