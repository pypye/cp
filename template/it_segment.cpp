/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ll long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define pi acos(-1)
#define N 200005
#define task "jewelry"
#define remain(x) ((x > MOD) ? (x - MOD) : x)
 
using namespace std;
 
int m, n;
 
struct line
{
    ll a, b;
 
    line(int _a = 0, int _b = 0) {a = _a; b = _b;}
};
 
struct IT_doanthang
{
    line t[N<<2];
 
    IT_doanthang()
    {
        FOR(i, 0, N << 2) t[i] = line(0, 0);
    }
 
    ll Get(line li, int x)
    {
        return 1ll*li.a*x + li.b;
    }
 
    void Upd(int l, int r, int id, int u, int v, line val)
    {
        if (l > v || r < u) return;
        int mid = (l + r) >> 1;
        if (l >= u && r <= v)
        {
            if (Get(t[id], l) >= Get(val, l) && Get(t[id], r) >= Get(val, r)) return;
            if (Get(t[id], l) <= Get(val, l) && Get(t[id], r) <= Get(val, r))
            {
                t[id] = val;
                return;
            }
            if (Get(t[id], l) <= Get(val, l) && Get(t[id], mid) <= Get(val, mid))
            {
                Upd(mid+1, r, id*2+1, u, v, t[id]);
                t[id] = val;
                return;
            }
            if (Get(t[id], l) >= Get(val, l) && Get(t[id], mid) >= Get(val, mid))
            {
                Upd(mid+1, r, id*2+1, u, v, val);
                return;
            }
            if (Get(t[id], r) <= Get(val, r) && Get(t[id], mid) <= Get(val, mid))
            {
                Upd(l, mid, id*2, u, v, t[id]);
                t[id] = val;
                return;
            }
            if (Get(t[id], r) >= Get(val, r) && Get(t[id], mid) >= Get(val, mid))
            {
                Upd(l, mid, id*2, u, v, val);
                return;
            }
        }
        Upd(l, mid, id*2, u, v, val);
        Upd(mid+1, r, id*2+1, u, v, val);
    }
 
    ll Query(int l, int r, int id, int x)
    {
        if (l > x || r < x) return -1e18;
        ll ans = Get(t[id], x);
        if (l == r) return ans;
        int mid = (l + r) >> 1;
        ans = max(ans, Query(l, mid, id*2, x));
        ans = max(ans, Query(mid+1, r, id*2+1, x));
        return ans;
    }
 
} Tree;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> n >> m;
    FOR(i, 1, m)
    {
        int s, e, v, d;
        cin >> s >> e >> v >> d;
        line li;
        li.a = d;
        li.b = 1ll*v - 1ll*s*d;
        Tree.Upd(1, n, 1, s, e, li);
    }
    FOR(i, 1, n) cout << Tree.Query(1, n, 1, i) << '\n';
    return 0;
}