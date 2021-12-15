#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
int z;
long long s, t, g[65][65], res;
void make_ckn(){
    FOR(i, 0, 64) g[i][0] = 1;
    g[1][1] = 1;
    FOR(i, 2, 64)
        FOR(j, 1, 64){
            g[i][j] = g[i-1][j-1] + g[i-1][j];
        }
}
bool get_bit(long long x, int u){
    return (x >> u) & 1;
}
long long calc(long long x){
    long long cur, ans = 0;
    FOR(i, 0, log2(x)-1){
        if(get_bit(x, i) == 1){
            cur = 1;
            FORR(j, log2(x)-1, i+1) if(get_bit(x, j) == 0) cur++;
            if(z >= cur) ans += g[i][z-cur];
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("zero.inp");
    //ofstream cout("zero.out");
    cin >> s >> t >> z;
    make_ckn();
    FOR(i, log2(s), log2(t)-1)
        if(i >= z) res += g[i][z];
    cout << res + calc(t) - calc(s);
    //cout << log2(t);
}
