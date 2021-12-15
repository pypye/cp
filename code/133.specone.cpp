#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 10005
using namespace std;
int n, k, s, m, cnt, f[maxn], dd[maxn];
map <string, int> M;
priority_queue <pair> q;
vector <int> a[maxn],b[maxn];
vector <string> ans;
string save[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("specone.inp");
    ofstream cout("specone.out");
    cin >> n >> k >> s >> m;
    while(s--){
        string t;
        cin >> t;
        if(!M[t]) M[t] = ++cnt, save[cnt] = t;
        q.push({k, M[t]});
        f[M[t]] = k;
    }
    while(m--){
        string t1, t2;
        cin >> t1 >> t2;
        if(!M[t1]) M[t1] = ++cnt, save[cnt] = t1;
        if(!M[t2]) M[t2] = ++cnt, save[cnt] = t2;
        int u = M[t1], v = M[t2];
        b[u].push_back(v);
        b[v].push_back(u);
    }
    FOR(i,1,n)
    {
        set <int> s(b[i].begin(),b[i].end());
        copy(s.begin(),s.end(),back_inserter(a[i]));
    }
    while(q.size()){
        pair u = q.top(); q.pop();
        if(!dd[u.second] && u.first >= s){
            for(auto v : a[u.second]){
                f[v]++;
                q.push({f[v], v});
            }
            dd[u.second] = 1;
        }
    }
    FOR(i, 1, n)
        if(f[i] >= k) ans.push_back(save[i]);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    //for(auto v : ans) cout << v << " ";
}
