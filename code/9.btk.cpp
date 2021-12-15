//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005
using namespace std;
int n, k;
long long f[maxn], mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("btk.inp");
    ofstream cout("btk.out");
    cin >> n >> k;
    f[0] = 1;
    FOR(i, 1, n)
        FOR(j, 0, k-1){
            if(j < i) f[i] = (f[i] + f[i-j-1]) % mod;
            if(j == i) f[i]++;
        }
    cout << f[n];
}

