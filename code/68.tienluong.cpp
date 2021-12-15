#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int T, n, k, p[maxn], dp[maxn][1005], in[maxn], cnt, dem, l[maxn];
vector <int> a[maxn];
vector <pair <int, int>> b[maxn];
void reset()
{
    dem = 0;
    memset(b, 0, sizeof b);
    FOR(i, 0, n) a[i].clear(), l[i] = in[i] = p[i] = 0;
    FOR(i, 1, cnt)
        FOR(j, 1, k) dp[i][j] = 0;cnt = 0;

}
void dfs(int u)
{
    int cur = ++cnt;
    for(auto v : a[u]) dfs(v);
    if(cur == cnt) dem++;
    l[u] = dem;
    b[cnt].push_back(make_pair(cur, u));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("tienluong.inp", "r", stdin);
    freopen("tienluong.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> k;
        reset();
        FOR(i, 1, n)
        {
            int u, v;
            cin >> u >> p[i];
            a[u].push_back(i);
        }
        dfs(0);
        FOR(i, 1, cnt)
            FOR(j, 1, k)
            {
                for(auto v : b[i])
                    if(j <= l[v.second]) dp[i][j] = max(dp[i][j], dp[v.first - 1][j-1] + p[v.second]);
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        cout << dp[cnt][k] << '\n';
    }
}
