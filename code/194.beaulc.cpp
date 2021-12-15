//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 50005
using namespace std;
int k, n, d[maxn];
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("beaulc.inp");
    //ofstream cout("beaulc.out");
    cin >> k >> n;
    while(k--){
        memset(d, 0, sizeof d);
        cin >> s;
        s = ' ' + s;
        for(int i = 1; s[i]; i++){
            if(s[i] == '(') d[i] = d[i-1] + 1;
            else d[i] = d[i-1] - 1;
        }
        FOR(i, 1, n) cout << d[i] << " ";
        cout << '\n';
    }

}
