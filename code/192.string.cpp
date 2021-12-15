#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 200005
using namespace std;
int n, f[maxn], d[maxn], lcp[maxn];
string s;
long long pw[maxn], h[maxn], mod = 1000000007, base = 31, sum;
long long gethash(int i, int sz){
    return (h[i] - h[i + sz] * pw[sz] + mod * mod) % mod;
}
bool comp(int i, int j){
    int l = 0, r = min(n-i, n-j) + 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(gethash(i, mid) == gethash(j, mid)) l = mid;
        else r = mid;
    }
    return s[i + l] < s[j + l];
}
void build_suffix(){
    pw[0] = 1;
    FOR(i, 1, n) pw[i] = (pw[i-1] * base) % mod;
    FORR(i, n-1, 0) h[i] = (h[i+1] * base + s[i] - 'a' + 1) % mod, f[i] = i;
    sort(f, f+n, comp);
}
void build_lcp(){
    int k = 0;
    FOR(i, 0, n-1) d[f[i]] = i;
    FOR(i, 0, n-1){
        if(k > 0) k--;
        if(d[i] == n-1){
            k = 0;
            continue;
        }
        int j = f[d[i] + 1];
        while(i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[d[i]] = k;
    }
}
bool check(int mid){
    FOR(i, 0, n-1) if(lcp[i] >= mid) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("string.inp");
    ofstream cout("string.out");
    cin >> n >> s;
    build_suffix();
    build_lcp();
    int l = 0, r = n+1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
}
