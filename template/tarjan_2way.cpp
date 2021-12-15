/**Lucky Boy**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 100005
#define maxm 1000006
#define pii pair<int, int>
#define Task ""
using namespace std;
int n, m, ans, s[maxn], top, num[maxn], low[maxn], cnt, lt[maxn], par[maxn];
vector<int> a[maxn];
void dfs(int u)
{
    num[u] = low[u] = ++cnt;
    s[++top] = u;
    for (int v : a[u])
        if (!lt[v])
        {
            if (num[v])
            {
                if (par[u] != v)
                    low[u] = min(low[u], num[v]);
            }
            else
            {
                par[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    if (num[u] == low[u])
    {
        ++ans;
        while (s[top] != u)
        {
            lt[s[top--]] = ans;
        }
        lt[s[top--]] = ans;
    }
}
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(Task ".inp", "r", stdin);
    //freopens(Task".out", "w",stdout);
    cin >> n >> m;
    FOR(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    FOR(i, 1, n)
    if (!num[i])
        cnt = 0, dfs(i);
    cout << ans;
    return 0;
}
