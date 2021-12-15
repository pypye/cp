#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
#define F first
#define S second
using namespace std;
int n, hmax;
long long w, h, ans = 1e18;
pair <int, int> a[maxn];
priority_queue<pair <int, int>> Q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("divland.inp");
    ofstream cout("divland.out");
    cin >> n >> w >> h;
    if(n & 1) return cout << -1, 0;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;
    sort(a+1, a+n+1);
    hmax = INT_MAX;
    FOR(i, 1, n){
        int x = a[i].F;
        while(a[i].F == x) Q.push({a[i].S,a[i++].F});
        i--;
        while(Q.size() > n/2){
            while(Q.top().F > hmax) Q.pop();
            hmax--;
        }
        hmax = Q.top().F;
        if(Q.size() == n/2) ans = min(ans, 1ll * a[i].F * Q.top().F);
    }

    if(ans == 1e18) cout << -1;
    else cout << w * h - ans;
}
