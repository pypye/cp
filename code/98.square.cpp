#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 2005
using namespace std;
int n, m, q, a[maxn][maxn], f[maxn][maxn], dp[maxn][maxn], g[maxn][maxn], res[maxn][maxn];
int get(int x, int y, int u, int v){
    return f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("square.inp");
   //ofstream cout("square.out");
    cin >> n >> m;
    FOR(i, 1, n)
        FOR(j, 1, m){
            char x; cin >> x;
            if(x == '#') a[i][j] = 1;
        }
    FOR(i, 1, n)
        FOR(j, 1, m) f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
    FOR(i, 1, n)
        FOR(j, 1, m){
            int l = 0, r = min(n-i, m-j) + 2;
            while(r - l > 1){
                int mid = (l + r) / 2;
                if(get(i, j, i+mid-1, j+mid-1) > 0) r = mid;
                else l = mid;
            }
            dp[i][j] = l;
        }
    FOR(i, 1, n){
        priority_queue <pair> q;
        FOR(j, 1, m) if(a[i][j] == 0){
            q.push({dp[i][j], j});
            while(q.size() && q.top().second + q.top().first - 1< j) q.pop();
            g[i][j] = q.top().first;
        }
    }
    FOR(j, 1, m){
        priority_queue <pair> q;
        FOR(i, 1, n)if(a[i][j] == 0){
            q.push({g[i][j], i});
            while(q.size() && q.top().second + q.top().first - 1 < i) q.pop();
            res[i][j] = q.top().first;
        }
    }
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << res[x][y] * res[x][y] << '\n';
    }
}
