//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define F first
#define S second
#define maxn 2212
using namespace std;
int n, m, k, d[maxn][maxn], a[maxn][maxn], dd[maxn][maxn];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void bfs(int x, int y){
    queue <pair> q;
    q.emplace(x, y);
    FOR(i, 1, m)
        FOR(j, 1, n) d[i][j] = 1e9;
    d[x][y] = 0;
    while(q.size()){
        pair s = q.front(); q.pop();
        FOR(h, 0, 3){
            FOR(i, 1, k){
                int u = s.F + dx[h] * i, v = s.S + dy[h] * i;
                if(!a[u][v]) break;
                if(d[u][v] <= d[s.F][s.S]) break;
                if(d[u][v] > d[s.F][s.S] + 1){
                    d[u][v] = d[s.F][s.S] + 1;
                    q.emplace(u, v);
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("flash.inp");
    ofstream cout("flash.out");
    cin >> m >> n >> k;
    FOR(i, 1, m)
        FOR(j, 1, n){
            char x; cin >> x;
            if(x == '.') a[i][j] = 1;
        }
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    bfs(xs, ys);
    if(d[xt][yt] == 1e9) cout << -1;
    else cout << d[xt][yt];
}
