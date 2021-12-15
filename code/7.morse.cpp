//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
string mr[26] = { ".-"   , "-..." ,"-.-."  , "-.."
                , "."    , "..-." , "--."  , "...."
                , ".."   , ".---" , "-.-"  , ".-.."
                , "--"   , "-."   , "---"  , ".--."
                , "--.-" , ".-."  , "..."  , "-"
                , "..-"  , "...-" , ".--"  , "-..-"
                , "-.--" , "--.." };
string s, t[maxn];
int q, n, Next[maxn][2], cnt, link[maxn], out[maxn], dp[maxn];
void reset(){
    memset(dp, 0, sizeof dp);
    memset(Next, 0, sizeof Next);
    memset(out, 0, sizeof out);
    memset(link, 0, sizeof link);
}
int to(char s){
    return (s == '.' ? 0 : 1);
}
void Add(string s, int i){
    int u = 0;
    for(int i = 0; s[i]; i++){
        int v = to(s[i]);
        if(!Next[u][v]) Next[u][v] = ++cnt;
        u = Next[u][v];
    }
    out[u]++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("morse.inp");
    ofstream cout("morse.out");
    cin >> q;
    while(q--){
        reset();
        cin >> s;
        cin >> n;
        FOR(i, 1, n){
            cin >> t[i];
            string str;
            for(int j = 0; t[i][j]; j++) str += mr[t[i][j] - 'A'];
            Add(str, i);
        }
        dp[s.size()] = 1;
        FORR(i, s.size(), 0){
            int u = 0;
            FOR(j, i, s.size()-1)
            {
                int v = to(s[j]);
                if(Next[u][v] == 0) break;
                u = Next[u][v];
                if(out[u] >= 1) dp[i] += dp[j+1] * out[u];

            }
        }
        cout << dp[0] << '\n';
    }
}
