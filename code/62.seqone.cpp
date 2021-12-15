#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 55
using namespace std;
long long n, k, m, f[maxn][maxn], g[maxn][maxn], check;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("seqone.inp");
    ofstream cout("seqone.out");
    cin >> n >> k >> m;
    g[0][0] = 1;
    FOR(i, 1, n)
        FOR(j, 0, k){
            f[i][j] = f[i-1][j] + g[i-1][j-1];
            g[i][j] = f[i-1][j] + g[i-1][j];
        }
    while(n){
        if(m > g[n][k]){
            cout << 1;
            m -= g[n][k];
            if(!check) k--;
            check = 1;
        }
        else{
            cout << 0;
            check = 0;
        }
        n--;
    }
}
