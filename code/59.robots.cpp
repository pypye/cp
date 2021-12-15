//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define F first
#define S second
#define maxn 1000005
using namespace std;
int A, B, T, wt[50005], sz[50005];
pair p[maxn];
bool check(int mid){
    priority_queue <int> q;
    int x = 1;
    FOR(i, 1, A){
        int temp = mid;
        while(x <= T && p[x].F < wt[i]) q.push(p[x].S), x++;
        while(q.size() && temp--) q.pop();

    }
    FOR(i, x, T) q.push(p[i].S);
    FORR(i, B, 1){
        int temp = mid;
        while(q.size() && temp-- && q.top() < sz[i]) q.pop();

    }
    return q.empty();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("robots.inp");
    ofstream cout("robots.out");
    cin >> A >> B >> T;
    FOR(i, 1, A) cin >> wt[i];
    FOR(i, 1, B) cin >> sz[i];
    sort(wt+1, wt+A+1);
    sort(sz+1, sz+B+1);
    FOR(i, 1, T) cin >> p[i].F >> p[i].S;
    sort(p+1, p+T+1);
    int l = 0, r = T+1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(r == T+1) cout << -1;
    else cout << r;

}
