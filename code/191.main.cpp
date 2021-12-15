#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 200005
using namespace std;
string s;
int n, sa[maxn];
long long base = 127, pw[maxn], h[maxn], mod = 998244353;
long long gethash(int i, int sz){
    return (h[i] - h[i + sz] * pw[sz] + mod * mod) % mod;
}
bool comp(int i, int j){
    int l = 0, r = min(n - i, n - j) + 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(gethash(i, mid) == gethash(j, mid)) l = mid;
        else r = mid;
    }
    return s[i + l] < s[j + l];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("main.inp");
    cin >> s;
    s = s + s;
    n = s.size();
    pw[0] = 1;
    FOR(i, 1, n) pw[i] = (pw[i-1] * base) % mod;
    h[n] = 0;
    FORR(i, n-1, 0) h[i] = (h[i+1] * base + s[i] - 'a') % mod, sa[i] = i;
    sort(sa, sa+n, comp);
    FOR(i, 0, n-1) if(sa[i] < n/2) return cout << sa[i], 0;


}
