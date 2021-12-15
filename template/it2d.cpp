//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 1025

using namespace std;
int n, m;
int fen[16*maxn*maxn], laz[16*maxn*maxn];
    #define L(a, b) a, (a+b)/2
    #define R(a, b) (a+b)/2+1, b
    #define i1 id*4-2
    #define i2 id*4-1
    #define i3 id*4+0
    #define i4 id*4+1
void down(int id){
    int &y = laz[id];
    fen[i1] += y; laz[i1] += y;
    fen[i2] += y; laz[i2] += y;
    fen[i3] += y; laz[i3] += y;
    fen[i4] += y; laz[i4] += y;
    y = 0;
}
void update(int x, int y, int u, int v, int val, int id = 1, int xl = 1, int xr = n, int yl = 1, int yr = m){
    if(x > xr || y > yr || u < xl || v < yl || xl > xr || yl > yr) return;
    if(u >= xr && v >= yr && x <= xl && y <= yl){
        fen[id] += val;
        laz[id] += val;
        return;
    }
    down(id);
    update(x, y, u, v, val, i1, L(xl, xr), L(yl, yr));
    update(x, y, u, v, val, i2, L(xl, xr), R(yl, yr));
    update(x, y, u, v, val, i3, R(xl, xr), L(yl, yr));
    update(x, y, u, v, val, i4, R(xl, xr), R(yl, yr));
    fen[id] = fen[i1] + fen[i2] + fen[i3] + fen[i4];
}
int get(int x, int y, int u, int v, int id = 1, int xl = 1, int xr = n, int yl = 1, int yr = m) {
    if(x > xr || y > yr || u < xl || v < yl || xl > xr || yl > yr) return 0;
    if(u >= xr && v >= yr && x <= xl && y <= yl) return fen[id];
    down(id);
    int aa = get(x, y, u, v, i1, L(xl, xr), L(yl, yr));
    int bb = get(x, y, u, v, i2, L(xl, xr), R(yl, yr));
    int cc = get(x, y, u, v, i3, R(xl, xr), L(yl, yr));
    int dd = get(x, y, u, v, i4, R(xl, xr), R(yl, yr));
    return aa + bb + cc + dd;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    ifstream cin("it.inp");
//    ofstream cout("it.out");
}
