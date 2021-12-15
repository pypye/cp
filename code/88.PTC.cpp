#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define maxn 100005
using namespace std;
int n, k[maxn], cnt[5*maxn];
vector <int> a[maxn], s;
void compress(){
    FOR(i, 1, n)
        for(auto x : a[i]) s.push_back(x);
    sort(all(s));
    FOR(i, 1, n)
        for(auto &x : a[i]) x = lower_bound(all(s), x) - s.begin();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("PTC.inp");
    //ofstream cout("PTC.out");
    cin >> n;
    FOR(i, 1, n) cin >> k[i];
    FOR(i, 1, n){
        int x;
        FOR(j, 1, k[i]) cin >> x, a[i].push_back(x);
        sort(all(a[i]));
        a[i].resize(unique(all(a[i])) - a[i].begin());
    }
    compress();
    FOR(i, 1, n)
        for(auto x : a[i]) cnt[x]++;
    FOR(i, 0, 5e5) if(cnt[i] == n) return cout << s[i], 0;
    cout << -1;
}
