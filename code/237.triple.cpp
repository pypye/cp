#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORR(i, a, b) for(int i = (a); i >= (b); --i)
#define maxn 10005
using namespace std;
int n, m, a[maxn], mod = 1000000007;
long long ans;
void Mod(long long &x, int v){
    x += v;
    if(x >= mod)  x -= mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    ifstream cin("triple.inp");
//    ofstream cout("triple.out");
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    FOR(i, 1, n){
        int r = n, x;
        FOR(j, i+1, n){
            if (r == j-1) x--, r++;
            if (a[j] == a[j-1] && j != i+1) {Mod(ans, x); continue;}
            x = 0;
            int re = m - a[i] - a[j];
            if (re < a[j]) break;
            while(a[r] > re) r--;
            while(a[r] == re && r > j) Mod(ans, 1), r--, x++;
        }
    }
    cout << ans;
}
