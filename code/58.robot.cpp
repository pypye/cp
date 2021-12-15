//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORR(i, a, b) for(int i = (a); i >= (b); --i)
#define pair pair <int, int>
#define F first
#define S second
#define maxn 300005
using namespace std;
int n, m, k, cnt, fen[maxn];
long long sum;
struct data{
    int x1, y1, x2, y2;
}q[maxn];
bool comp1(data A, data B){ if(A.x1 == B.x1) return A.y1 < B.y1; return A.x1 < B.x1; }
bool comp2(data A, data B){ if(A.y1 == B.y1) return A.x1 < B.x1; return A.y1 < B.y1; }
bool comp3(pair A, pair B){ return A.S < B.S; }
bool comp4(pair A, pair B){ return A.S > B.S; }
vector <data> row, col, pre;
vector <pair> q1, qm, r[maxn];
vector <int> s;
pair Find(int x, int y, char ty){
    if(ty == 'E') y = m; if(ty == 'W') y = 1;
    if(ty == 'N') x = n; if(ty == 'S') x = 1;
    return {x, y};
}
#define all(s) s.begin(), s.end()
void Resize(){
    sort(all(row), comp1);
    sort(all(col), comp2);
    if(row.size())
        FOR(i, 0, row.size()-1){
            int x = i, M = row[x].y2;
            while(x < row.size() && row[i].x1 == row[x].x1 && M >= row[x].y1) M = max(M, row[x++].y2);
            q[++cnt] = {row[i].x1, row[i].y1, row[i].x1, M};
            if(M == m) qm.emplace_back(row[i].x1, row[i].y1);
            else q1.emplace_back(row[i].x1, M);
            i = x-1;
        }
    if(col.size())
        FOR(i, 0, col.size()-1){
            int x = i, M = col[x].x2;
            while(x < col.size() && col[i].y1 == col[x].y1 && M >= col[x].x1) M = max(M, col[x++].x2);
            q[++cnt] = {col[i].x1, col[i].y1, M, col[i].y1};
            pre.push_back({col[i].y1, col[i].x1, M, 0});
            i = x-1;
        }
    sort(all(q1), comp3);
    sort(all(qm), comp4);
}
void low(int &x){
    x = lower_bound(all(s), x) - s.begin() + 1;
}
void compress(){
    for(auto v : q1) s.push_back(v.F), s.push_back(v.S);
    for(auto v : qm) s.push_back(v.F), s.push_back(v.S);
    for(auto v : pre) s.push_back(v.x1), s.push_back(v.y1), s.push_back(v.x2);
    sort(all(s));
    for(auto &v : q1) low(v.F), low(v.S);
    for(auto &v : qm) low(v.F), low(v.S);
    for(auto &v : pre){
        low(v.x1), low(v.y1), low(v.x2);
        r[v.x1].push_back({v.y1, v.x2});
    }
}
void update(int x, int val){
    for(; x; x -= x & -x) fen[x] += val;
}
long long get(int x){
    long long ans = 0; if(!x) return 0;
    for(; x < maxn; x += x & -x) ans += 1ll*fen[x];
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
    cin >> n >> m >> k;
    FOR(i, 1, k){
        int u, v; char ty;
        cin >> u >> v >> ty;
        pair x = Find(u, v, ty);
        if(x.S == v){
            if(x.F < u) swap(u, x.F), swap(v, x.S);
            col.push_back({u, v, x.F, x.S});
        }
        else if(x.F == u){
            if(x.S < v) swap(u, x.F), swap(v, x.S);
            row.push_back({u, v, x.F, x.S});
        }
    }
    Resize();
    compress();
    FOR(i, 1, cnt) sum += 1ll*abs(q[i].x1 - q[i].x2) + abs(q[i].y1 - q[i].y2) + 1;
    int x = 0;
    FOR(high, 1, maxn-1){
        for(auto v : r[high]) update(v.S, 1), update(v.F-1, -1);
        while(x < q1.size() && q1[x].S <= high) sum -= get(q1[x++].F);
    }
    memset(fen, 0, sizeof fen);
    x = 0;
    FORR(high, maxn-1, 1){
        for(auto v : r[high]) update(v.S, 1), update(v.F-1, -1);
        while(x < qm.size() && qm[x].S >= high) sum -= get(qm[x++].F);
    }
    cout << sum;
}
