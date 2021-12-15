#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn
using namespace std;
vector <int> ans;
int n, res, base[11];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("binaryf.inp");
    ofstream cout("binaryf.out");
    cin >> n;
    base[0] = 1;
    FOR(i, 1, 9) base[i] = base[i-1] * 10;
    FOR(i, 1, (1 << 9)-1){
        int k = 0;
        FOR(x, 0, 8) k += base[x] * ((i >> x) & 1);
        ans.push_back(k);
    }
    for(auto v : ans) if(v <= n) res++;
    cout << res;
}
