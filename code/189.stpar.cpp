#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 10005
using namespace std;
int n, a[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //ifstream cin("stpar.inp");
    //ofstream cout("stpar.out");
    while(cin >> n){
        stack <int> s;
        if(!n) return 0;
        FOR(i, 1, n) cin >> a[i];
        int temp = 1, x = 1;
        while(temp <= n && x <= n){
            while(s.size() && s.top() == temp){
                s.pop();
                temp++;
            }
            while(a[x] != temp && x <= n){
                s.push(a[x]);
                x++;
            }
            if(x <= n) temp++, x++;
        }
        while(s.size() && s.top() == temp){
            s.pop();
            temp++;
        }
        if(temp <= n) cout << "no\n";
        else cout << "yes\n";
    }
}
