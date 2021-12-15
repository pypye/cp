//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 2005

using namespace std;
int n, m;
long long T[4][maxn][maxn];
void update(int p, int q, long long v, int node){
    for(int i = p; i <= m; i += i & -i)
        for(int j = q; j <= n; j += j & -j) T[node][i][j] += v;
}
long long get(int p, int q, int node){
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
    long long val1 = fget(x2, y2);
    long long val2 = fget(x2, y1-1);
    long long val3 = fget(x1-1, y2);
    long long val4 = fget(x1-1, y1-1);
    return val1 - val2 - val3 + val4;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    ifstream cin("it.inp");
//    ofstream cout("it.out");
    int t; cin >> t;
    while(t--){
        memset(T, 0, sizeof T);
        cin >> n;
        m = n;
        string s;
        while(cin >> s){
            if(s == "END") break;
            if(s == "SET"){
                int x, y, k;
                cin >> x >> y >> k;
                ++x, ++y;
                update_range(x, y, x, y, k);
            }
            if(s == "SUM"){
                int x, y, u, v;
                cin >> x >> y >> u >> v;
                ++x, ++y, ++u, ++v;
                cout << get_range(x, y, u, v) << '\n';
            }
        }
    }
}
