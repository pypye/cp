#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n;
long long k, a[maxn], fen[maxn], sum[maxn], res;
void compress(){
    vector <long long> s;
    FOR(i, 0, n) s.push_back(sum[i]);
    sort(s.begin(), s.end());
    FOR(i, 0, n) sum[i] = lower_bound(s.begin(), s.end(), sum[i]) - s.begin() + 1;
}
void update(int x){
    for(; x <= n+1; x += x & (-x)) fen[x]++;
}
long long get(int x){
    long long ans = 0;
    for(; x; x -= x & (-x)) ans += fen[x];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("avertree.inp");
    ofstream cout("avertree.out");
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i], a[i] -= k;
    FOR(i, 1, n) sum[i] = sum[i-1] + a[i];
    compress();
    FOR(i, 0, n){
        res += get(sum[i]);
        update(sum[i]);
    }
    cout << res;
}
