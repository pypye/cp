#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 10005
using namespace std;
int b, d[maxn], n, solved;
string s;
vector <int> q;
int solve(int k){
    FOR(x, 1, b-1){
        int mr = 0, last = x;
        FORR(i, n, k){
            if(last - mr < d[i]) last = last - mr + b - d[i], mr = 1;
            else last = last - mr - d[i], mr = 0;
        }
        if(last == x) return x;
    }
    return 0;
}
void put(int k, int check){
    int mr = 0, last = check;
    FORR(i, n, k){
        if(last - mr < d[i]) last = last - mr + b - d[i], mr = 1;
        else last = last - mr - d[i], mr = 0;
        q.push_back(last);
    }
    reverse(q.begin(), q.end());
    if(q[0] > q[1]) cout << 0 << '\n';
    else{
        for(auto v : q)
            if(v < 10) cout << v;
            else cout << char(v - 10 + 'A');
        cout << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("rotation.inp");
    //ofstream cout("rotation.out");
    cin >> b;
    FOR(temp, 1, 4){
        memset(d, 0, sizeof d);
        q.clear();
        cin >> s;
        n = s.size(), solved = 0;
        FOR(i, 0, n-1) d[i+1] = (isdigit(s[i]) ? (s[i] - '0') : (s[i] - 'A' + 10));
        FORR(i, 1, 0)
        if(solve(i)) {
            put(i, solve(i));
            solved = 1;
            break;
        }
        if(!solved) cout << 0 << '\n';
    }
}
