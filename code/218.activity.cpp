#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 400005
using namespace std;
int T;
long long m, n, k, a, b;
bool check(long long mid){
    if(n - b * mid < 0) return 0;
    if(m - a * mid < 0) return 0;
    return (m - a * mid + n - b * mid >= k);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream  cin("activity.inp");
    ofstream cout("activity.out");
    cin >> T;
    while(T--){
        cin >> m >> n >> k >> a >> b;
        long long l = 0, r = min(m/a, n/b) + 1;
        while(r - l > 1){
            long long mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        cout << l << '\n';
    }
}
