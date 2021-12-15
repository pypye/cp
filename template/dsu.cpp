//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x, y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "mintree"
#define maxn 30005
#define maxm 100002
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

struct data
{
    int u, v, w;
};

int n, m;
long long ans;
data a[maxm];
int root[maxn];
vector<data> kq;

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
}

bool comp(data p, data q)
{
    return p.w < q.w;
}

int Get_root(int u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}

void Kruskal()
{
    sort(a + 1, a + m + 1, comp);
    memset(root, 0, sizeof(root));
    ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p != q)
        {
            root[p] = q;
            ans += a[i].w;
            kq.PB(a[i]);
        }
    }
}

void Ghikq()
{
    cout << ans << endl;
    for (int i = 0; i < n - 1; i++)
        cout << kq[i].u << " " << kq[i].v << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen(Task ".inp", "r", stdin);
    freopen(Task ".out", "w", stdout);
    nhap();
    Kruskal();
    Ghikq();
    return 0;
}
