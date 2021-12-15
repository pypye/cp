//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 2005
using namespace std;
int m, n, a, b, c, d, f[maxn][maxn], py[maxn][maxn];
pair <int, pair<int, int>> ngang[maxn][maxn], doc[maxn][maxn];
int get(int x, int y, int u, int v){
    return f[u][v] - f[u][y-1] - f[x-1][v] + f[x-1][y-1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("pyramid.inp");
    ofstream cout("pyramid.out");
    cin >> m >> n >> a >> b >> c >> d;
    int km = a - c - 1;
    int kn = b - d - 1;
    FOR(i, 1, n)
        FOR(j, 1, m){
            int x; cin >> x;
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + x;
        }
    FOR(i, d, n)
        FOR(j, c, m) py[i][j] = get(i-d+1, j-c+1, i, j);
    FOR(i, d, n){
        priority_queue <pair <int, pair<int, int>>> q;
        FOR(j, c, m){
            while(q.size() && q.top().S.S + c - 1 < j - km + 1) q.pop();
            q.push({-py[i][j], {i-d+1, j-c+1}});
            if(j >= c + km) ngang[i][j] = {-q.top().F, q.top().S};
        }
    }
    FOR(j, c, m){
        priority_queue <pair <int, pair<int, int>>> q;
        FOR(i, d, n){
            while(q.size() && q.top().S.F + d - 1 < i - kn + 1) q.pop();
            q.push({-ngang[i][j].F, ngang[i][j].S});
            if(i >= d + kn) doc[i][j] = {-q.top().F, q.top().S};
        }
    }
    pair <int, int> in, out;
    int ans = 0;
    FOR(i, b, n)
        FOR(j, a, m){
            if(ans < get(i-b+1, j-a+1, i, j) - doc[i-1][j-1].F){
                ans = get(i-b+1, j-a+1, i, j) - doc[i-1][j-1].F;
                out = {i-b+1, j-a+1};
                in = doc[i-1][j-1].S;
            }
        }
    cout << out.S << " " << out.F << '\n';
    cout << in.S << " " << in.F << '\n';
}
