#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
using namespace std;
int n, lf, rt;
long long L, R, v[33], w[33], a[33], ans;
pair <long long, long long> prof, f[18][1 << 18];
vector <int> qu;
vector <long long> wei;
struct data{
    long long wei, val, st;
    bool operator < (const data &x){
        return wei < x.wei;
    }
};
vector <data> q[2];
void process(bool ty){
    long long ans = 0, val = 0, wei = 0;
    if(!ty){
        FOR(i, 1, lf)if(a[i]){
            ans += (1ll << (i-1));
            val += v[i];
            wei += w[i];
        }
        q[0].push_back({wei, val, ans});
    }
    else{
        FOR(i, 1, rt)if(a[i]){
            ans += (1ll << (i-1));
            val += v[i+lf];
            wei += w[i+lf];
        }
        q[1].push_back({wei, val, ans});
    }
}
void dfs(int u, bool ty){
    if(ty){if(u > rt){process(ty);return;}}
    else  {if(u > lf){process(ty);return;}}
    FOR(i, 0, 1){
        a[u] = i;
        dfs(u+1, ty);
    }
}
pair <long long, long long> get(int u, int v){
    int k = log2(v-u+1);
    return max(f[k][u], f[k][v - (1 << k) + 1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("dowry.inp", "r", stdin);
//    freopen("dowry.out", "w", stdout);
    cin >> n >> L >> R;
    lf = n/2, rt = n - lf;
    FOR(i, 1, n) cin >> w[i] >> v[i];
    dfs(1, 0);
    dfs(1, 1);
    sort(q[0].begin(), q[0].end());
    sort(q[1].begin(), q[1].end());
    wei.push_back(-1);
    FOR(i, 0, q[1].size()-1) wei.push_back(q[1][i].wei);
    int cnt = 0;
    for(auto v : q[1]) f[0][++cnt] = {v.val, v.st};
    FOR(i, 1, 17)
        FOR(u, 1, cnt - (1 << i) + 1) f[i][u] = max(f[i-1][u], f[i-1][u + (1 << (i-1))]);
    FOR(u, 0, q[0].size()-1){
        int l = lower_bound(wei.begin(), wei.end(), L - q[0][u].wei) - wei.begin();
        int r = upper_bound(wei.begin(), wei.end(), R - q[0][u].wei) - wei.begin() - 1;
        if(l >= r) continue;
        if(ans < q[0][u].val + get(l, r).first){
            ans = q[0][u].val + get(l, r).first;
            prof = {q[0][u].st, get(l, r).second};
        }
    }
    FOR(i, 0, lf-1) if(((prof.first >> i) & 1)) qu.push_back(i + 1);
    FOR(i, 0, rt-1) if(((prof.second >> i) & 1)) qu.push_back(i + lf + 1);
    cout << qu.size() << '\n';
    sort(qu.begin(), qu.end());
    long long ans = 0, res = 0;
    for(auto x : qu) cout << x << " ";
}
