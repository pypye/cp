#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORR(i, a, b) for(int i = (a); i >= (b); --i)
#define maxn 10005
using namespace std;
long long a, b;
vector <string> ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    ifstream cin("plus.inp");
//    ofstream cout("plus.out");
    cin >> a >> b;
    while(a != b){
        long long d = __gcd(a, b);
        a /= d, b /= d;
        if((a & 1) && (b & 1)){
            if(a < b){
                ans.push_back("B+=A");
                ans.push_back("A+=A");
                b += a; a += a;
            }
            else{
                ans.push_back("A+=B");
                ans.push_back("B+=B");
                a += b; b += b;
            }
        }
        else{
            if(a & 1) a += a, ans.push_back("A+=A");
            if(b & 1) b += b, ans.push_back("B+=B");
        }
    }
    cout << ans.size() << '\n';
    for(auto v : ans) cout << v << "\n";
}
