#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 205
#define eps 1e-6
using namespace std;
int n, m, res;
struct point{
    float x, y;
};
point a[maxn], b[maxn];
float side(point A, point B, point C){
    return (A.x - C.x) * (B.y - C.y) - (B.x - C.x) * (A.y - C.y);
}

bool check(point M, point A, point B, point C){
    bool b1, b2, b3;
    b1 = side(M, A, B) < 0;
    b2 = side(M, B, C) < 0;
    b3 = side(M, C, A) < 0;
    return ((b1 == b2) && (b2 == b3));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("rbtriang.inp");
    //ofstream cout("rbtriang.out");
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i].x >> a[i].y;
    FOR(i, 1, m) cin >> b[i].x >> b[i].y;
    FOR(i, 1, n)
        FOR(j, i+1, n)
            FOR(k, j+1, n){
                int flag = 1;
                FOR(x, 1, m) if(check(b[x], a[i], a[j], a[k]) == 1){
                    flag = 0;
                    break;
                }
                res += flag;
            }
    cout << res;
}
