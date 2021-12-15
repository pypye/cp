#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 200005
using namespace std;
int n;
long long w[maxn], d[maxn], sumd[maxn], sumw[maxn], k[maxn], ans = 2e18;
long long getdown(int l, int r){
    r--;
    return sumd[r] * (sumw[r] - sumw[l-1]) - k[r] + k[l-1];
}
long long check(int i, int x){
    return getdown(1, i) + getdown(i+1, x) + getdown(x+1, n+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("sawmill.inp");
    //ofstream cout("sawmill.out");
    cin >> n;
    FOR(i, 1, n) cin >> w[i] >> d[i];
    FOR(i, 1, n) sumd[i] = sumd[i-1] + d[i];
    FOR(i, 1, n) sumw[i] = sumw[i-1] + w[i];
    FOR(i, 1, n) k[i] = k[i-1] + 1ll * w[i] * sumd[i-1];
    FOR(i, 1, n-1){
        int l = i, r = n+1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(check(i, mid) > check(i, mid-1)) r = mid;
            else l = mid;
        }
        ans = min(ans, check(i, l));
    }
    cout << ans;
}
