//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 200005
#define F first
#define S second

using namespace std;
using Array = long long[maxn];

int n, m, Q;
Array w, r, val;
pair <pair<long long, long long>, int> a[maxn], query[maxn];
vector <long long> ans;
multiset <long long, greater <long long>> s;
int gr(int u){
    return r[u] ? r[u] = gr(r[u]) : u;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("corrupted.inp");
    ofstream cout("corrupted.out");
    cin >> n >> m >> Q;
    FOR(i, 1, n) cin >> w[i];
    FOR(i, 1, m){
        int u, v;
        cin >> u >> v;
        a[i] = {{u, v}, 1};
    }
    FOR(i, 1, Q){
        char type; cin >> type;
        if(type == 'D'){
            int x; cin >> x;
            query[i] = {a[x].F, 1};
            a[x].S = 0;
        }
        else{
            int u, x; cin >> u >> x;
            query[i] = {{u, w[u]}, 0};
            w[u] = x;
        }
    }
    FOR(i, 1, n) val[i] = w[i], s.insert(val[i]);
    FOR(i, 1, m)
        if(a[i].S == 1){
            int u = a[i].F.F, v = a[i].F.S;
            int p = gr(u), q = gr(v);
            if(p > q) swap(p, q);
            if(p != q){
                r[q] = p;
                s.erase(s.find(val[p]));
                s.erase(s.find(val[q]));
                val[p] += val[q];
                s.insert(val[p]);
            }
        }
    ans.push_back(*s.begin());
    FORR(i, Q, 1){
        if(query[i].S){
            int u = query[i].F.F, v = query[i].F.S;
            int p = gr(u), q = gr(v);
            if(p > q) swap(p, q);
            if(p != q){
                r[q] = p;
                s.erase(s.find(val[p]));
                s.erase(s.find(val[q]));
                val[p] += val[q];
                s.insert(val[p]);
            }
        }
        else{
            int u = query[i].F.F, rval = query[i].F.S;
            int nval = w[u], uf = u;
            u = gr(u);
            s.erase(s.find(val[u]));
            val[u] += rval - nval;
            s.insert(val[u]);
            w[uf] = rval;
        }
        ans.push_back(*s.begin());
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    for(auto v : ans) cout << v << '\n';
}
