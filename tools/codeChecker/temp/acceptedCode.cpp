#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;

int main(){
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
    int n, x;
    cin >> n >> x;
    int ans = 0;
    for(int i = 1; i <= 2*n; i++)
        for(int j = i+1; j <= 2*n; j++){
            if(j - i != 1 && j - i != n+x) ans++;
        }
    cout << ans % mod;

}