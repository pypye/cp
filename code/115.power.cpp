#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 100005
#define F first
#define S second
using namespace std;
int n, k;
long long ans;
pair <int, int> a[maxn];
bool comp(pair <int, int> A, pair<int, int> B){
    return A.F > B.F;
}
priority_queue <int>q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("power.inp");
    ofstream cout("power.out");
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;
    sort(a+1, a+n+1, comp);
    FOR(i, 1, n){
        q.push(-a[i].S);
        while(q.size() > k) q.pop();
        if(q.size() == k) ans = max(ans, 1ll * a[i].F * (-q.top()));
    }
    cout << ans;
}
