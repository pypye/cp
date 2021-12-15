#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 5005
using namespace std;
int n, m, k, p[maxn], d[maxn], res;
vector <int> a[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("netxor.inp");
    ofstream cout("netxor.out");
    cin >> n >> m >> k;
    FOR(i, 1, n) cin >> p[i];
    while(m--){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    FOR(x, 0, (1 << k)-1){
        FOR(i, 0, (1 << n)-1){
            FOR(u, 1, n) d[u] = p[u];
            FOR(u, 1, n) if((i >> (u-1)) & 1) d[u] = (p[u] ^ x);
            int check = 1;
            FOR(u, 1, n)
                for(auto v : a[u]){
                    if(d[u] == d[v]) {
                        check = 0;
                        break;
                    }
                }
            res += check;
        }
    }
    cout << res;
}
