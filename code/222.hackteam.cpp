#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 2005
using namespace std;
int T, n, m, a[maxn], b[maxn], x[maxn], d[maxn], tr[(1 << 20) + 5];
int mod = 1000000007;
void reset(){
    memset(d, 0, sizeof d);
    memset(tr, 0, sizeof tr);
}
int power(int x,  int k)
{
    if(k == 0) return 1;
    long long b = power(x, k/2);
    b = (b * b) % mod;
    if(k & 1) b = (b * x) % mod;
    return b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("hackteam.inp");
    ofstream cout("hackteam.out");
    cin >> T;
    while(T--){
        int ans = 0;
        cin >> n >> m;
        reset();
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) cin >> b[i], a[i] = b[i] ^ a[i];
        FOR(i, 1, m) cin >> x[i];
        queue <int> p, q;
        q.push(0);
        tr[0] = -1;
        FOR(i, 1, m){
            if(tr[x[i]]) continue;
            while(q.size()){
                int u = q.front(); q.pop();
                p.push(u);
                p.push(u ^ x[i]);
                tr[u ^ x[i]] = i;
            }
            swap(p, q);
        }
        bool check = 0;
        FOR(i, 1, n){
            int u = a[i];
            while(u){
                if(tr[u] == 0) {u = -1; break;}
                d[tr[u]]++;
                u = u ^ x[tr[u]];
            }
            if(u == -1) {check = 1; break;}
        }
        if(check) cout << -1 << '\n';
        else{
            FOR(i, 1, m) if(d[i]) ans += power(2, i-1);
            cout << ans << '\n';
        }
    }
}
