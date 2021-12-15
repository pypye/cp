//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 100005
using namespace std;
int n, a[maxn], fen[maxn][2], ans;
vector <int> s;
void Lupdate(int x, int val){
    for(; x <= n+1; x += x & -x) fen[x][0] = max(fen[x][0], val);
}
int Lget(int x){
    int ans = 0;
    for(; x; x -= x & -x) ans = max(ans, fen[x][0]);
    return ans;
}
void Rupdate(int x, int val){
    for(; x; x -= x & -x) fen[x][1] = max(fen[x][1], val);
}
int Rget(int x){
    int ans = 0;
    for(; x <= n+1; x += x & -x) ans = max(ans, fen[x][1]);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("beads.inp");
    ofstream cout("beads.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i], s.push_back(a[i]);
    #define all(s) s.begin(), s.end()
    sort(all(s));
    FOR(i, 1, n) a[i] = lower_bound(all(s), a[i]) - s.begin() + 1;
    FORR(i, n, 1){
        int p = Lget(a[i]-1) + 1;
        int q = Rget(a[i]+1) + 1;
        ans = max(ans, p + q - 1);
        Lupdate(a[i], p);
        Rupdate(a[i], q);
    }
    cout << ans;
}
