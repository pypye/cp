//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
int n, d, a[maxn], l[maxn], r[maxn], f[maxn], tr[maxn];
pair fen[12*maxn];
int M[3*maxn];
vector <int> res;
void compress(){
    #define all(s) s.begin(), s.end()
    vector <int> s;
    FOR(i, 1, n){
        s.push_back(a[i]);
        s.push_back(l[i]);
        s.push_back(r[i]);
    }
    sort(all(s));
    FOR(i, 1, n){
        int x = a[i];
        a[i] = lower_bound(all(s), a[i]) - s.begin() + 1;
        l[i] = lower_bound(all(s), l[i]) - s.begin() + 1;
        r[i] = lower_bound(all(s), r[i]) - s.begin() + 1;
        M[a[i]] = x;
    }
}
    #define mid (l + r) / 2
void update(int x, int val, int w, int l = 1, int r = 3*n, int id = 1){
    if(l > x || r < x) return;
    if(l == r){
        fen[id] = {val, w};
        return;
    }
    if(mid >= x) update(x, val, w, l, mid, id*2);
    else update(x, val, w, mid+1, r, id*2+1);
    fen[id] = max(fen[id*2], fen[id*2+1]);
}
pair get(int u, int v, int l = 1, int r = 3*n, int id = 1){
    if(l > v || r < u) return {0, 0};
    if(l >= u && r <= v) return fen[id];
    return max(get(u, v, l, mid, id*2), get(u, v, mid+1, r, id*2+1));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("subseq.inp");
    ofstream cout("subseq.out");
    cin >> n >> d;
    FOR(i, 1, n){
        cin >> a[i];
        l[i] = a[i] - d;
        r[i] = a[i] + d;
    }
    compress();
    int ans = 0, pos = 0;
    FOR(i, 1, n){
        f[i] = get(l[i], r[i]).first + 1;
        tr[i] = get(l[i], r[i]).second;
        if(ans < f[i]) ans = f[i], pos = i;
        update(a[i], f[i], i);
    }
    cout << ans << '\n';
    while(pos){
        res.push_back(M[a[pos]]);
        pos = tr[pos];
    }
    reverse(res.begin(), res.end());
    for(auto v : res) cout << v << " ";
}
