#include <bits/stdc++.h>
#define FOR(i,x,y) for(int i = x; i <= y ; ++i)
#define FORN(i,x,y) for(int i = x; i >= y ; --i)
#define maxn 100005
#define maxm
#define Task "rmq"
#define pii pair< int , int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
int n, m, x, u, v;
int a[maxn];
int f[18][maxn];
int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
    freopen(Task".inp" , "r" , stdin);
    freopen(Task".out" , "w" , stdout);
    cin >> n >> m;
    FOR(i, 1, n) cin >> x,   f[0][i] = x ;

    FOR(i, 1, 17)
        FOR(u, 1, n - (1 << i) + 1)
            f[i][u] = min(f[i-1][u], f[i-1][u + (1 << (i-1))]);
    while(m--)
    {
        cin >> u >> v;
        int k = log2(v-u+1);
        cout << min(f[k][u], f[k][v - (1 << k) +1]) << "\n";
    }
}
