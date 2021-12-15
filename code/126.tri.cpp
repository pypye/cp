#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= b; i++)
#define FORR(i, a, b) for(int i = (a); i >= b; i--)
#define maxn 100005
using namespace std;
int k, m, cnt, ans[maxn];
struct point{
    float x, y;
}a[maxn];
float sign(point p1, point p2, point p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}
bool checkpoint(point pt, point v1, point v2, point v3)
{
    bool b1, b2, b3;
    b1 = sign(pt, v1, v2) < 0.0f;
    b2 = sign(pt, v2, v3) < 0.0f;
    b3 = sign(pt, v3, v1) < 0.0f;
    return ((b1 == b2) && (b2 == b3));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("tri.inp");
    ofstream cout("tri.out");
    cin >> k >> m;
    FOR(i, 1, k) cin >> a[i].x >> a[i].y;
    while(m--){
        point B, C;
        cin >> B.x >> B.y >> C.x >> C.y;
        bool check = 1;
        FOR(i, 1, k) if(checkpoint(a[i], {0,0}, B, C)){
            check = 0;
            break;
        }
        if(check) cout <<"N\n";
        else cout<< "Y\n";
    }
}
