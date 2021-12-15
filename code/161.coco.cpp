#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005
using namespace std;
int n, a[maxn], r[maxn], d[maxn];
int gr(int u){
    return r[u] ? r[u] = gr(r[u]) : u;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("coco.inp");
    //ofstream cout("coco.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n)
        FOR(j, 1, i-1){
            if(__gcd(a[i], a[j]) == 1){
                int p = gr(a[i]), q = gr(a[j]);
                if(p > q) swap(p, q);
                if(p != q){
                    r[q] = p;
                }
            }
        }
    FOR(i, 1, n) d[gr(a[i])] = 1;
    cout << count(d+1, d+maxn+1, 1);
}
