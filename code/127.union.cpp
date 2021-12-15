#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 1000005
using namespace std;
int n, a[105][105][105];
long long ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("union.inp");
    ofstream cout("union.out");
    cin >> n;
    FOR(i, 1, n){
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        if(z1 > z2) swap(z1, z2);
        FOR(x, x1, x2-1)
            FOR(y, y1, y2-1)
                FOR(z, z1, z2-1) a[x][y][z] = 1;
    }
    FOR(i, 0, 100)
        FOR(j, 0, 100)
            FOR(k, 0, 100) ans += a[i][j][k];
    cout << ans;
}
