//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
using Ar = int[maxn];
struct data{
    int l, r, x, y;
}Q[maxn];
int n, m;
long long fen[maxn][2];
Ar h, p, l, r;
void update(int x, long long val, bool i){
    for(; x; x -= x & (-x)) fen[x][i] += val;
}
long long get(int x, bool i){
    long long ans = 0;
    if(!x) return ans;
    for(; x <= n; x += x & -x) ans += fen[x][i];
    return ans;
}
void updateQ(data c){
    if(!c.l) return;
    update(c.l-1, -(c.x - c.l * c.y), 0);
    update(c.r, c.x - c.l * c.y, 0);
    update(c.l-1, -c.y, 1);
    update(c.r, c.y, 1);
}
long long getQ(int x){
    return get(x, 1) * x + get(x, 0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("growup.inp");
    ofstream cout("growup.out");
    cin >> n;
    FOR(i, 1, n) cin >> h[i];
    FOR(i, 1, n) cin >> p[i];
    cin >> m;
    FOR(i, 1, m){
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        Q[i] = {l, r, x, y};
    }
    FOR(i, 1, n) r[i] = m+1, l[i] = -1;
    FORR(time, log2(m)+2, 1){
        memset(fen, 0, sizeof fen);
        vector <int> mid[maxn];
        FOR(i, 1, n) if(l[i] != r[i]-1) mid[(l[i] + r[i]) / 2].push_back(i);
        FOR(i, 0, m){
            updateQ(Q[i]);
            for(auto x : mid[i]){
                if(getQ(x) + h[x] >= p[x]) r[x] = i;
                else l[x] = i;
            }
        }
    }
    FOR(i, 1, n) if(r[i] > m) cout << -1 << " ";
    else cout << r[i] << " ";
}
