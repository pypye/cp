#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 3005
using namespace std;
int n, T, x[maxn];
bitset <maxn> M[maxn];
vector <int> a[maxn];
void reset(){
    FOR(u, 1, n) M[u].reset();
    FOR(u, 1, n){
        M[u][u] = 1;
        for(auto v : a[u]) M[u][v] = 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("lamps2.inp");
    //ofstream cout("lamps2.out");
    cin >> n >> T;
    FOR(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    while(T--){
        reset();
        FOR(i, 1, n){
            int x; cin >> x;
            M[i][n+1] = 1 - x;
        }
        FOR(i, 1, n){
            if(!M[i][i]) FOR(j, i+1, n){
                if(M[j][i]){
                    swap(M[j], M[i]);
                    break;
                }
            }
            if(M[i][i]) FOR(j, i+1, n) if(M[j][i]) M[j] ^= M[i];
        }
        x[n] = M[n][n+1] / M[n][n];
        FORR(i, n-1, 1)
        {
            x[i] = M[i][n+1];
            FOR(j, i+1, n) x[i] -= M[i][j] * x[j];
            x[i] /= M[i][i];
        }
        FOR(i, 1, n) cout << x[i] << " ";
    }
}
