//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 100005

using namespace std;
int n, T, ans, sum;
pair <int, int> a[maxn];
priority_queue <int> q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("cake.inp");
    ofstream cout("cake.out");
    cin >> n >> T;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;
    sort(a+1, a+n+1);
    FOR(i, 1, n){
        int lim = T - a[i].F;
        q.push(a[i].S);
        sum += a[i].S;
        while(q.size() && sum > lim) sum -= q.top(), q.pop();
        ans = max(ans, (int)q.size());
    }
    cout << ans;
}
