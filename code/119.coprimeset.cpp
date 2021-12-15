#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005
using namespace std;
int q, n, a[55], d[55], ans, c[55];
vector<int> p, s;
void init(){
    d[1] = 1;
    FOR(i, 2, 50){
        bool check = 1;
        FOR(x, 2, sqrt(i))
            if(i % x == 0){
                check = 0;
                break;
            }
        d[i] = check;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("coprimeset.inp");
    //ofstream cout("coprimeset.out");
    cin >> q;
    init();
    while(q--){
        p.clear();
        s.clear();
        ans = 0;
        cin >> n;
        FOR(i, 1, n){
            cin >> a[i];
            if(a[i] == 1) ans++;
        }
        sort(a+1, a+n+1);
        n = unique(a+1, a+n+1) - a - 1;
        FOR(i, 1, n) if(a[i] != 1){
            if(d[a[i]]) s.push_back(a[i]), ans++, c[i]++;
            else p.push_back(a[i]);
        }
        for(auto u : p){
            bool check = 1;
            FOR(i, 2, 50) if(u % i == 0 && d[i]){
                if(c[i]) check = 0;
            }
            if(check){
                FOR(i, 2, 50) if(u % i == 0 && d[i]){
                c[i] = 1;
                }
                ans++;
            }
        }
        cout << ans << '\n';
    }
}
