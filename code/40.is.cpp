//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
using Array = long long[maxn];
int n;
long long ans;
Array a, w, dp, fen;
int Max(int x, int y){
    if(dp[x] > dp[y]) return x;
    return y;
}
void update(int x, int val){
    for(; x <= maxn - 4; x += x & -x){
        fen[x] = Max(fen[x], val);
    }
}
long long get(int x){
    int ans = 0;
    for(; x; x -= x & -x){
        ans = Max(ans, fen[x]);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("is.inp");
    ofstream cout("is.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> w[i];
    FOR(i, 1, n){
        dp[i] = dp[get(a[i] - 1)] + w[i];
        update(a[i], i);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

