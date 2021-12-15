//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 100005
using namespace std;
int n, k, q;
vector <pair <long double, long double>> poly[maxn];
pair <double, double    > range[maxn];
struct point{
    long double x, y;
};
struct line{
    long double a, b, c;
};
point  operator -(const point& u, const point& v){
    return {u.x - v.x, u.y - v.y};
}
long double operator *(const point& u, const point& v){
    return u.x*v.y - u.y*v.x;
}
long double ccw(point a, point b, point c){
    return (b-a)*(c-b);
}
vector <pair <long double, long double>> reorder(int u, long double x){
    long double delta = 0;
    if(x == 0) delta = x - 1.0*range[u].F;
    else delta = x - 1.0*range[u].S;
    vector <pair <long double, long double>> ans;
    for(auto v : poly[u]) ans.push_back({1.0*v.F + delta, v.S});
    return ans;
}
bool intersect(point p1, point p2, point p3, point p4){
    long double a = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    long double b = ccw(p3, p4, p1) * ccw(p3, p4, p2);
    return a < 0 && b < 0;
}
bool check(int u, int v, long double mid){
    vector <pair <long double, long double>> pu = reorder(u, 0);
    vector <pair <long double, long double>> pv = reorder(v, mid);
    pu.push_back(pu[0]);
    pv.push_back(pv[0]);
    FOR(i, 0, pu.size()-2){
        point x = {pu[i].F, pu[i].S};
        point y = {pu[i+1].F, pu[i+1].S};
        FOR(j, 0, pv.size()-2){
            point z = {pv[j].F, pv[j].S};
            point t = {pv[j+1].F, pv[j+1].S};
            if(intersect(x, y, z, t)) return 0;
        }
    }
    return 1;
}
long double calc(int u, int v, long double x){
    vector <pair <long double, long double>> pu = reorder(u, 0);
    vector <pair <long double, long double>> pv = reorder(v, x);
    long double low = 1e18, high = -1e18;
    FOR(i, 0, pu.size()-1) low = min(low, pu[i].F), high = max(high, pu[i].F);
    FOR(i, 0, pv.size()-1) low = min(low, pv[i].F), high = max(high, pv[i].F);
    return high - low;
}
long double Find(int u, int v){
    long double l = 0, r = 1e18 + 1;
    while(r - l > 1e-9){
        long double mid = (l + r) / 2.0;
        if(check(u, v, mid)) r = mid;
        else l = mid;
    }
    return calc(u, v, l);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("toys.inp", "r", stdin);
//    freopen("toys.out", "w", stdout);
    cin >> n;
    FOR(i, 1, n){
        int k; cin >> k;
        while(k--){
            int x, y;
            cin >> x >> y;
            poly[i].push_back({x, y});
        }
    }
    FOR(i, 1, n){
        long double l = 2e18, r = -2e18;
        for(auto v : poly[i]){
            l = min(l, v.F);
            r = max(r, v.F);
        }
        range[i] = {l, r};
    }
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << fixed << setprecision(9) << min(Find(u, v), Find(v, u)) << '\n';
    }
}
