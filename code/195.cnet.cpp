//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 505
using namespace std;
int T, n, m, k, s, t, f[maxn][maxn], tr[maxn], stop[maxn], maxc, st;
vector <int> a[maxn];
void reset(){
    memset(f, 0, sizeof f);
    memset(stop, 0, sizeof stop);
    FOR(i, 1, n) a[i].clear();
    maxc = 1; st = 0;
}
bool BFS(){
    memset(tr, 0, sizeof tr);
    queue <int> q;
    q.push(s);
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto v : a[u]){
            if (!tr[v] && maxc > f[u][v] + f[v][u]){
                tr[v] = u;
                q.push(v);
                if(stop[v]) return st = v, 1;
            }
        }
        for(auto v : a[u]){
            if (!tr[v] && f[v][u] > 0){
                tr[v] = -u;
                q.push(v);
            }
        }
    }
    return 0;
}

void IncFlow(){
    stop[st] = 0;
    int v = st;
    while (v != s){
        int u = tr[v];
        if(u > 0) f[u][v]++;
        else u = -u, f[v][u]--;
        v = u;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("cnet.inp");
    ofstream cout("cnet.out");
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        s = 1, t = n+1;
        reset();
        FOR(i, 1, k){
            int x; cin >> x;
            stop[x] = 1;
        }
        while(m--){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        FOR(i, 1, k){
            while(!BFS()) maxc++;
            IncFlow();
        }
        cout << maxc << '\n';
    }
}
