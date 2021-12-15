#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005
using namespace std;
int n, T, a[maxn], d[maxn], cnt[maxn], check[maxn], ans;
vector <pair <int, int>> q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("ants.inp");
    ofstream cout("ants.out");
    cin >> n >> T;
    FOR(i, 1, n) cin >> a[i], cnt[a[i]]++;
    FOR(i, 1, n) if(!check[a[i]]) q.push_back(make_pair(a[i], cnt[a[i]])), check[a[i]]++;
    for(auto v : q){
        for(int j = v.first; j <= T; j += v.first) d[j] += v.second;
    }
    ans = *max_element(d+1, d+T+1);
    cout << ans << " " << count(d+1, d+T+1, ans);
}
