#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 100005
using namespace std;
int n, m, p[maxn], fen[maxn], res[maxn];
vector <int> a[maxn];
void compress(){
    vector <int> s;
    FOR(i, 1, n) s.push_back(p[i]);
    sort(s.begin(),s.end());
    FOR(i, 1, n) p[i] = lower_bound(s.begin(), s.end(), p[i]) - s.begin() + 1;
}
void update(int x, int val){
    for(; x; x -= x & -x) fen[x] += val;
}
int get(int x){
    int ans = 0;
    for(; x <= n+1; x += x & -x) ans += fen[x];
    return ans;
}
void dfs(int u, int par){
    res[u] = get(p[u]+1);
    update(p[u], 1);
    for(auto v : a[u])
        if(v != par){
            dfs(v, u);
        }
    res[u] = get(p[u]+1) - res[u];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("greater.inp");
    ofstream cout("greater.out");
    cin >> n;
    FOR(i, 1, n) cin >> p[i];
    compress();
    FOR(i, 1, n-1){
        int u;
        cin >> u;
        a[u].push_back(i+1);
    }
    dfs(1, -1);
    FOR(i, 1, n) cout << res[i] << '\n';
}
