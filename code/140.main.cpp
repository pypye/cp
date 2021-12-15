//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
int n, m, k, r[maxn];
struct edge{
    int u, v, w;
    bool operator < (const edge &x){
        return w < x.w;
    }
}query[maxn];
int gr(int u){
    return r[u] > 0 ? r[u] = gr(r[u]) : u;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    FOR(i, 1, k){
        int x;
        cin >> x, r[x] = -1;
    }
    FOR(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        query[i] = {u, v, w};
    }
    sort(query+1, query+m+1);
    FOR(i, 1, m){
        int p = gr(query[i].u), q = gr(query[i].v);
        if(p > q) swap(p, q);
        if(p != q){
            r[p] += r[q];
            r[q] = p;
            if(r[p] == -k){
                while(k--) cout << query[i].w << " ";
                return 0;
            }
        }
    }
}
