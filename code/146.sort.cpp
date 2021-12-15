#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 200005
using namespace std;
int n, a[maxn], top = INT_MIN, cnt, f[maxn];
void compress(){
    vector <int> s;
    FOR(i, 1, n)s.push_back(a[i]);
    sort(s.begin(),s.end());
    FOR(i, 1, n) a[i] = lower_bound(s.begin(),s.end(), a[i]) - s.begin() + 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("sort.inp");
    ofstream cout("sort.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    compress();
    f[n+1] = 1e9;
    FORR(i, n, 1) f[i] = min(f[i+1], a[i]);
    FOR(i, 1, n){
        top = max(top, a[i]);
        if(top <= f[i+1]){
            cnt++;
            top = INT_MIN;
        }
    }
    cout << cnt;
}
