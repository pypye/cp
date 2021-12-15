#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 50005
using namespace std;
int p, v;
long long n;
long long solve(long long n, int p, int v, int k){
    long long fact = (long long) pow(n, 1.0/k);
    int cnt = 0;
    while(pow(fact + 1, cnt) * pow(fact, k - cnt) < n) cnt++;
    return (k * fact + cnt) * p + k * v;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("meetings.inp");
    //ofstream cout("meetings.out");
    cin >> n >> p >> v;
    if(n == 1) return cout << 0, 0;
    long long res = solve(n, p, v, 1);
    for(int k = 2; 2ll << k < n; k++){
        res = min(res, solve(n, p, v, k));
    }
    cout << res;
}
