//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005
using namespace std;
string s;
int n, cnt[maxn], dd[maxn];
long long mod = 1000000007, f[maxn], rev[maxn];
vector <int> p;
void compress(){
    FOR(i, 0, n-1) if(!dd[s[i]]) p.push_back(cnt[s[i]]), dd[s[i]]++;
    sort(p.begin(), p.end(), greater <int>());
}
long long pw(long long x, long long k){
    if(k == 0) return 1;
    long long b = pw(x, k/2);
    b = (b * b) % mod;
    if(k & 1) return (b * x) % mod;
    return b;
}
void factorial(){
    f[0] = 1;
    FOR(i, 1, n) f[i] = (f[i-1] * i) % mod;
    rev[n] = pw(f[n], mod - 2);
    FORR(i, n-1, 1) rev[i] = (rev[i+1] * (i+1)) % mod;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("pew.inp");
    ofstream cout("pew.out");
    cin >> s;
    n = s.size();
    FOR(i, 0, n-1) cnt[s[i]]++;
    compress();
    factorial();
    long long ans = f[n];
    for(auto i : p)
        ans = (ans * rev[i]) % mod;
    cout << ans;

}
