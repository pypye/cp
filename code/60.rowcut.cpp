//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 3005
using namespace std;
int m, n;
long long h[maxn][maxn], p[maxn];
char a[maxn][maxn];
const int base = 31;
const int mod = 1e9 + 7;
string str[maxn];
long long gethash(int i, int l, int r){
    return (h[i][r] - h[i][l-1] * p[r - l + 1] + 1ll*mod*mod) % mod;
}
bool check(int mid){
    set <long long> s;
    FOR(i, 1, n) s.insert(gethash(i, 1, mid));
    return s.size() == n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("rowcut.inp");
    ofstream cout("rowcut.out");
    cin >> m >> n;
    FOR(i, 1, m)
        FOR(j, 1, n){
            cin >> a[i][j];
            str[j] += a[i][j];
        }
    p[0] = 1;
    FOR(i, 1, m) p[i] = (p[i-1] * base) % mod;
    FOR(i, 1, n)
        FOR(j, 1, m) h[i][j] = (h[i][j-1] * base + str[i][j-1] - 'a' + 1) % mod;
    int l = -1, r = m+1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << m - r;
}
