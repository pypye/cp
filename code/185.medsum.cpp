//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 205
using namespace std;
int n, L, mod = 1000000000, ans;
vector <int> a[maxn];
int proc(int i, int j){
    int l = 0, r = L + 1;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(a[i][mid] >= a[j][L - mid + 1]) r = mid;
        else l = mid;
    }
    return max(a[i][l],a[j][L - l]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("medsum.inp");
    ofstream cout("medsum.out");
    cin >> n >> L;
    FOR(i, 1, n){
        a[i].push_back(-2e9);
        FOR(j, 1, L){
            int x;
            cin >> x, a[i].push_back(x);
        }
    }
    FOR(i, 1, n)
        FOR(j, i+1, n){
            ans = (ans + proc(i, j) + mod) % mod;
        }
    cout << ans;

}
