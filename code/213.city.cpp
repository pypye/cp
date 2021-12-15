#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
using namespace std;
int T, n, s, t, f[1 << 20], tr[1 << 20];
bool bit(int x, int u){
    return (u >> x) & 1;
}
vector <int> a[20];
vector <pair> res[1 << 20];
void process(){
    a[1] = {2,3,4,5,6,7};    a[9] = {2,8,10};     a[17] = {6,16,18};
    a[2] = {1,3,7,8,9,10};   a[10] = {2,3,9,11};  a[18] = {6,7,17,19};
    a[3] = {1,2,4,10,11,12}; a[11] = {3,10,12};   a[19] = {7,8,18};
    a[4] = {1,3,5,12,13,14}; a[12] = {3,4,11,13};
    a[5] = {1,4,6,14,15,16}; a[13] = {12,4,14};
    a[6] = {1,5,7,16,17,18}; a[14] = {4,5,13,15};
    a[7] = {1,2,6,8,18,19};  a[15] = {5,14,16};
    a[8] = {2,7,9,19};       a[16] = {5,6,15,17};
}
void bfs(int x){
    queue<int> q;
    q.push(x);
    while(q.size()){
        int u = q.front(); q.pop();
        FOR(i, 0, 18) if(bit(i, u))
            for(auto j : a[i+1]) if(!bit(j-1, u)){
                int v = u - (1 << i) + (1 << (j-1));
                if(!f[v])
                {
                    f[v] = f[u] + 1;
                    copy(res[u].begin(), res[u].end(), back_inserter(res[v]));
                    res[v].push_back({i+1, j});
                    q.push(v);
                }
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("city.inp");
    //ofstream cout("city.out");
    cin >> T;
    process();
    while(T--){
        cin >> n;
        int x;
        s = 0, t = 0;
        memset(f, 0, sizeof f);
        FOR(i, 1, n) cin >> x, s += (1 << (x-1));
        FOR(i, 1, n) cin >> x, t += (1 << (x-1));
        bfs(s);
        cout << f[t] << '\n';
        for(auto x : res[t]) cout << x.first << " " << x.second << '\n';
    }

}
