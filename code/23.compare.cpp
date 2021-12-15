#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, q, k1, k2, check, res1, res2;
string s, t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("compare.inp");
    ofstream cout("compare.out");
    cin >> n >> q;
    cin >> s >> t;
    k1 = k2 = n;
    FOR(i, 0, n-1){
        if(s[i] < t[i]) res1++;
        if(s[i] > t[i]){k1 = i; break;}
    }
    FOR(i, 0, n-1){
        if(s[i] < t[i]) res2++;
        if(s[i] == '0' && t[i] == '0'){k2 = i; break;}
    }
    while(q--){
        int x;
        cin >> x; x--;
        if(s[x] == '0' && t[x] == '1'){
            if(x <= k1) res1--;
            if(x <= k2) res2--;
        }
        s[x] = '1';
        if(s[k2] == '1' && !res2 || !res1) check = 1;
        cout << ((check) ? "Y\n" : "N\n");

    }
}
