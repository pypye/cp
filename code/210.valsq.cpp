#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 5005
using namespace std;
int n, m, k;
pair <int, int> q[10005];
int a[maxn][maxn], f[maxn][maxn], g[maxn][maxn];
long long ans;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
int main()
{
    freopen("valsq.inp", "r", stdin);
    freopen("valsq.out", "w", stdout);
    read(n); read(m); read(k);
    FOR(i, 1, n)
        FOR(j, 1, m) read(a[i][j]);
    FOR(i, 1, n){
        int top = 5000, bot = 5001;
        FOR(j, 1, m){
            while(top >= bot && q[bot].F < a[i][j]) ++bot;
            while(top >= bot && q[top].S <= j-k) --top;
            if(j < k) q[--bot] = {a[i][j], j};
            else{
                q[--bot] = {a[i][j], j};
                f[i][j] = q[top].F;
            }
        }
    }
    FOR(j, 1, m){
        int top = 5000, bot = 5001;
        FOR(i, 1, n){
            while(top >= bot && q[bot].F < f[i][j]) ++bot;
            while(top >= bot && q[top].S <= i-k) --top;
            if(i < k) q[--bot] = {f[i][j], i};
            else{
                q[--bot] = {f[i][j], i};
                g[i][j] = q[top].F;

            }
        }
    }
    FOR(i, 1, n)
        FOR(j, 1, m) ans += 1ll * g[i][j];
    write(ans);
}
