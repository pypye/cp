//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <long long, int>
#define F first
#define S second
#define maxn 40005
using namespace std;
int m, n, xs, ys, xt, yt, s, t;
long long p[205][205], d[maxn];
vector <pair> a[maxn];
int convert(int x, int y){
    return n * (x-1) + y;
}
void connect(int i, int j, int x, int y){
    int u = convert(i, j), v = convert(x, y);
    long long w = p[x][y] - p[i][j];
    if(w < 0) w = 0;
    a[u].emplace_back(v, w);
}
void ijk(int s){
    priority_queue <pair> q;
    fill(d+1, d+n*m+1, 1e18);
    q.emplace(0, s);
    d[s] = 0;
    while(q.size()){
        pair x = q.top(); q.pop();
        int u = x.S;
        if(d[u] < -x.F) continue;
        for(auto v : a[u])
            if(d[v.F] > d[u] + v.S){
                d[v.F] = d[u] + v.S;
                q.emplace(-d[v.F], v.F);
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("city.inp");
    ofstream cout("city.out");
    cin >> m >> n;
    cin >> xs >> ys; s = convert(xs, ys);
    cin >> xt >> yt; t = convert(xt, yt);
    FOR(i, 1, m)
        FOR(j, 1, n) cin >> p[i][j];
    FOR(i, 1, m)
        FOR(j, 1, n){
            if(p[i][j+1]) connect(i, j, i, j+1);
            if(p[i+1][j]) connect(i, j, i+1, j);
            if(p[i][j-1]) connect(i, j, i, j-1);
            if(p[i-1][j]) connect(i, j, i-1, j);
        }
    ijk(s);
    cout << d[t];
}
