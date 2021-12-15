//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define all(s) s.begin(), s.end()
#define maxn 80005
using namespace std;
int n, m;
unordered_set <int> M[maxn];
struct data{
    int u, v, x, y;
}q[maxn], d[maxn];
bool check(data A, data B){
    if(A.u <= B.u && B.u <= A.x)
        if(A.v <= B.v && B.v <= A.y) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("paint.inp");
    ofstream cout("paint.out");
    cin >> n >> m;
    FOR(i, 1, n){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        q[i] = {u, v, x, y};
    }
    FOR(i, 1, m){
        int u, v, ty;
        cin >> u >> v >> ty;
        d[i] = {u, v, ty, 0};
    }
    FOR(i, 1, n)
        FOR(j, 1, m){
            if(check(q[i], d[j])) M[i].insert(d[j].x);
        }
    FOR(i, 1, n) cout << M[i].size() << '\n';
}
