#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
int n, a[maxn], f[maxn], sum[maxn];
double c[maxn], k;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
bool compare(double x, double y){
    return (fabs(x-y) <= 1e-5);
}
int main()
{
    freopen("homework.inp", "r", stdin);
    freopen("homework.out", "w", stdout);
    read(n);
    FOR(i, 1, n) read(a[i]), sum[i] = sum[i-1] + a[i];
    f[n+1] = 2e9;
    FORR(i, n, 1) f[i] = min(a[i], f[i+1]);
    FOR(i, 1, n-2){
        c[i] = 1.0 * (sum[n] - sum[i] - f[i+1]) / (1.0*(n-i-1));
        k = max(k, c[i]);
    }
    FOR(i, 1, n-2) if(compare(c[i], k)) writeln(i);
}
