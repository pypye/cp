//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 1000005
using namespace std;
int n, d[maxn], q[maxn], lim[maxn], cnt, range;
long long res;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    ifstream cin("pmoney.inp");
//    ofstream cout("pmoney.out");
    cin >> s;
    n = s.size();
    FOR(i, 0, n-1){
        if(s[i] == '+' || s[i] == '_') cnt++;
        else if(s[i] == '-') cnt--;
        if(cnt < 0) return cout << "NIE", 0;
    }
    FORR(i, n-1, 0){
        q[i] = q[i+1];
        d[i] = d[i+1];
        if(s[i] == '+') q[i]++;
        else if(s[i] == '-') q[i]--;
        else if(s[i] == '_') d[i]++;
        if(q[i] > d[i]) return cout << "NIE", 0;
        range = max(range, q[i] + d[i]);
        lim[i] = range - (q[i] + d[i]);
    }
    cnt = 0;
    FOR(i, 0, n-1){
        if(s[i] == '+') cnt++;
        else if(s[i] == '-') cnt--;
        else if(s[i] == '_'){
            if(cnt > lim[i+1]) cnt--;
            else if(cnt < lim[i+1]) cnt++;
        }
        res += cnt;
    }
    cout << res << ' ';
    res = 0, cnt = 0;
    FOR(i, 0, n-1){
        if(s[i] == '+') cnt++;
        else if(s[i] == '-') cnt--;
        else if(s[i] == '_'){
            if(cnt + q[i+1] > d[i+1]) cnt--;
            else if(cnt + q[i+1] < d[i+1]) cnt++;
        }
        res += cnt;
    }
    cout << res << '\n';
}
