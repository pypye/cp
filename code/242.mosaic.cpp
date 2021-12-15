//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 200005

using namespace std;
int n, k, a[maxn], b[maxn], p[maxn], q[maxn];
bool check(int u, int v){
    return a[u] == a[v] || b[u] == b[v];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("mosaic.inp");
    ofstream cout("mosaic.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i] >> b[i];
    FOR(i, 1, n){
        if(a[i] != a[i-1]) p[i] = i-1;
        else p[i] = p[i-1];
        if(b[i] != b[i-1]) q[i] = i-1;
        else q[i] = q[i-1];
    }
    cin >> k;
    while(k--){
        int l, r;
        cin >> l >> r;
        if(p[r] < l || q[r] < l) cout << "0 0\n";
        else{
            int u = p[r], v = q[r];
            if(!check(u, v)) cout << u << " " << v << '\n';
            else if(!check(u, r)) cout << u << " " << r << '\n';
            else cout << v << " " << r << '\n';
        }
    }

}
