#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn
using namespace std;
int n, l, r, bn[32], bl[32], br[32];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("bits.inp");
    ofstream cout("bits.out");
    while(cin >> n >> l >> r){
            bool Min = 0, Max = 0;
            int ans = 0;
        FORR(i, 31, 0) {
            bn[i] = ((n >> i) & 1);
            bl[i] = ((l >> i) & 1);
            br[i] = ((r >> i) & 1);
        }
        FORR(i, 31, 0)
            if(bn[i]){
                if(!Max && bl[i]) ans += (1 << i);
                else if(br[i]) Min = 1;
            }
            else{
                if(Min || br[i]){
                    ans += (1 << i);
                    if(!bl[i]) Max = 1;
                }
            }
        cout << ans << '\n';
    }

}
