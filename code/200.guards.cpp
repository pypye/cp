//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 1005
#define eps 1e-6
using namespace std;
int n;
double s;
struct point{
    double x, y;
} a[maxn], p[maxn];
vector <point> ans;
struct triplet{
    double a, b, c;
}line[maxn];
triplet make_line(point p1, point p2){
    double a = p1.y - p2.y;
    double b = p2.x - p1.x;
    double c = -(a*p1.x + b*p1.y);
    return {a, b, c};
}
bool Intersect(triplet l1, triplet l2, point p1, point p2){
    double t1 = (p1.x*l2.a + p1.y*l2.b + l2.c) * (p2.x*l2.a + p2.y*l2.b + l2.c);
    double t2 = (p1.x*l1.a + p1.y*l2.b + l1.c) * (p2.x*l1.a + p2.y*l1.b + l1.c);
    return (t1 < 0) && (t2 < 0);
}
point common(triplet l1, triplet l2){
    double x;
    if(l1.a*l2.b - l2.a*l1.b == 0) x = 0;
    else x = (l2.c*l1.b - l1.c*l2.b) / (l1.a*l2.b - l2.a*l1.b);
    double y = (-l1.c - l1.a * x) / l1.b;
    return {x, y};
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("guards.inp");
    cin >> n;
    FOR(i, 1, n) cin >> a[i].x >> a[i].y;
    a[n+1] = a[1];
    FOR(i, 1, n) line[i] = make_line(a[i], a[i+1]);
    FOR(i, 1, n){
        FOR(j, 1, n){
            if(i == j || !Intersect(line[i], line[j], a[i], a[j])) continue;
            ans.push_back(common(line[i], line[j]));
        }
    }
    ans.push_back(ans[0]);
    FOR(i, 0, ans.size()-2){
        point p = ans[i];
        point q = ans[i+1];
        s += 1ll * (p.x - q.x) * (p.y + q.y);
    }
    cout << s/2;

}
