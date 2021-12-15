//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 300005

using namespace std;
int n, pos[maxn], dd[maxn], ans;
pair <int, int> a[maxn];
void dfs(int u, int sz){
    ans = max(ans, u);
    FOR(i, 1, n) if(!dd[i] && a[i].F <= sz){
        dd[i] = 1;
        dfs(u+1, min(sz - a[i].F, a[i].S));
        dd[i] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("pizza.inp", "r", stdin);
    freopen("pizza.out", "w", stdout);
    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;
    dfs(0, 1e9);
    cout << ans;


}
