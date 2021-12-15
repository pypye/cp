#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 10005
#define F first
#define S second
using namespace std;
int n, w, h, s, t, maxflow, c[maxn][maxn], f[maxn][maxn], tr[maxn];
pair <int, int> a[205][205];
vector <int> edge[maxn];
void add(int u, int v, int w){
    edge[u].push_back(v);
    edge[v].push_back(u);
    c[u][v] = w;
}
bool FindPath(){
    memset(tr, 0, sizeof tr);
    queue <int> q;
    q.push(s);
    tr[s] = -1;
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto v : edge[u]) if(!tr[v] && c[u][v] > f[u][v]){
            tr[v] = u;
            q.push(v);
        }
    }
    return tr[t];
}
void IncFlow(){
    int del = 1e9, u = t;
    while(u != s){
        int v = tr[u];
        del = min(del, c[v][u] - f[v][u]);
        u = v;
    }
    u = t;
    while(u != s){
        int v = tr[u];
        f[u][v] -= del;
        f[v][u] += del;
        u = v;
    }
    maxflow += del;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("maytap.inp");
    ofstream cout("maytap.out");
    cin >> n >> w >> h;
    s = 0, t = 2 * n + 1;
    FOR(i, 1, n){
        int x, y;
        cin >> x >> y;
        a[x][y] = make_pair(1, i);
        add(i, i+n, 1);
        if((x + y) & 1) add(s, i, 1e9);
        else add(i+n, t, 1e9);
    }
    FOR(i, 1, w)
        FOR(j, 1, h){
            if(a[i][j].F && (i + j) & 1){
                if(a[i-1][j].F) add(a[i][j].S + n, a[i-1][j].S, 1);
                if(a[i+1][j].F) add(a[i][j].S + n, a[i+1][j].S, 1);
                if(a[i][j-1].F) add(a[i][j].S + n, a[i][j-1].S, 1);
                if(a[i][j+1].F) add(a[i][j].S + n, a[i][j+1].S, 1);
            }
        }
    while(FindPath()) IncFlow();
    cout << n - maxflow;

}
