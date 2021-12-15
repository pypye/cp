#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 2000005
using namespace std;
int n, m, a[maxn], d[maxn], fen[maxn], s[maxn], ans;
void update(int x, int val){
    for(; x; x -= x & (-x)) fen[x] += val;
}
int get(int x){
    int ans = 0;
    for(; x <= n; x += x & (-x)) ans += fen[x];
    return ans;
}
bool check(){
    if(get(1) == n) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("shuffle.inp");
    ofstream cout("shuffle.out");
    cin >> n >> m;
    int k = m;
    while(k % n != 0) k++;
    FOR(i, 1, m) cin >> a[i];
    FOR(i, 1, n){
        if(!d[a[i]]) update(a[i], 1);
        d[a[i]]++;
        s[i] = (get(1) == i);
    }
    FOR(i, n + 1, k + n - 1){
        if(a[i]){
            d[a[i-n]]--;
            if(!d[a[i-n]]) update(a[i-n], -1);
            if(!d[a[i]]) update(a[i], 1);
            d[a[i]]++;
        }
        s[i] = s[i-n] & check();
    }
    FOR(i, k, k + n - 1) ans += s[i];
    cout << ans;
}
