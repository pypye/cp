#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn
using namespace std;
string s, t;
bool check(int i){
    FOR(x, 0, t.size()-1)
        if(s[x + i] != t[x]) return 0;
      return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("removest.inp");
    ofstream cout("removest.out");
    cin >> s >> t;
    s = '@' + s;
    FORR(i, s.size()-1, 0){
        if(s == "@") return cout << "FRULA", 0;
        if(check(i)) s.erase(i, t.size());
    }
    s.erase(0, 1);
    cout << s;
}
