#include <bits/stdc++.h>
#define FOR(i,x,y) for(int i=x; i<=y; ++i)
#define maxn 10005
#define maxm
#define reset(x) memset(x,0,sizeof(x));
using namespace std;
string P;
int pi[maxn];
int main()
{   
    cin >> P;
    int m = P.length();
    P = ' ' + P;
    pi[0] = -1;
    int k = -1;
    for(int i = 1; i <= m; i++)
    {
        while(k >= 0 && P[k+1] != P[i])
        k = pi[k];
        pi[i] = ++k;
    }
    FOR(i,1,m) cout << pi[i] << " ";
}


