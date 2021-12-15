//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 1000005

using namespace std;
int n, a[1005][1005], r[maxn], ans;
vector <int> q;
vector <pair <int, int>> st[maxn];
int encode(int x, int y){
    return n*(x-1) + y;
}
int gr(int u){
    return r[u] >= 0 ? r[u] = gr(r[u]) : u;
}
void add(int u, int v){
    int p = gr(u), q = gr(v);
    if(p > q) swap(p, q);
    if(p != q){
        r[q] += r[p];
        r[p] = q;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("rselect.inp");
    ofstream cout("rselect.out");
    cin >> n;
    FOR(i, 1, n)
        FOR(j, 1, n) cin >> a[i][j];
    FOR(i, 1, n)
        FOR(j, 1, n){
            if(i < n){
                int x = abs(a[i][j] - a[i+1][j]);
                q.push_back(x);
                st[x].push_back({encode(i, j), encode(i+1, j)});
            }
            if(j < n){
                int x = abs(a[i][j] - a[i][j+1]);
                q.push_back(x);
                st[x].push_back({encode(i, j), encode(i, j+1)});
            }
        }
    sort(q.begin(), q.end());
    q.resize(unique(q.begin(), q.end()) - q.begin());
    for(auto del : q){
        for(auto v : st[del]) r[v.F] = r[v.S] = -1;
        for(auto v : st[del]) add(v.F, v.S);
        for(auto v : st[del]) ans = max(ans, max(-r[v.F], -r[v.S]));
    }
    cout << ans;
}

