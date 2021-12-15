//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn
using namespace std;

long long cost(int l, int r){
    r--;
    return sumd[r] * (sumw[r] - sumw[l-1]) - k[r] + k[l-1];
}
void Mul(const TMatrix& x, const TMatrix& y, TMatrix& res){
    FOR(step, 0, n-1)
        FOR(i, 1, n+n-step-1){
            int j = i + step;
            res[i][j] = x[i][j];
            trace[i][j] = j;
            if(i == j) continue;
            int k = trace[i][j - 1];
            int endk = min(trace[i + 1][j] + 1, j);
            for (; k <= endk; ++k)
                if (Minimize(res[i][j], x[i][k] + y[k + 1][j]))
                    trace[i][j] = k;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("csp.inp");
    //ofstream cout("csp.out");
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i], a[i+n] = a[i];
    FOR(i, 1, n+n) sumd[i] = sumd[i-1] + 1;
    FOR(i, 1, n+n) sumw[i] = sumw[i-1] + w[i];
    FOR(i, 1, n+n) k[i] = k[i-1] + 1ll * w[i] * sumd[i-1];
    FOR(i, 1, n+n)
        FOR(j, 1, min(i+n, n+n)) A[i][j] = B[i][j] = cost(i, j);

}
