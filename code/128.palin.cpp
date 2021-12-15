#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn
using namespace std;
int n;
long long f[115][115], mod = 1000000007;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("palin.inp");
    //ofstream cout("palin.out");
    cin >> s;
    n = s.size();
    s = ' ' + s;
    FOR(i, 1, n) f[i][i] = 1;
    FORR(i, n, 1)
        FOR(j, i+1, n)
        {
            f[i][j] = (f[i+1][j] + f[i][j-1] - f[i+1][j-1] + mod * mod) % mod;
            if(s[i] == s[j]) f[i][j] += (f[i+1][j-1] + 1) % mod;
        }
    cout << f[1][n] % mod;
}
