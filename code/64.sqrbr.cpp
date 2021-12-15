#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn
#define all(s) s.begin(), s.end()
using namespace std;
int T, n, k, a[40], d[40];
vector <int> low, high;
void check(int type){
    int open = 0, close = 0;
    if(type == n){
        FOR(i, 1, n){
            if(a[i] == 1 || a[i] == 3) open++;
            else open--;
            if(open < 0) return;
        }
        low.push_back(open);
    }
    else{
        FORR(i, n+n, n+1){
            if(a[i] == 1 || a[i] == 3) close--;
            else close++;
            if(close < 0) return;
        }
        high.push_back(close);
    }
}
void dfs(int u, int type){
    if(u > type){
        check(type);
        return;
    }
    FOR(x, 2, 3)if(u <= type){
        while(a[u] == 1) u++;
        a[u] = x;
        dfs(u+1, type);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("sqrbr.inp");
    ofstream cout("sqrbr.out");
    cin >> T;
    while(T--){
        cin >> n >> k;
        memset(a, 0, sizeof a);
        low.clear(); high.clear();
        int x, ans = 0;
        FOR(i, 1, k) cin >> x, a[x] = 1;
        dfs(1, n);
        dfs(n+1, n+n);
        sort(all(high));
        for(auto v : low)
            ans += upper_bound(all(high), v) - lower_bound(all(high), v);
        cout << ans << '\n';
    }
}
