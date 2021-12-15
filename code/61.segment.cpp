//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 400005
using namespace std;
int n, t, res, sum;
pair a[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("segment.inp");
//    ofstream cout("segment.out");
    cin >> n >> t;
    FOR(i, 1, n){
        int l, r;
        cin >> l >> r;
        if(r - t == l) continue;
        a[i] = {l, -1};
        a[i+n] = {r-t, 1};
    }
    sort(a+1, a+2*n+1);
    FOR(i, 1, n+n){
        sum += a[i].second;
        res = max(res, sum);
    }
    cout << res;
}
