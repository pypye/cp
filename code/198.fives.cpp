#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 2005
using namespace std;
int n, q, a[maxn], fen[4][maxn], f[maxn][maxn];
vector <int> s;
void update(int id, int x, int val){
    for(; x <= n; x += x & -x) fen[id][x] += val;
}
int get(int id, int x){
    int ans = 0;
    for(; x; x -= x & -x) ans += fen[id][x];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    ifstream cin("fives.inp");
//    ofstream cout("fives.out");
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i], s.push_back(a[i]);
    sort(s.begin(), s.end());
    FOR(i, 1, n) a[i] = lower_bound(s.begin(), s.end(), a[i]) - s.begin() + 1;
    FOR(i, 1, n){
        memset(fen, 0, sizeof fen);
        FOR(j, i, n){
            int x = a[j];
            f[i][j] = get(2, x-1);
            if(x < a[i]) update(0, x, 1);
            update(1, x, get(0, x-1));
            update(2, x, get(1, n) - get(1, x));
        }
    }
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << f[u][v] << '\n';
    }
}
