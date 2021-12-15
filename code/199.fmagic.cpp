#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, q, a[maxn], fen[maxn], mod = 3046201;
long long g[30*maxn+5], rev[30*maxn+5];
long long power(long long n, int k){
    if(k == 0) return 1;
    long long b = power(n, k/2);
    b = (b * b) % mod;
    if(k & 1) return (b * n) % mod;
    return b;
}
void Generate(){
    int n = 30*maxn;
    g[0] = 1;
    FOR(i, 1, n) g[i] = (g[i-1] * i) % mod;
    rev[n] = power(g[n], mod-2);
    FORR(i, n-1, 1) rev[i] = (rev[i+1] * (i+1)) % mod;
    rev[0] = 1;
}
void update(int x, int val){
    if(!x) return;
    for(; x <= maxn; x += x & -x) fen[x] += val;
}
int get(int x){
    int ans = 0;

    for(; x; x -= x & -x) ans += fen[x];
    return ans;
}
void re(long long &ans, long long x){
    ans = (ans * x) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    ifstream cin("fmagic.inp");
    ofstream cout("fmagic.out");
    cin >> n;
    Generate();
    FOR(i, 1, n){
        cin >> a[i];
        update(i, a[i]);
    }
    cin >> q;
    while(q--){
        char type; int l, r;
        cin >> type >> l >> r;
        if(type == 'C'){
            update(l, -a[l]);
            update(l, r);
            a[l] = r;
        }
        else{
            int k = r - l + 1;
            int b = get(r) - get(l-1);
            int i = b % k, p = b / k;
            long long ans = 1;
            re(ans, g[k]); re(ans, rev[i]);
            re(ans, rev[k-i]); re(ans, g[b]);
            re(ans, power(rev[p+1], i));
            re(ans, power(rev[p], k-i));
            cout << ans << '\n';
        }
    }
}
