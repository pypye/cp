#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define all(s) s.begin(), s.end()
#define maxn 200005
using namespace std;
using Array = int[maxn];
int n, k;
Array l, r, query, root;
vector <int> s;
int gr(int u){
    return root[u] ? root[u] = gr(root[u]) : u;
}
void Add(int u, int v){
    int p = gr(v), q = gr(u);
    if(p != q) root[q] = p;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("od.inp");
    ofstream cout("od.out");
    cin >> n >> k;
    FOR(i, 1, k){
        string x;
        cin >> l[i] >> r[i] >> x;
        l[i]--;
        s.push_back(l[i]);
        s.push_back(r[i]);
        if(x == "odd") query[i] = 1;
    }
    sort(all(s));
    n = s.size();
    FOR(i, 1, k){
        int u = lower_bound(all(s), l[i]) - s.begin() + 1;
        int v = lower_bound(all(s), r[i]) - s.begin() + 1;
        if(query[i]) Add(u, v+n), Add(u+n,v);
        else Add(u, v), Add(u+n, v+n);
        if(gr(u) == gr(u+n) || gr(v) == gr(v+n)) return cout << i -1, 0;
    }
    cout << k;
}
