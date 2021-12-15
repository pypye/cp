#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORR(i, a, b) for(int i = (a); i >= (b); --i)
#define maxn 100005
using namespace std;
int n, a[maxn], d[maxn][12], ans = 1e9;
int re(int x, int y){
    return (x - y + 12) % 12;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    ifstream cin("clock.inp");
//    ofstream cout("clock.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 0, 11){
        int res = i;
        int temp = re(a[1], i);
        FOR(x, 1, n){
            res += (12 - temp) % 12;
            temp = re(a[x+1], (12 - temp) % 12);
        }
        ans = min(ans, res);
    }
    cout << ans;
}
