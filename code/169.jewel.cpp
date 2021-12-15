//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 200005

using namespace std;
int n, m;
long long ans[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("jewel.inp");
    ofstream cout("jewel.out");
    cin >> n >> m;
    while(m--){
        int s, e;
        long long v, d;
        cin >> s >> e >> v >> d;
        FOR(i, s, e) ans[i] = max(ans[i], v + d * (i - s));
    }
    FOR(i, 1, n) cout << ans[i] << '\n';
}
