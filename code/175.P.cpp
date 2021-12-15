//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORR(i, a, b) for(int i = (a); i >= (b); --i)
#define F first
#define S second
#define maxn 100005
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
using namespace std;
int n, p[maxn], a[maxn], tab = 1, res, cnt2, q[maxn], seq[1230][maxn];
void build(){
    FOR(i, 2, 10000)
        if(!p[i]){
            q[cnt2++] = i;
            for(int x = i*i; x <= 10000; x += i) p[x] = 1;
        }
}
int power(int x, int k){
    if(k == 0) return 1;
    int b = power(x, k/2);
    b = (b * b);
    if(k & 1) b = (b * x);
    return b;
}
int main()
{
    freopen("P.inp", "r", stdin);
    freopen("P.out", "w", stdout);
    read(n);
    build();
    FOR(i, 0, n-1){
        read(a[i]);
        FOR(j, 0, cnt2-1){
            int cnt = 0;
            while(a[i] % q[j] == 0) a[i] /= q[j], cnt++;
            if(a[i] == 0) break;
            seq[j][i] = cnt;
        }
    }
    FOR(j, 0, cnt2-1){
        nth_element(seq[j], seq[j] + (n-1)/2, seq[j] + n);
        FOR(i, 0, n-1)
            res += abs(seq[j][i] - seq[j][(n-1)/2]);
        tab *= power(q[j], seq[j][(n-1)/2]);
    }
    write(res);
    write(tab);
}
