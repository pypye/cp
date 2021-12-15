#include <bits/stdc++.h>
#define FOR(i, x, y) for (int i = x; i <= y; ++i)
#define FORR(i, x, y) for (int i = x; i >= y; --i)
#define maxn 100005
using namespace std;
int n, m, sz, a[maxn], l[maxn], r[maxn], id[maxn], cnt[maxn], cur, res[maxn], b[maxn];
bool comp(int u, int v)
{
    int blocku = l[u] / sz, blockv = l[v] / sz;
    if (blocku != blockv)
        return blocku < blockv;
    return r[u] < r[v];
}
void compress()
{
    sort(b + 1, b + n + 1);
    int n1 = unique(b + 1, b + n + 1) - b - 1;
    FOR(i, 1, n)
    a[i] = lower_bound(b + 1, b + n1 + 1, a[i]) - b;
}
void add(int u, int x)
{
    int k = (cnt[u] == b[u]);
    cnt[u] += x;
    cur += (cnt[u] == b[u]) - k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n >> m;
    sz = sqrt(n);
    FOR(i, 1, n)
        cin >> a[i],
        b[i] = a[i];
    FOR(i, 1, m)
        cin >> l[i] >> r[i],
        id[i] = i;
    compress();
    sort(id + 1, id + m + 1, comp);
    int L = 2, R = 1;
    FOR(i, 1, m)
    {
        int u = id[i];
        while (L > l[u])
            add(a[--L], 1);
        while (L < l[u])
            add(a[L++], -1);
        while (R > r[u])
            add(a[R--], -1);
        while (R < r[u])
            add(a[++R], 1);
        res[u] = cur;
    }
    FOR(i, 1, m)
        cout << res[i] << '\n';
}