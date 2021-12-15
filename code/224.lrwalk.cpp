//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
int n, M, a[maxn];
long double pend[maxn], b[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("lrwalk.inp");
    ofstream cout("lrwalk.out");
    cin >> M >> n;
    FOR(i, 1, n){
        char trash;
        cin >> a[i] >> trash;
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i += 2) a[i] = 2 * M - a[i];
    sort(a+1, a+n+1);
    FOR(i, 1, n) pend[i] = (2 * M / (1.0*n)) * (i-1);
    FOR(i, 1, n) b[i] = pend[i] - a[i];
    double low = *min_element(b+1, b+n+1);
    double high = *max_element(b+1, b+n+1);
    cout << fixed << setprecision(6) << (high - low) / 2.0;
}
