#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1005
using namespace std;
int n, r, k;
long long a[maxn][maxn], T[4][maxn][maxn], ans;
void update(int p, int q, int v, int node){
    for(int i = p; i <= n; i += i & -i)
        for(int j = q; j <= n; j += j & -j) T[node][i][j] += v;
}
int get(int p, int q, int node){
    long long ans = 0;
    for(int i = p; i >= 1; i -= i & -i)
        for(int j = q; j >= 1; j -= j & -j) ans += T[node][i][j];
    return ans;
}
void update_range(int x1, int y1, int x2, int y2, long long k){
    update(x1, y1 , k, 0);
    update(x1, y2+1, -k, 0);
    update(x2+1, y1, -k, 0);
    update(x2+1, y2+1, k, 0);

    update(x1, y1, k*(1-y1), 1);
    update(x1, y2+1, k*y2, 1);
    update(x2+1, y1, k*(y1-1), 1);
    update(x2+1, y2+1, -y2*k, 1);

    update(x1, y1, k*(1-x1), 2);
    update(x1, y2+1, k*(x1-1), 2);
    update(x2+1, y1, k*x2, 2);
    update(x2+1, y2+1, -x2*k, 2);

    update(x1, y1, (x1-1)*(y1-1)*k, 3);
    update(x1, y2+1, -y2*(x1-1)*k, 3);
    update(x2+1, y1, -x2*(y1-1)*k, 3);
    update(x2+1, y2+1, x2*y2*k, 3);
}
long long fget(int x, int y){
    return get(x, y, 0) * x * y + get(x, y, 1) * x + get(x, y, 2) * y + get(x, y, 3);
}
long long get_range(int x1, int y1, int x2, int y2){
    int val1 = fget(x2, y2);
    int val2 = fget(x2, y1-1);
    int val3 = fget(x1-1, y2);
    int val4 = fget(x1-1, y1-1);
    return val1 - val2 - val3 + val4;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("bonus.inp");
    //ofstream cout("bonus.out");
    cin >> n >> r >> k;
    FOR(i, 1, n)
        FOR(j, 1, n) cin >> a[i][j];
    while(k--){
        int x, y;
        cin >> x >> y;
        update_range(x, y, x+r-1, y+r-1, 1);
    }
    FOR(i, 1, n)
        FOR(j, 1, n) if(get_range(i, j, i, j)) ans += a[i][j];
    cout << ans;
}
