#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 40005
using namespace std;
int n, m, f[maxn], d[maxn], lcp[maxn], ck[maxn];
long long pw[maxn], h[maxn], mod = 1000000007, base = 31;
string s;
vector <int> q;
void reset(){
    FOR(i, 0, n) h[i] = f[i] = d[i] = lcp[i] = ck[i] = 0;
    q.clear();
}
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
    h[n] = 0;
    FORR(i, n-1, 0) h[i] = (h[i+1] * base + s[i] - 'a') % mod, f[i] = i;
    sort(f, f+n, comp);
}
void build_lcp(){
    int k = 0;
    FOR(i, 0, n-1) d[f[i]] = i;
    FOR(i, 0, n-1){
        if(d[i] == n-1){
            k = 0;
            continue;
        }
        int j = f[d[i] + 1];
        while(i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[d[i]] = k;
        if(k > 0) k--;
    }
}
bool check(int mid){
    int res = 0, ans = 0;
    FOR(i, 0, n-1) if(lcp[i] >= mid){
        res++;
        ans = max(ans, res);
    }
    else res = 0;
    return ans >= m-1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("alien.inp");
    ofstream cout("alien.out");
    pw[0] = 1;
    FOR(i, 1, 40000) pw[i] = (pw[i-1] * base) % mod;
    while(cin >> m){
        if(!m) return 0;
        cin >> s;
        n = s.size();
        reset();
        build_suffix();
        build_lcp();
        int l = 0, r = n+1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        if(!l) cout << "none";
        else{
            int res = 0, ans = 0, checkf = 0;
            FORR(i, n-1, 0) if(lcp[i] >= l){
                res++;
                if(res >= m-1) ck[i] = 1;
            }
            else ck[i] = 0, res = 0;
            FOR(i, 0, n-1){
                if(ck[i]) checkf = 1;
                if(lcp[i] < l) checkf = 0;
                if(checkf){
                    q.push_back(f[i]);
                    q.push_back(f[i+1]);
                }
            }
            sort(q.begin(), q.end());
            if(q.size()) cout << l << " " << q[q.size()-1];
            else cout << l << " " << 0;
        }
        cout << '\n';
    }

}
