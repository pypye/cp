#include <bits/stdc++.h>
#define FOR(i, x, y) for (int i = x; i <= y; ++i)
#define FORR(i, x, y) for (int i = x; i >= y; --i)
#define maxn 100001
#define maxm 100001
#define Task "CNODE"
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
int n, m, cnt, dem;
vector<int> a[maxm];
int low[maxn], id[maxn], tr[maxn], khop[maxn];
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
    id[u] = low[u] = ++dem;
    int nb = 0;
    for (int v : a[u])
        if (v != tr[u])
            if (tr[v] != 0)
                low[u] = min(low[u], id[v]);
            else
            {
                tr[v] = u;
                TJ(v);
                low[u] = min(low[u], low[v]);
                if (low[v] >= id[u])
                    nb++;
            }
    if (nb + (tr[u] != -1) >= 2)
        khop[++cnt] = u;
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
    if (id[i] == 0)
    {
        tr[i] = -1;
        TJ(i);
    }
    cout << cnt << "\n";
    sort(khop + 1, khop + cnt + 1);
    FOR(i, 1, cnt)
    cout << khop[i] << " ";
}
