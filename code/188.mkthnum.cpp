//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 100005

using namespace std;
#define all(s) s.begin(), s.end()
int n, m, a[maxn], ver[maxn], cnt;
vector <int> s;
struct pst{
    int l, r, ans;
}fen[16*maxn];
void modify(int id){
    int l = fen[id].l, r = fen[id].r;
    fen[id].ans = fen[l].ans + fen[r].ans;
}
int update(int x, int id, int l = 1, int r = n){
    if(l == r){
        ++cnt;
        fen[cnt] = {0, 0, fen[id].ans + 1};
        return cnt;
    }
    int mid = (l + r) >> 1;
    int cur = ++cnt;
    if(x <= mid){
        fen[cur].l = update(x, fen[id].l, l, mid);
        fen[cur].r = fen[id].r;
        modify(cur);
    }
    else{
        fen[cur].l = fen[id].l;
        fen[cur].r = update(x, fen[id].r, mid+1, r);
        modify(cur);
    }
    return cur;
}
int get(int lid, int rid, int x, int l = 1, int r = n){
    if(l == r) return l;
    int d = fen[fen[rid].l].ans - fen[fen[lid].l].ans;
    int mid = (l + r) >> 1;
    if(d >= x) return get(fen[lid].l, fen[rid].l, x, l, mid);
    return get(fen[lid].r, fen[rid].r, x - d, mid+1, r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    ifstream cin("mkthnum.inp");
    cin >> n >> m;
    FOR(i, 1, n){
        cin >> a[i];
        s.push_back(a[i]);
    }
    sort(all(s));
    FOR(i, 1, n) a[i] = lower_bound(all(s), a[i]) - s.begin() + 1;
    FOR(i, 1, n)
        ver[i] = update(a[i], ver[i-1]);
    while(m--){
        int l, r, k;
        cin >> l >> r >> k;
        cout << s[get(ver[l-1], ver[r], k)-1] << '\n';
    }

}
