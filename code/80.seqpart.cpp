#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
#define maxc 1000000000000000000
using namespace std;
int n, a[maxn];
long long m, sum[maxn], b[maxn], f[maxn], tr[maxn];
struct Pair{
    long long F, S;
};
Pair fen[maxn];
vector <int> q;
int compress(long long x){
    return lower_bound(b+1, b+n+2, x) - b;
}
void update(int x, int val, int pos){
    for(; x; x -= x & (-x)){
        if(fen[x].F > val) fen[x] = {val, pos};
    }
}
Pair get(int x){
    Pair res = {maxc, maxc};
    for(; x <= n; x += x & (-x)){
        if(res.F > fen[x].F) res = fen[x];
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("seqpart.inp");
    //ofstream cout("seqpart.out");
    cin >> n >> m;
    FOR(i, 1, n){
        cin >> a[i];
        sum[i] = sum[i-1] + 1ll * a[i];
        b[i] = sum[i];
        fen[i] = {maxc, maxc};
    }
    sort(b+1, b+n+2);
    update(compress(0), 0, 0);
    FOR(i, 1, n){
        Pair u = get(compress(sum[i] - m));
        if(u.F == maxc || u.S == maxc) continue;
        f[i] = u.F + 1;
        tr[i] = u.S;
        update(compress(sum[i]), f[i], i);
    }
    cout << f[n] << '\n';
    n = tr[n];
    while(n){
        q.push_back(n);
        n = tr[n];
    }
    reverse(q.begin(), q.end());
    for(auto v : q) cout << v << " ";
}
