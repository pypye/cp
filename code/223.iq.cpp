#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, a[maxn], b[maxn];
bool compare(int x, int y){
    x = sqrt(1ll*x*x + 1ll*x*x);
    return x <= y;
}
bool check(int k){
    FOR(i, 1, k) if(!compare(a[i], b[n - i + 1])) return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream  cin("iq.inp");
    ofstream cout("iq.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    int l = 0, r = n+1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    FOR(i, 1, l) cout << i + l << " ";
    FOR(i, l+1, n) cout << i - l << " ";
}
