#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1005

using namespace std;
int n, q, a[maxn], dp[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("tmachine.inp");
    //ofstream cout("tmachine.out");
    cin >> n >> q;
    FOR(i, 1, n){
        char x; cin >> x;
        a[i] = x - '0';
    }
    while(q--){
        int u, v, c;
        cin >> u >> v >> c;
        if(u > v) swap(u, v);
        memset(dp, 0, sizeof dp);
        priority_queue <pair <int, int>> q;
        dp[u] = a[u];
        q.push({-dp[u], u});
        FOR(i, u+1, v){
            while(q.size() && q.top().second + c < i) q.pop();
            dp[i] = -q.top().first + a[i];
            q.push({-dp[i], i});
        }
        cout << dp[v] << '\n';
    }
}
