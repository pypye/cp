#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORR(i, a, b) for (int i = (a); i >= (b); i--)
#define maxn 10005
using namespace std;
int q, n, Next[maxn][60], link[maxn], cnt;
string s, t;
vector<int> id[maxn], res[maxn];
void reset()
{
    memset(Next, 0, sizeof Next);
    memset(link, 0, sizeof link);
    FOR(i, 1, cnt)
    id[i].clear();
}
void Add(string s, int i)
{
    int u = 0;
    for (int i = 0; s[i]; i++)
    {
        int v = s[i] - 'A';
        if (!Next[u][v])
            Next[u][v] = ++cnt;
        u = Next[u][v];
    }
    id[u].push_back(i);
}
int get_next(int u, int k)
{
    while (u != -1)
    {
        if (Next[u][k])
            return Next[u][k];
        u = link[u];
    }
    return 0;
}
void Bfs()
{
    queue<int> q;
    q.push(0);
    link[0] = -1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        FOR(p, 0, 57)
        {
            if (Next[u][p])
            {
                int v = Next[u][p];
                link[v] = get_next(link[u], p);
                copy(id[v].begin(), id[v].end(), back_inserter(id[link[v]]));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //    ifstream cin("main.inp");
    cin >> q;
    while (q--)
    {
        reset();
        cin >> n;
        FOR(i, 1, n)
            cin >> t,
            Add(t, i);
        Bfs();
        int p = 0;
        for (int i = 0; s[i]; i++)
        {
            p = get_next(p, s[i] - 'A');
            for (int x : id[p])
                res[x].push_back(i);
        }
        FOR(i, 1, n)
        if (res[i].size() >= 1)
            cout << "y\n";
        else
            cout << "n\n";
    }
}
