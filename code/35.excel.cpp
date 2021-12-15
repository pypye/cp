//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define F first
#define S second
#define maxn
using namespace std;
int r, s, base[11];
long long a[105][105];
long long mod = (1ll << 31);
vector <pair> b[105][105];
pair convert(string t){
    vector <int> s;
    string newt = "";
    int ans = 0;
    for(int i = 0; t[i]; i++){
        if(t[i] < '0' || t[i] > '9') s.push_back(t[i] - 'A' + 1);
        else newt += t[i];
    }
    reverse(s.begin(), s.end());
    FOR(i, 0, s.size()-1) ans += s[i] * base[i];
    return {ans, stoi(newt)};
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("excel.inp");
    ofstream cout("excel.out");
    cin >> r >> s;
    FOR(i, 1, r)
        FOR(j, 1, s) a[i][j] = -1;
    base[0] = 1;
    FOR(i, 1, 10) base[i] =  base[i-1] * 26;
    FOR(i, 1, r)
        FOR(j, 1, s){
            string str;
            cin >> str;
            if(str[0] != '=') a[i][j] = stoi(str);
            else{
                string t = "";
                for(int x = 1; str[x]; x++){
                    if(str[x] != '+') t += str[x];
                    else b[i][j].push_back(convert(t)), t = "";
                }
                b[i][j].push_back(convert(t));
            }
        }
    FOR(temp, 1, 100){
        FOR(i, 1, r)
            FOR(j, 1, s){
                if(a[i][j] == -1){
                    bool check = 0;
                    long long cur = 0;
                    for(auto v : b[i][j]){
                        if(a[v.S][v.F] != -1) cur = (cur + a[v.S][v.F]) % mod;
                        else {check = 1;break;}
                    }
                    if(!check) a[i][j] = cur;
                }
            }
    }
    FOR(i, 1, r){
        FOR(j, 1, s) cout << a[i][j] << " ";
        cout << '\n';
    }
}
