//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define M 1000000000000000000
#define maxn 100005
using namespace std;
int n;
struct point{
    long long x, y;
}p[5];
struct rtg{
    long long u, v, x, y;
}rect[maxn];
pair <long long, long long> pro(long long x, long long u){
    long long cnt = (x - u) + 1, c, l;
    if(abs(x) % 2 == 0 && abs(u) % 2 == 1) c = l = cnt/2;
    if(abs(x) % 2 == 1 && abs(u) % 2 == 0) c = l = cnt/2;
    if(abs(x) % 2 == 0 && abs(u) % 2 == 0) l = cnt/2, c = cnt - l;
    if(abs(x) % 2 == 1 && abs(u) % 2 == 1) c = cnt/2, l = cnt - c;
    return {c, l};
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("pinpos.inp");
    ofstream cout("pinpos.out");
    cin >> n;
    FOR(i, 1, n){
        FOR(k, 1, 4){
            long long x, y;
            cin >> x >> y;
            p[k] = {x+y, x-y};
        }
        rect[i] = {M, M, -M, -M};
        FOR(k, 1, 4){
            rect[i].u = min(p[k].x, rect[i].u);
            rect[i].x = max(p[k].x, rect[i].x);
            rect[i].v = min(p[k].y, rect[i].v);
            rect[i].y = max(p[k].y, rect[i].y);
        }
    }
    long long u = -M, v = -M, x = M, y = M;
    FOR(i, 1, n){
        u = max(u, rect[i].u+1);
        v = max(v, rect[i].v+1);
        x = min(x, rect[i].x-1);
        y = min(y, rect[i].y-1);
    }
    if(u >= x || v >= y) return cout << 0, 0;
    pair <long long, long long> l = pro(x, u), r = pro(y, v);
    cout << 1ll * l.F * r.F + 1ll * l.S * r.S;

}
