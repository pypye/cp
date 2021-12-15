#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 50000005

using namespace std;
int coin[16] = {1, 3, 5,
                10, 30, 50,
                100, 300, 500,
                1000, 3000, 5000,
                10000, 30000, 50000};
int q, dp[maxn], ncoin[16];
void bruh(){
    while(q--){
        int x, t;
        cin >> x >> t;
        coin[15] = x;
        FOR(i, 1, t) dp[i] = 1e9;
        FOR(i, 1, t){
            FOR(j, 0, 15){
                if(i >= coin[j]) dp[i] = min(dp[i], dp[i-coin[j]] + 1);
            }
        }
        cout << dp[t] <<'\n';
    }
}
int get(int x){
    int ans = 0;
    FORR(i, 14, 0){
        ans += x / coin[i];
        x %= coin[i];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("oddcoin.inp", "r", stdin);
    freopen("oddcoin.out", "w", stdout);
    cin >> q;
    while(q--){
        int x, t, ans  = 1e9;
        cin >> x >> t;
        int k = t/x + 1;
        FOR(i, 0, k){
            if(t < 0) break;
            ans = min(ans, i + get(t));
            t -= x;
        }
        cout << ans << '\n';
    }
}
