#include <bits/stdc++.h>
#define FOR(i, x, y) for (int i = x; i <= y; ++i)
#define FORR(i, x, y) for (int i = x; i >= y; --i)
#define maxn 100001
#define maxm 100001
#define Task "CBRIDGE"
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
int n, m, dem, cnt;
pii cau[maxm];
vector<int> a[maxn], d[maxn];
int tr[maxn], low[maxn], id[maxn];
void nhap()
{
    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
}
void TJ(int u)
{
    low[u] = id[u] = ++dem;
    for (int v : a[u])
        if (v != tr[u])
            if (tr[v] != 0)
                low[u] = min(low[u], id[v]);
            else
            {
                tr[v] = u;
                TJ(v);
                low[u] = min(low[u], low[v]);
                if (low[v] == id[v])
                    cau[++cnt] = mp(u, v);
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
    {
        tr[i] = -1;
        TJ(i);
    }
    cout << cnt << "\n";
    FORN(i, cnt, 1)
    {
        cout << cau[i].F << " " << cau[i].S << "\n";
    }
}
