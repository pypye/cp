#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
template <typename R, typename D> inline void Min(R &a, D b){if(a>b) a=b;}
template <typename D, typename R> inline void Max(D &a, R b){if(a<b) a=b;}
int n, m, par[maxn];
unordered_set <int> a[maxn];
vector <int> res[maxn];
unordered_map <int, int> M[maxn];
queue <int> q;
void Add(int u, int v){
    if(!M[u][v]){
        M[u][v] = M[v][u] = 1;
        res[u].push_back(v);
        res[v].push_back(u);
    }
}
void dfs(int u){
    par[u] = 1;
    write(u);
    for(auto v : res[u]) if(!par[v]) dfs(v);
}
int main()
{
    freopen("polygon.inp", "r", stdin);
    //freopen("polygon.out", "w", stdout);
    read(n); read(m);
    FOR(i, 1, n+m){
        int u, v;
        read(u); read(v);
        a[u].insert(v);
        a[v].insert(u);
    }
    FOR(i, 1, n) if(a[i].size() == 2)
    q.push(i);
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(a[x].size() < 2) continue;
        int u = 0, v = 0;
        for (auto it = a[x].begin(); it != a[x].end(); ++it){
            if(!u) {u = *it; continue;}
            v = *it;
        }
        if(!M[u][v]){
            M[u][v] = M[v][u] = 2;
            a[u].insert(v);
            a[v].insert(u);
        }
        Add(u, x);
        Add(x, v);
        if(a[u].find(x) != a[u].end()) a[u].erase(x);
        if(a[v].find(x) != a[u].end()) a[v].erase(x);
        if(a[u].size() == 2) q.push(u);
        if(a[v].size() == 2) q.push(v);
    }
    sort(res[1].begin(), res[1].end());
    dfs(1);
}
