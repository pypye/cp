#include <bits/stdc++.h>
#define FOR(i, x, y) for (int i = x; i <= y; ++i)
#define FORR(i, x, y) for (int i = x; i >= y; --i)
#define maxn 101
#define Task "SCONNECT"
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
int n, m, cnt;
vector<int> a[5001], d[5001];
int low[maxn], id[maxn], dem;
int s[maxn];
int top;
int tplt[maxn];
void nhap()
{
    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
    }
}
void DFS(int u)
{
    low[u] = id[u] = ++dem;
    s[++top] = u;
    for (int &v : a[u])
    {
        if (tplt[v] == 0)
            if (id[v] == 0)
            {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
            else
                low[u] = min(low[u], id[v]);
    }
    if (low[u] == id[u])
    {
        cnt++;
        int x;
        do
        {
            x = s[top--];
            tplt[x] = cnt;
            d[cnt].pb(x);
        } while (x != u);
    }
}
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(Task ".inp", "r", stdin);
    freopen(Task ".out", "w", stdout);
    nhap();
    FOR(i, 1, n)
    if (!id[i])
        DFS(i);
    FOR(i, 1, cnt)
    {
        FOR(j, 0, d[i].size() - 1)
        cout << d[i][j] << " ";
        cout << " \n";
    }
}
