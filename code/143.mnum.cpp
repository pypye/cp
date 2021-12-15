#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn
using namespace std;
int n, m;
long long getnum(long long k){
    long long sum = 0;
    for(long long i = 1; i <= k; i *= 10)
        sum += 1ll * (k - i + 1);
    return sum;
}
int getpos(long long k){
    long long l = 0, r = 1e18 + 1;
    while(r - l > 1){
        long long mid = (l + r) / 2;
        if(getnum(mid) >= k) r = mid;
        else l = mid;
    }
    k = getnum(r) - k;
    while(k--) r /= 10;
    return r % 10;
}
int get(long long k){
    long long x = getnum(k), pos = 1;
    while(pos * 4 - 2 <= x) pos = pos * 4 - 2;
    return getpos(pos);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("mnum.inp");
//    ofstream cout("mnum.out");
    cin >> n;
    FOR(i, 1, n){
        long long k;
        cin >> k;
        cout << get(k);
    }
}
