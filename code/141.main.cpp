//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 400005
using namespace std;
int n, q, Next[maxn][26], cnt[maxn][26][26], str[maxn], sub[maxn], link[maxn], dem;
vector <int> id[maxn];
void Add(string s, int x){
    int u = 0;
    for(int i = 0; s[i]; i++){
        int v = s[i] - 'a';
        if(!Next[u][v]) Next[u][v] = ++dem;
        u = Next[u][v];
    }
    id[u].push_back(x);
    link[x] = u;
}
void Find(int u){
    FOR(p, 0, 25)
        if(Next[u][p]){
            int v = Next[u][p];
            Find(v);
            copy(id[v].begin(), id[v].end(), back_inserter(id[u]));
        }
}
void dfs(int u){
    FOR(p, 0, 25){
        FOR(q, 0, 25){
                if(p == q) continue;
                if(!Next[u][p] || !Next[u][q]) continue;
                for(auto x : id[Next[u][p]]) cnt[x][p][q] += id[Next[u][q]].size();
            }
        if(Next[u][p]) dfs(Next[u][p]);
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    ifstream cin("inp.txt");
    cin >> n;
    FOR(i, 1, n){
        string s;
        cin >> s;
        Add(s, i);
    }
    Find(0);
    dfs(0);
    cin >> q;
    while(q--){
        string s;
        int ans = n, k;
        cin >> k >> s;
        FOR(i, 0, 25)
            FOR(j, i+1, 25){
                int u = s[i] - 'a', v = s[j] - 'a';
                ans -= cnt[k][u][v];
            }
        cout << ans - id[link[k]].size() + 1 << '\n';
    }
}

