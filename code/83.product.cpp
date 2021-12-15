//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 300005

using namespace std;
int n, a[maxn], l, r;
long long ans = -1e18;
struct data{
    int st, c2, c1;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("product.inp", "r", stdin);
    freopen("product.out", "w", stdout);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    if(n <= 60){
        FOR(i, 1, n)
            FOR(j, i, n){
                long long cur = 1;
                FOR(k, i, j) cur *= a[k];
                if(ans < cur){
                    ans = cur;
                    l = i, r = j;
                }
            }
        cout  << l << " " << r;
    }
    else{
        data res = {0, (int)-1e9, (int)-1e9};
        FOR(i, 1, n){
            data cur = {2, 0, 0};
            FOR(j, i, n){
                if(abs(a[i]) == 2) cur.c2++;
                if(abs(a[i]) == 1) cur.c1++;
                if(a[i] < 0) cur.st = 2 - cur.st;
                if(a[i] == 0) cur.st = 1;

                if(res.st < cur.st) res = cur, l = i, r = j;
                else if(res.st == cur.st){
                    if(res.c2 < cur.c2) res = cur, l = i, r = j;
                }
                else if(res.c2 == cur.c2){
                    if(res.c1 < cur.c1) res = cur, l = i, r = j;
                }
                if(cur.st == 1) break;
            }
        }
        cout << l << " " << r;
    }
}
