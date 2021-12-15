#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005
using namespace std;
int n, s, t, cnt, tr[1005], check, maxflow;
struct flow{
    int u, v, c, f;
} a[2*maxn];
vector <int> Edge[2005];
void Add(int u, int v, int w){
    Edge[u].push_back(cnt);
    a[cnt++] = {u, v, w, 0};
    Edge[v].push_back(cnt);
    a[cnt++] = {v, u, 0, 0};
}
bool BFS(){
    memset(tr, 0, sizeof tr);
    tr[s] = -1;
    queue <int> q;
    q.push(s);
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto id : Edge[u]){
            int v = a[id].v;
            if(!tr[v] && a[id].c > a[id].f){
                tr[v] = id;
                q.push(v);
                if(v == t) return 1;
            }
        }
    }
    return 0;
}
void IncFlow(){
    int del = INT_MAX, v = t;
    while(v != s){
        int id = tr[v];
        del = min(del, a[id].c - a[id].f);
        v = a[id].u;
    }
    v = t;
    while(v != s){
        int id = tr[v];
        a[id].f += del;
        a[id^1].f -= del;
        v = a[id].u;
    }
    maxflow += del;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("gifts.inp");
    //ofstream cout("gifts.out");
    cin >> n;
    s = 0, t = 2*n+1;
    FOR(i, 1, n){
        int x, y;
        cin >> x >> y;
        if(x) Add(s, i, x);
        if(y) Add(i+n, t, y);
    }
    FOR(i, 1, n)
        FOR(j, 1, n)
            if(i != j) Add(j, i+n, 1);
    while(BFS()) IncFlow();
    FOR(id, 1, cnt){
        if(a[id].u == s || a[id].v == s) continue;
        if(a[id].u == t || a[id].v == t) continue;
        if(a[id].f == 1) check = 1, cout << a[id].v - n << " " << a[id].u << '\n';
    }
    if(!check) cout << "0 0";
}
