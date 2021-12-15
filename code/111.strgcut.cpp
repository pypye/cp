#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
string s, t;
int n, m, id[maxn], pos[maxn];
long long pw[maxn], pws[maxn], h[maxn], hs[maxn], dp[maxn], sum[maxn], base = 31, mod = 1000000007, mod2 = 1000000000;
vector <pair<int, int>> q;
long long get(int i, int sz){
    return (h[i] - h[i + sz] * pw[sz] + mod * mod) % mod;
}
long long gets(int i, int sz){
    return (hs[i] - hs[i + sz] * pws[sz] + mod * mod) % mod;
}
bool comp(int i, int j){
    int l = 0, r = min(n-i, n-j) + 1;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(get(i, mid) == get(j, mid)) l = mid;
        else r = mid;
    }
    return t[i + l] < t[j + l];
}
bool check(int i, int j){
    if(s[i] != t[id[j]]) return s[i] > t[id[j]];
    int l = 0, r = min(m, n-id[j]) + 1;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(gets(i, mid) == get(id[j], mid)) l = mid;
        else r = mid;
    }
    return s[i + l] > t[id[j] + l];

}
int solve(int i, int l){
    int l2 = 0, r2 = min(m, n - id[l]) + 1;
    while(r2 - l2 > 1){
        int mid2 = (l2 + r2) >> 1;
        if(gets(i, mid2) == get(id[l], mid2)) l2 = mid2;
        else r2 = mid2;
    }
    return l2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("strgcut.inp");
    //ofstream cout("strgcut.out");
    cin >> s >> t;
    m = s.size();
    s = s + '~';
    n = t.size();
    pw[0] = 1; pws[0] = 1;
    FOR(i, 1, n) pw[i] = (pw[i-1] * base) % mod;
    FOR(i, 1, m) pws[i] = (pws[i-1] * base) % mod;
    FORR(i, n-1, 0) h[i] = (h[i+1] * base + t[i] - 'A' + 1) % mod, id[i] = i;
    FORR(i, m-1, 0) hs[i] = (hs[i+1] * base + s[i] - 'A' + 1) % mod;
    sort(id, id+n, comp);

    FOR(i, 0, m-1){
        int l = 0, r = n;
        while(r - l > 1){
            int mid = (l + r) >> 1;
            if(check(i, mid)) l = mid;
            else r = mid;
        }
        int l2 = max(solve(i, l), solve(i, r));
        pos[i] = i + l2 - 1;
    }
    sum[m] = 1;
    FORR(i, m-1, 0){
        long long f = ((sum[i+1] - sum[pos[i]+2]) % mod2 + mod2) % mod2;
        sum[i] = (sum[i+1] + f) % mod2;
    }
    cout << ((sum[0]- sum[1]) % mod2 + mod2) % mod2;
}
