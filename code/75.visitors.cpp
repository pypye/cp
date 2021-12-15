//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
int n, a[maxn], id[maxn], pos[maxn];
long long sum[maxn], f[maxn], fen[2][maxn];
bool comp(int i, int j){
    return a[i] < a[j];
}
long long getsum(int l, int r){
    return sum[r] - sum[l];
}
void update1(int x, long long val){
    for(; x <= n; x += x & -x) fen[0][x] = min(fen[0][x], val);
}
long long get1(int x){
    long long ans = 1e18;
    for(; x; x -= x & -x) ans = min(ans, fen[0][x]);
    return ans;
}
void update2(int x, long long val){
    for(; x; x -= x & -x) fen[1][x] = min(fen[1][x], val);
}
long long get2(int x){
    long long ans = 1e18;
    for(; x <= n; x += x & -x) ans = min(ans, fen[1][x]);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("visitors.inp");
    ofstream cout("visitors.out");
    cin >> n;
    FOR(i, 0, 1) fill(fen[i], fen[i]+n+1, 1e18);
    FOR(i, 1, n) cin >> a[i], id[i] = i;
    sort(id+1, id+n+1, comp);
    FOR(i, 1, n) pos[id[i]] = i;
    FOR(i, 1, n) sum[i] = sum[i-1] + abs(a[i] - a[i-1]);
    f[1] = abs(a[1]);
    int x = 1;
    while(x <= n && a[id[x]] <= 0) ++x;
    if(x <= n) update1(x, f[1]);
    if(x > 1) update2(x - 1, f[1]);
    long long ans = f[1] + getsum(1, n);
    FOR(i, 2, n){
        f[i] = min(get1(pos[i]) + getsum(1, i-1) + a[i], get2(pos[i]) + getsum(1, i-1) - a[i]);
        ans = min(ans, f[i] + getsum(i, n));
        update1(pos[i-1], f[i] - getsum(1, i) - a[i-1]);
        update2(pos[i-1], f[i] - getsum(1, i) + a[i-1]);
    }
    cout << ans;

}
