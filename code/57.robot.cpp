//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 1005
using namespace std;
int n, m, k, cnt;
long long sum;
struct data{
    int x1, y1, x2, y2;
}q[maxn];
bool comp1(data A, data B){
    if(A.x1 == B.x1) return A.y1 < B.y1;
    return A.x1 < B.x1;
}
bool comp2(data A, data B){
    if(A.y1 == B.y1) return A.x1 < B.x1;
    return A.y1 < B.y1;
}
vector <data> row, col;
pair Find(int x, int y, char ty){
    if(ty == 'E') y = m; if(ty == 'W') y = 1;
    if(ty == 'N') x = n; if(ty == 'S') x = 1;
    return {x, y};
}
bool check(data A, data B){
    if(A.x1 != A.x2) swap(A, B);
    if(A.y1 <= B.y1 && B.y1 <= A.y2)
        if(B.x1 <= A.x1 && A.x1 <= B.x2) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
    cin >> n >> m >> k;
    FOR(i, 1, k){
        int u, v; char ty;
        cin >> u >> v >> ty;
        pair x = Find(u, v, ty);
        if(x.first == u){
            if(x.second < v) swap(u, x.first), swap(v, x.second);
            row.push_back({u, v, x.first, x.second});
        }
        else if(x.second == v){
            if(x.first < u) swap(u, x.first), swap(v, x.second);
            col.push_back({u, v, x.first, x.second});
        }
    }
    sort(row.begin(), row.end(), comp1);
    sort(col.begin(), col.end(), comp2);
    if(row.size())
        FOR(i, 0, row.size()-1){
            int x = i, M = row[x].y2;
            while(x < row.size() && row[i].x1 == row[x].x1 && M >= row[x].y1) M = max(M, row[x++].y2);
            q[++cnt] = {row[i].x1, row[i].y1, row[i].x1, M};
            i = x-1;
        }
    if(col.size())
        FOR(i, 0, col.size()-1){
            int x = i, M = col[x].x2;
            while(x < col.size() && col[i].y1 == col[x].y1 && M >= col[x].x1) M = max(M, col[x++].x2);
            q[++cnt] = {col[i].x1, col[i].y1, M, col[i].y1};
            i = x-1;
        }
    FOR(i, 1, cnt){
        sum += 1ll * abs(q[i].x1 - q[i].x2) + abs(q[i].y1 - q[i].y2) + 1;
        FOR(j, i+1, cnt) sum -= check(q[i], q[j]);
    }
    cout << sum;
}
