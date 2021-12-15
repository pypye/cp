#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 1000005
using namespace std;
int n, k, b[maxn];
pair <int,int> a[maxn];
long long calc(int i, int mid){
    return mid / (2ll * a[i].S) + 1ll * a[i].F;
}
bool check(long long mid){
    int base = k;
    long long x = 1e18;
    FOR(i, 1, n){
        long long cur = calc(i, mid);
        x = min(x, cur);
        if(x >= a[i+1].F) continue;
        while(2ll * a[i].S * abs(x - a[i].F) <= mid)
            i++;
        i--; x = 1e18;
        base--;
    }
    return base >= 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("ants.inp");
    ofstream cout("ants.out");
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i].F;
    a[n+1].F = 1e9;
    FOR(i, 1, n) cin >> a[i].S;
    sort(a+1, a+n+1);
    long long l = -1, r = (long long)1e12 + 1;
    while(r - l > 1){
        long long mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}
