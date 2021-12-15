#include <bits/stdc++.h>
#define FOR(i, x, y) for (int i = x; i <= y; ++i)
#define FORR(i, x, y) for (int i = x; i >= y; --i)
#define maxn 100001
#define maxm 200002
#define Task "minpath"
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define maxc 2e9
using namespace std;
int n, m, s, t, x;
vector<pii> a[maxm];
long long d[maxn];
int tr[maxn];
vector<int> h;
void nhap()
{
    cin >> n >> m >> s >> t;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].pb(mp(v, w));
        a[v].pb(mp(u, w));
    }
}
void cb()
{
    FOR(i, 1, n)
    d[i] = maxc;
    d[s] = 0;
}
void xuli()
{
    priority_queue<pii> Q;
    Q.push(mp(-d[s], s));
    while (!Q.empty())
    {
        pii u = Q.top();
        Q.pop();
        x = u.S;
        if (d[x] < -u.F)
            continue;
        for (auto v : a[x])
            if (d[x] + v.S < d[v.F])
            {
                d[v.F] = d[x] + v.S;
                Q.push(mp(-d[v.F], v.F));
                tr[v.F] = x;
            }
    }
}
void kq()
{
    cout << d[t] << '\n';
    while (t)
    {
        h.pb(t);
        t = tr[t];
    }
    reverse(h.begin(), h.end());
    cout << h.size() << '\n';
    for (int v : h)
        cout << v << ' ';
}
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(Task ".inp", "r", stdin);
    freopen(Task ".out", "w", stdout);
    nhap();
    cb();
    xuli();
    kq();
}
