//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
int q[maxn], top, p[3], last;
vector <int> ans;
int calc(int x){
    int ans = 1;
    while(x){
        ans *= x % 10;
        x /= 10;
    }
    return ans;
}
int to(char x, char y){
    string str = "";
    str += x;
    str += y;
    return stoi(str);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("digit.inp");
    ofstream cout("digit.out");
    string l, r;
    cin >> l >> r;
    l = string(r.size() - l.size(), '0').append(l);
    int n = l.size();
    FOR(i, 0, n-1) if(l[i] < r[i]) q[++top] = i;
    int bot = 1, check = 0;
    if(bot > top) return cout << l, 0;
    if(n == 1) return cout << r, 0;
    FORR(i, n-1, 0){
        if(i-1 == q[bot]){
            last = i-2;
            int ll = to(l[i-1], l[i]);
            int rr = to(r[i-1], r[i]);
            int res = 0, x, dem = 0;
            if(check) rr--;
            FOR(i, ll, rr) if(res < calc(i)){
                res = calc(i);
                x = i;
            }
            while(x){
                p[++dem] = x % 10;
                x /= 10;
            }
            if(dem == 1) p[++dem] = 0;
            FOR(k, 1, dem) ans.push_back(p[k]);
            break;
        }
        else{
            if(i == q[top]) top--;
            if(r[i] - '0' < 9) check = 1;
            ans.push_back(9);
        }
    }
    FORR(i, last, 0)
        ans.push_back(l[i] - '0');
    while(ans[ans.size()-1] == 0) ans.pop_back();
    reverse(ans.begin(), ans.end());
    for(auto v : ans) cout << v;
}
