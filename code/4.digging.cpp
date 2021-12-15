//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
int n, a[maxn];
long long T, sum[maxn], low = 1e18;
long long getsum(int l, int r){
    return sum[r] - sum[l-1];
}
long long getup(long long l, long long r){
    return (r + l) / 2 * (r - l + 1);
}
bool check(long long x){
    long long ans = 0, res = 9e18;
    FOR(i, 1, n){
        int l = 0, r = i;
        ans = 0;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(x + mid <= a[i-mid]) l = mid;
            else r = mid;
        }
        ans += getsum(i-l, i) - getup(x, x+l);
        l = 0, r = n-i+1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(x + mid <= a[i+mid]) l = mid;
            else r = mid;
        }

        ans += getsum(i+1, i+l) - getup(x+1, x+l);
        res = min(ans, res);
    }
    return res <= T;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("digging.inp");
    ofstream cout("digging.out");
    cin >> n >> T;
    FOR(i, 1, n) cin >> a[i], sum[i] = sum[i-1] + a[i], low = min(low, 1ll*a[i]);
    long long l = -T, r = low;
    while(r - l > 1){
        long long mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}
