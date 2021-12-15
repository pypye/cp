#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 100005
using namespace std;
long long a, mod = 1000000007, ans = 1;
int n, d[maxn];
string b;
long long power(long long n, long long k){
    if(k == 0) return 1;
    long long b = power(n, k/2);
    b = (b * b) % mod;
    if(k & 1) return (b * n) % mod;
    return b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("pow.inp");
    ofstream cout("pow.out");
    cin >> a >> b;
    n = b.size();
    FOR(i, 0, n-1) d[i+1] = b[i] - '0';
    FOR(i, 1, n){
        long long k = power(10, n-i);
        ans = (ans * power(power(a, 1ll*d[i]), k)) % mod;
    }
    cout << ans;
}
