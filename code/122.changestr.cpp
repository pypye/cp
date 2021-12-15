#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 100005
#define pair pair<int, int>
#define F first
#define S second
using namespace std;
int n, m, p[maxn], d[32][32], ans = 1e9;
string s;
vector<pair> a[26];
vector <int> save;
void ijk(int s){
    priority_queue<pair> Q;
    FOR(i, 0, 25) d[s][i] = 1e9;
    d[s][s] = 0;
    Q.push({0,s});
    while(Q.size()){
        auto u = Q.top();
        Q.pop();
        if(d[s][u.S] > -u.F) continue;
        for(auto v : a[u.S])
            if(d[s][v.F] > d[s][u.S] + v.S){
                d[s][v.F] = d[s][u.S] + v.S;
                Q.push({-d[s][v.F], v.F});
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("changestr.inp");
    //ofstream cout("changestr.out");
    cin >> n >> m;
    cin >> s;
    s = ' ' + s;
    FOR(i, 1, m){
        char u, v;
        int w;
        cin >> u >> v >> w;
        a[u - 'a'].push_back({v - 'a',w});
    }
    FOR(i, 2, n) if(!p[i])
        for(int j = i+i; j <= n; j += i)
            if(!p[j]) p[j] = 1;
    FOR(i, 2, n) if(n % i == 0 && !p[i]) save.push_back(i);
    FOR(i, 0, 25) ijk(i);
    for(auto v : save){
        int cur = 0;
        FOR(i, 1, n/v){
            int minx = 1e9;
            FOR(j, 0, 25){
                int res = 0;
                for(int z = i; z <= n; z += n/v)
                {
                    int u = s[z] - 'a';
                    res += d[u][j];
                }
                minx = min(minx,res);
            }
            if(minx != 1e9) cur += minx;
            else cur = 1e9;
        }
        ans = min(ans,cur);
    }
    if(ans == 1e9) cout << -1;
    else cout << ans;
    return 0;
}
