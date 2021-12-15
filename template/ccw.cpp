#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 2005
using namespace std;
int n;
double ans;
struct point{
    double x,y;
} a[maxn], p[maxn];
point  operator -(const point& u, const point& v){
    return {u.x - v.x, u.y - v.y};
}
double operator *(const point& u, const point& v){
    return u.x*v.y - u.y*v.x;
}
double dis(point a, point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double calc(int x, int y, int z) {
    double a = dis(p[x], p[y]);
    double b = dis(p[y], p[z]);
    double c = dis(p[x], p[z]);
    double p = (a + b + c) / 2.0;
    return sqrt(p*(p - a)*(p - b)*(p - c));
}
bool comp(point a, point b){
    if (a.x == b.x) return a.y < b.y; return a.x < b.x;
}
bool ccw(point a, point b, point c){
    return (b-a)*(c-b) > 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //ifstream cin("A.inp");
    cin >> n;
    FOR(i, 1, n) cin >> a[i].x >> a[i].y;
    sort(a+1, a+n+1, comp);
    int m = 0, m1;
    FOR(i, 1, n){
        while (m >= 2 && !ccw(p[m-2], p[m-1], a[i])) m--;
        p[m++] = a[i];
    }
    m1 = m;
    FORR(i, n-1, 1)
    {
        while (m > m1 && !ccw(p[m-2], p[m-1], a[i])) m--;
        p[m++] = a[i];
    }
    FOR(i, 1, n)
        FOR(j, i+1, n){
            int l = j, r = n+1;
            while(r - l > 1){
                int mid = (l + r) / 2;
                if(calc(i, j, mid) > calc(i, j, mid-1)) l = mid;
                else r = mid;
            }
            ans = max(ans, calc(i, j, l));
        }
    cout << fixed << setprecision(1) << ans;
}
