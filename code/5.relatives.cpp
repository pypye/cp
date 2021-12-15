//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 500005
using namespace std;
int n, a[maxn], d[10], cnt[1 << 11];
long long res;
void Push(int x){
    memset(d, 0, sizeof d);
    int ans = 0;
    if(x == 0) d[x]++;
    while(x){
        d[x % 10] = 1;
        x /= 10;
    }
    FOR(i, 0, 9) if(d[i]) ans += (1 << i);
    cnt[ans]++;
}
long long ckn(int n) {
    return 1ll * n * (n-1) / 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("relatives.inp");
    ofstream cout("relatives.out");
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        Push(a[i]);
    }
    FOR(i, 0, (1 << 10)-1)
        if(cnt[i])
            FOR(j, i+1, (1 << 10)-1)
                if(cnt[j] && (i & j))
                    res += 1ll * cnt[i] * cnt[j];
    FOR(i, 0, (1 << 10)-1)
        if(cnt[i])
            res += ckn(cnt[i]);
    cout << res;
}
