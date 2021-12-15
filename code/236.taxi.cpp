#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORR(i, a, b) for(int i = (a); i >= (b); --i)
#define maxn 10005
#define bit(x, i) ((x >> i) & 1)
using namespace std;
int n;
long long a[21][21], dp[(1 << 20) + 5][21], ans = 1e18;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
template <typename R, typename D> inline void Min(R &a, D b){if(a>b) a=b;}
template <typename D, typename R> inline void Max(D &a, R b){if(a<b) a=b;}
int main()
{
//    ifstream cin("taxi.inp");
//    ofstream cout("taxi.out");
    read(n);
    FOR(i, 0, n)
        FOR(j, 0, n) read(a[i][j]);
    memset(dp, 60, sizeof dp);
    FOR(i, 1, n/2) dp[1 << (i-1)][i] = a[0][i];
    FOR(x, 0, (1 << n)-1){
        bool check = 0;
        FOR(j, 0, n-1) if(j > n/2-1 && bit(x, j) && !bit(x, j-n/2)) {check = 1; break;}
        if(check) continue;
        FOR(i, 0, n)
            FOR(j, 0, n-1)
                if(!bit(x, j)){
                    dp[x + (1 << j)][j+1] = min(dp[x + (1 << j)][j+1], dp[x][i] + a[i][j+1]);
                }
    }
    FOR(i, 1, n) ans = min(ans, dp[(1 << n)-1][i] + a[i][0]);
    write(ans);
}
