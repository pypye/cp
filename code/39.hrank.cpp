#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 300005
using namespace std;
int n, hmax, a[maxn], h[maxn], d[maxn];
void update(int x){
    for(; x; x -= x & (-x)) d[x]++;
}
int get(int x){
    int ans = 0;
    for(; x <= n; x += x & (-x)) ans += d[x];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("hrank.inp");
    ofstream cout("hrank.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FORR(i, n, 1){
        int l = 0, r = n+1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(n - mid - get(mid+1) <= a[i]) r = mid;
            else l = mid;
        }
        h[i] = r;
        update(h[i]);
    }
    FOR(i, 1, n) cout << h[i] << " ";
}
