#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 300005
using namespace std;
int n, k, a[maxn], b[maxn], c[maxn];
priority_queue <int> q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("compseq.inp");
    ofstream cout("compseq.out");
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    FOR(i, 1, n) if(a[i] != b[i]) c[i] = 1, q.push(-i);
    while(k--){
        int u, v;
        cin >> u >> v;
        a[u] = v;
        if(a[u] == b[u]) c[u] = 0;
        else c[u] = 1, q.push(-u);
        if(!q.size()) cout << "N\n";
        else{


            while(q.size() && !c[-q.top()]) q.pop();
            cout << (a[-q.top()] > b[-q.top()] ? "Y\n" : "N\n");
        }
    }
}
