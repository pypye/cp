//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 200005
#define F first
#define S second
using namespace std;
int n, ans = 1;
struct point{
    int x, y;
};
struct edge{
    int x1, y1, x2, y2;
    bool operator < (const edge& o) const{
        if (x2 < o.x2) return 1ll*(y2 - o.y1)*(o.x2 - o.x1) < 1ll*(o.y2 - o.y1)*(x2 - o.x1);
        return 1ll*(o.y2 - y1)*(x2 - x1) > 1ll*(y2 - y1)*(o.x2 - x1);
    }
}a[maxn];
vector <edge> l;
pair <pair <int, int>, pair <edge, int>> E[maxn];
set <pair <edge, int>> s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("hillwalk.inp");
//    ofstream cout("hillwalk.out");
    cin >> n;
    FOR(i, 1, n){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {x1, y1, x2, y2};
        E[2*i - 1] = {{a[i].x1, 0}, {a[i], i}};
        E[2*i] = {{a[i].x2, 1}, {a[i], i}};
    }
    sort(E+1, E+2*n+1);
    int cur = 1;
    FOR(i, 1, 2*n){
        if(E[i].F.S == 0) s.insert(E[i].S);
        else{
            if(E[i].S.S == cur){
                auto it = s.find(E[i].S);
                if(it == s.begin()) continue;
                --it;
                cur = (*it).S;
                if(a[cur].x2 >= E[i].F.F) ans++;
            }
            s.erase(E[i].S);
        }
    }
    cout << ans;
}
