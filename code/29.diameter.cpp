//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 1000005

using namespace std;
int n, ans, b[maxn], d[maxn], pos, M[maxn];
vector <int> a[maxn];
set <int> s;
void dfs(int u, int par = -1){
    for(auto v : a[u]){
        if(v != par){
            d[v] = d[u] + 1;
            if(ans < d[v]){
                ans = d[v];
                pos = v;
            }
            dfs(v, u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("diameter.inp");
//    ofstream cout("diameter.out");
    cin >> n;
    FOR(i, 1, n) cin >> b[i], M[b[i]]++;
    FOR(i, 1, n+2) if(M[i] == 0) s.insert(i);
    FOR(i, 1, n){
        int x = *s.begin(); s.erase(x);
        a[x].push_back(b[i]);
        a[b[i]].push_back(x);
        M[b[i]]--;
        if(M[b[i]] == 0) s.insert(b[i]);
    }
    int x = *s.begin(); s.erase(x);
    a[x].push_back(*s.begin());
    a[*s.begin()].push_back(x);

    dfs(1);
    ans = 0;
    memset(d, 0, sizeof d);
    dfs(pos);
    cout << ans;
}
