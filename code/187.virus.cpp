//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 1005
using namespace std;
string s, str[21];
int k, base = 31, mod = 1000000007;
long long p[maxn], h[maxn];
long long gethash(int l, int r){
    return (h[r] - h[l-1] * p[r-l+1] + 1ll*mod*mod) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("virus.inp");
    //ofstream cout("virus.out");
    cin >> s; q.push(s);
    int n = s.size();
    s = ' ' + s;
    p[0] = 1;
    FOR(i, 1, n) p[i] = (p[i-1] * base) % mod;
    FOR(i, 1, n) h[i] = (h[i-1] * base + s[i] - 'A' + 1) % mod;

}
