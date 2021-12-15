//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 1005
using namespace std;
int h, w, n, f[maxn][maxn], a[11][maxn][maxn], save[maxn][maxn], ans = -1;
struct data{
    int x, y, u, v;
} re[11];
inline bool bit(int x, int i){
    return ((x >> i) & 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("pixels.inp", "r", stdin);
    freopen("pixels.out", "w", stdout);
    cin >> h >> w;
    cin >> n;
    FOR(i, 0, n-1){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        re[i] = {x, y, u, v};
        FOR(p, x, u)
            FOR(q, y, v) cin >> a[i][p][q];
    }
    FOR(x, 0, (1 << n)-1){
        memset(f, -1, sizeof f);
        bool check = 0;
        FOR(i, 0, n-1) if(bit(x, i)){
            FOR(p, re[i].x, re[i].u){
                FOR(q, re[i].y, re[i].v)
                    if(f[p][q] == -1) f[p][q] = 1^a[i][p][q];
                    else if(f[p][q] != 1^a[i][p][q]){
                        check = 1;
                        break;
                    }
                if(check) break;
            }
            if(check) break;
        }
        else{
            FOR(p, re[i].x, re[i].u){
                FOR(q, re[i].y, re[i].v)
                    if(f[p][q] == -1) f[p][q] = a[i][p][q];
                    else if(f[p][q] != a[i][p][q]){
                        check = 1;
                        break;
                    }
                if(check) break;
            }
            if(check) break;
        }
        if(check) continue;
        int res = 0;
        FOR(i, 1, h)
            FOR(j, 1, w) if(f[i][j] <= 0) res++;
        if(ans < res){
            ans = res;
            FOR(i, 1, h)
                FOR(j, 1, w) if(f[i][j] <= 0) save[i][j] = 0;
                else save[i][j] = 1;
        }
    }
    if(ans == -1) return cout << ans, 0;
    cout << ans << '\n';
    FOR(i, 1, h){
        FOR(j, 1, w) cout << save[i][j] << " ";
        cout << '\n';
    }
}
