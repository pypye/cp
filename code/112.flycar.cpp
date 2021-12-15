#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 405
using namespace std;
int n, k, a[maxn];
long long ans = 1e18;
struct pii{
    long long F, S;
}f[maxn][maxn];
bool check(int l, int r, long long mid){
    FOR(i, l, r) if(mid < a[i]) return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("flycar.inp");
    ofstream cout("flycar.out");
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n)
        FOR(x, 0, k) f[i][x].F = 1e18;
    FOR(i, 1, n)
        FOR(j, 0, i-1){
            long long l = 0, r = 1e18 + 1;
            while(r - l > 1){
                long long mid = (l + r) >> 1;
                if(check(j+1, i, mid)) r = mid;
                else l = mid;
            }
            long long cur = 0;
            FOR(x, j+1, i) cur += r - a[x];
            FOR(x, 0, k-1)
                if(f[j][x].S == r || j == 0){
                    if(f[i][x].F > f[j][x].F + cur){
                        f[i][x].F = f[j][x].F + cur;
                        f[i][x].S = r;
                    }
                }
                else{
                    if(f[i][x+1].F > f[j][x].F + cur){
                        f[i][x+1].F = f[j][x].F + cur;
                        f[i][x+1].S = r;
                    }
                }
        }
    FOR(x, 0, k) ans = min(ans, f[n][x].F);
    cout << ans;
}
