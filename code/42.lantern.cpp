#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 50005
using namespace std;
int n, a[maxn], dp[5][maxn], res, fen[5][maxn], fenr[5][maxn];
void compress(){
    vector <int> b;
    FOR(i, 1, n) b.push_back(a[i]);
    sort(b.begin(), b.end());
    FOR(i, 1, n) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
}
void up(int id, int x, int val){
    for(; x <= n; x += x & (-x)) fen[id][x] = max(fen[id][x], val);
}
int get(int id, int x){
    int ans = 0;
    for(; x; x -= x & (-x)) ans = max(ans, fen[id][x]);
    return ans;
}
void upr(int id, int x, int val){
    for(; x; x -= x & (-x)) fenr[id][x] = max(fenr[id][x], val);
}
int getr(int id, int x){
    int ans = 0;
    for(; x <= n; x += x & (-x)) ans = max(ans, fenr[id][x]);
    return ans;
}
void update(int &x, int add, int id){
    if(add >= id) x = max(x, add + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("lantern.inp");
    ofstream cout("lantern.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    compress();
    dp[1][1] = 1;
    up(1, a[1], dp[1][1]);
    FOR(i, 2, n){
        dp[1][i] = max(dp[1][i], get(1, a[i] - 1) + 1);
        update(dp[2][i], getr(1, a[i] + 1), 2);
        update(dp[2][i], getr(2, a[i] + 1), 3);
        update(dp[3][i], get(2, a[i] - 1), 3);
        update(dp[3][i], get(3, a[i] - 1), 4);
        update(dp[4][i], getr(3, a[i] + 1), 4);
        update(dp[4][i], getr(4, a[i] + 1), 5);
        up(1, a[i], dp[1][i]);
        up(2, a[i], dp[2][i]);
        up(3, a[i], dp[3][i]);
        upr(1, a[i], dp[1][i]);
        upr(2, a[i], dp[2][i]);
        upr(3, a[i], dp[3][i]);
        upr(4, a[i], dp[4][i]);
    }
    FOR(i, 1, n) res = max(res, dp[4][i]);
    cout << res;
}
