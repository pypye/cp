#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, m;
long long p[maxn], h[maxn];
bool d[maxn];
bool check(long long mid){
    int x = 1;
    FOR(i, 1, n)
    {
        if(abs(h[i] - p[x]) > mid) continue;
        if(p[x] < h[i])
        {
            long long k = h[i] - p[x];
            while(x <= m && p[x] <= h[i]) x++;
            while(x <= m && k * 2 + p[x] - h[i] <= mid) x++;
            while(x <= m && k + 2 * (p[x] - h[i]) <= mid) x++;
        }
        else while(x <= m && p[x] - h[i] <= mid) x++;
    }
    if(x == m + 1) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    ifstream cin("readtime.inp");
    ofstream cout("readtime.out");
    cin >> n >> m;
    FOR(i, 1, n) cin >> h[i];
    FOR(i, 1, m) cin >> p[i];
    long long l = -1, r = 1e18;
    while(r - l > 1){
        long long mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}
