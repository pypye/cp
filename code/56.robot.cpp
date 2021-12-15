//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 1005
using namespace std;
int n, m, k, a[maxn][maxn], cnt;
long long sum;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int dir(char x){
    if(x == 'E') return 0; if(x == 'W') return 1;
    if(x == 'S') return 2; return 3;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
    cin >> n >> m >> k;
    while(k--){
        int u, v; char ty;
        cin >> u >> v >> ty;
        int x = dir(ty);
        while(u > 0 && v > 0 && u <= n && v <= m) a[u][v] = 1, u += dx[x], v += dy[x];
    }
    FOR(i, 1, n)
        FOR(j, 1, m) sum += a[i][j];
    cout << sum;
}
