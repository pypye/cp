//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn
using namespace std;
int n, ans = 0;
string s;
int cdigit(int x){
    int ans = 0;
    while(x) ans++, x /= 10;
    return ans;
}
bool check(int x){
    vector <int> a;
    while(x) a.push_back(x%10), x/= 10;
    if(a.size()) FOR(i, 0, a.size()-2) if(a[i] == a[i+1]) return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("aplusb.inp");
    ofstream cout("aplusb.out");
    cin >> s;
    if(s[0] == '1') return cout << 0, 0;
    n = stoi(s);
    FOR(i, 1, n){
        if(cdigit(i) == cdigit(n-i) && cdigit(i) == cdigit(n) && check(i) && check(n-i)) ans++;
    }
    cout << ans;
}
