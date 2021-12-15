#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn
using namespace std;
int n, k, pos[21];
long long pw[13];
long long x, y;
vector <long long> res, q, q2;
long long Find(long long x){
    FOR(i, 1, 12) if(x == pw[i]) return x;
    long long tmp = 0;
    while(x){
        x /= 10;
        tmp++;
    }
    return pw[tmp];
}
long long Rotate(long long tmp){
    int i = 1;
    long long x = 0;
    while(tmp >= 10){
        x += pw[i] * (tmp % 10);
        tmp /= 10;
        i++;
    }
    x += tmp;
    return x;
}
void Try(){
    n = 20;
    FOR(u, 0, (1 << n) - 1){
        q.clear();
        long long tmp = x;
        q.push_back(tmp);
        FOR(i, 0, n-1)
            if(((u >> i) & 1) == 1){
                tmp = Rotate(tmp);
                q.push_back(tmp);
                if(tmp == y){
                cout << q.size()-1 << '\n';
                for(auto v : q) cout << v << '\n';
                exit(0);
                }
            }
            else{
                tmp++;
                q.push_back(tmp);
                if(tmp == y){
                cout << q.size()-1 << '\n';
                for(auto v : q) cout << v << '\n';
                exit(0);
                }

            }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("cxy.inp");
    //ofstream cout("cxy.out");
    cin >> k >> x >> y;
    pw[0] = 1;
    FOR(i, 1, 12) pw[i] = pw[i-1] * 10;
    if(y - x >= 0 && y - x <= 1000000){
        cout << y - x << '\n';
        for(long long i = x; i <= y; i++) cout << i << '\n';
    }
    else{
        if(k <= 6 && x - y > 0){
            FOR(i, x, Find(x)) res.push_back(i);
            res.push_back(1);
            FOR(i, 2, y) res.push_back(i);
            cout << res.size()-1 << '\n';
            for(auto v : res) cout << v << '\n';
            return 0;
        }
        if(k > 6) Try();
    }
}
