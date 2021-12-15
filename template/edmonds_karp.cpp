#include <bits/stdc++.h>
#define maxn 1003
#define maxm 100003

using namespace std;

struct data
{
    int u = 0, v = 0, c = 0, f = 0;
};

int n, m, st, ed, tr[maxn], qu[maxn];
long long maxf = 0;
vector <int> s[maxn];

data edge[maxm * 2];

void inpa()
{
    int q = 0;
    cin >> n >> m >> st >> ed;
    for (int u, v, cv, i = 1; i <= m; i++)
    {
        cin >> u >> v >> cv;
        s[u].push_back(q);
        edge[q++] = {u, v, cv, 0};
        s[v].push_back(q);
        edge[q++] = {v, u, 0, 0};
    }
}

int check()
{
    memset(tr, 0, sizeof(tr));
    tr[st] = -1;
    int l = 1, r = 1;
    qu[l] = st;
    while (l <= r)
    {
        int u = qu[l++];
        for (int id : s[u])
        {
            int v = edge[id].v;
            if (tr[v] == 0 && edge[id].c > edge[id].f)
            {
                tr[v] = id;
                if (v == ed) return 1;
                qu[++r] = v;
            }
        }
    }
    return 0;
}

void run()
{
    int cv = 2e9, p = ed;
    while (p != st)
    {
        int id = tr[p];
        cv = min(cv, edge[id].c - edge[id].f);
        p = edge[id].u;
    }
    maxf += cv, p = ed;
    while (p != st)
    {
        int id = tr[p];
        edge[id].f += cv;
        edge[id ^ 1].f -= cv;
        p = edge[id].u;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("INP.txt", "r", stdin);
    freopen("OUT.txt", "w", stdout);
    inpa();
    while (check()) run();
    cout << maxf;
    return 0;
}
