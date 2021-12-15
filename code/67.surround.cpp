#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 2000005
using namespace std;
int n, k, p[22][maxn], ans = 1e9,dd[maxn],res;
pair <int, int> a[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("surround.inp");
    //ofstream cout("surround.out");
    cin >> n >> k;
    FOR(i, 1, k){
        cin >> a[i].first >> a[i].second;
        if(a[i].second < a[i].first) a[i].second += n;
        p[0][a[i].first] = max(p[0][a[i].first], a[i].second);
        dd[a[i].first]++;
        dd[a[i].second + 1]--;
    }
    FOR(i,1,n+n) dd[i] += dd[i-1];
    FOR(i, 1, n+n) p[0][i] = max(p[0][i], p[0][i-1]);
    FOR(x, 1, 21)
        FOR(i, 1, n+n)
             p[x][i] = p[x-1][p[x-1][i] + 1];
    FOR(i, 1, n){
        if(!dd[i] && !dd[i+n]) return !(cout << "impossible");
        res = 1;
        int cur = i;
        int last = i + n - 1;
        FORR(j, 21, 0)
        {
            if(p[j][cur] < last && p[j][cur])
            {
                cur = p[j][cur] + 1, res += (1 << j);
            }
        }
        if(p[0][cur] + 1 > last) ans = min(ans, res);
    }
    cout << ans;
}
