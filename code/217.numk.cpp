#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005
using namespace std;
int k, M, a[maxn], tr[maxn];
pair <int, int> f[maxn];
queue <int> q;
vector <int> ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("numk.inp");
    //ofstream cout("numk.out");
    cin >> k >> M;
    FOR(i, 1, k) cin >> a[i];
    FOR(i, 0, 1000000)
        f[i] = {INT_MAX, INT_MAX};
    FOR(i, 1, k)
        if(f[a[i] % M].second > a[i] && a[i]){
            f[a[i] % M] = {1, a[i]};
            q.push(a[i] % M);
        }
    while(q.size()){
        int u = q.front(); q.pop();
        FOR(i, 1, k){
            int v = (u * 10 + a[i]) % M;
            if(f[v].first > f[u].first + 1){
                f[v] = {f[u].first + 1, a[i]};
                tr[v] = u;
                q.push(v);
            }
        }
    }
    if(f[0].first == INT_MAX) return cout << -1, 0;
    int t = 0;
    do{
        ans.push_back(f[t].second);
        t = tr[t];
    }
    while(t);
    reverse(ans.begin(), ans.end());
    for(auto v : ans) cout << v;

}
