//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 1000005
using namespace std;
int n, last[maxn], a[maxn], tr[maxn], d[maxn], ans;
vector <int> q[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("minarrows.inp");
    ofstream cout("minarrows.out");
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        if(q[a[i]+1].size()) {tr[i] = q[a[i]+1].back(); q[a[i]+1].pop_back();}
        q[a[i]].push_back(i);
    }
    FORR(i, n, 1) if(!d[i]){
        int x = i;
        while(x){
            d[x] = 1;
            x = tr[x];
        }
        ans++;
    }
    cout << ans;
}
