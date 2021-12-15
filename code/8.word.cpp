//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005
using namespace std;
int m, n, d, Next[maxn][2], send[maxn], link[maxn], cnt, ans;
string t[maxn];
void Add(string s){
    int u = 0;
    for(int i = 0; s[i]; i++){
        int v = s[i] - '0';
        if(!Next[u][v]) Next[u][v] = ++cnt;
        u = Next[u][v];
    }
    send[u] = 1;
}
int get_Next(int u, int k){
    while(u != -1){
        if(Next[u][k]) return Next[u][k];
        u = link[u];
    }
    return 0;
}
void Bfs(){
    queue <int> q;
    q.push(0);
    link[0] = -1;
    while(q.size()){
        int u = q.front(); q.pop();
        FOR(p, 0, 1){
            if(Next[u][p]){
                int v = Next[u][p];
                link[v] = get_Next(link[u], p);
                send[v] += send[link[v]];
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("word.inp");
    ofstream cout("word.out");
    cin >> m >> n;
    FOR(i, 1, m){
        char x;
        FOR(j, 1, n) cin >> x, t[i] += x;
    }

    cin >> d;
    while(d--){
        string s; cin >> s;
        Add(s);
    }
    Bfs();
    FOR(i, 1, m){
        int p = 0;
        for(int j = 0; t[i][j]; j++){
            p = get_Next(p, t[i][j] - '0');
            ans += send[p];
        }
    }
    cout << ans;
}
