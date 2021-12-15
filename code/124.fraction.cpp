#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 1000005
using namespace std;
long long n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("fraction.inp");
    ofstream cout("fraction.out");
    while(cin >> n)
    {
            long long k = n/2;
            long long k1 = n - k;
            while(__gcd(k, k1) != 1) k--, k1++;
            cout << k << " " << k1 << '\n';

    }

}
