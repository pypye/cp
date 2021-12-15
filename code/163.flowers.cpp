#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005
using namespace std;
long long n, m, t, mod, dd[maxn], p[maxn], cnt[maxn];
long long g[maxn], rev[maxn];
long long power(long long n, long long k){
    long long c = 1;
    for(; k; k /= 2, n = (n * n) % mod)
        if(k & 1) c = (c * n) % mod;
    return c;
}
void prepare(){
    g[0] = 1;
    int n = 1000000;
    FOR(i, 1, n) g[i] = (g[i-1] * i) % mod;
    rev[n] = power(g[n], mod - 2);
    FORR(i, n-1, 0) rev[i] = (rev[i+1] * (i+1)) % mod;
}

long long ckn(int n, int k){
    return ((((g[n] * rev[k]) % mod) * rev[n-k]) % mod);
}
long long calc(int n, int k){
    long long ans = 1;
    FOR(i, 0, k-1) ans = (ans * (n-i)) % mod;
    return (ans * rev[k]) % mod;
}
void calc2(int n, int val){
    FOR(i, 2, n){
        int x = i;
        while(x != 1){
            int prime = dd[x];
            while(x % prime == 0) cnt[prime] += val, x /= prime;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("flowers.inp");
    ofstream cout("flowers.out");
    cin >> t >> mod;
    if(t > 50){
        prepare();
        while(t--){
            int n, m, k;
            cin >> n >> m >> k;
            if(k == 0){
                cout << m % mod << '\n';
                continue;
            }
            cout << (((power(m-1, k) * m) % mod) * ckn(n-1, k)) % mod << '\n';
        }
    }
    else{
        if(mod == 998244353){
            prepare();
            while(t--){
                int n, m, k;
                cin >> n >> m >> k;
                if(k == 0){
                    cout << m % mod << '\n';
                    continue;
                }
                cout << (((power(m-1, k) * m) % mod) * calc(n-1, k)) % mod << '\n';
            }

        }
        else{
            int dem = 0;
            FOR(i, 2, 1000000)
                for(int j = i; j <= 1000000; j += i) if(!dd[j]) dd[j] = i;
            FOR(i, 2, 1000000)
                if(dd[i] == i) p[++dem] = i;
            while(t--){
                int n, m, k;
                cin >> n >> m >> k;
                if(k == 0){
                    cout << m % mod << '\n';
                    continue;
                }
                FOR(i, 2, 1000000) cnt[i] = 0;
                calc2(n-1, 1);
                calc2(k, -1);
                calc2(n-k-1,-1);
                long long res = (power(m-1, k) * m) % mod;
                FOR(i, 1, dem)
                    res = (res *  power(p[i], cnt[p[i]])) % mod;
                cout << res << '\n';
            }

        }
    }

}
