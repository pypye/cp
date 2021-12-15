#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 4005
using namespace std;
using Array = int[maxn][maxn];
int n, m, a[maxn], b[maxn];
Array Nexta, Nextb, f, tr;
string s;
void Add(int a[], int &x){
    cin >> s;
    x = s.size();
    for(int i = 0; s[i]; i++) a[i+1] = s[i] - '0';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("scns.inp", "r", stdin);
    Add(a, n);
    Add(b, m);
    FOR(i, 0, n+1){
        FOR(j, i+1, n){
            if(!Nexta[i][0] && a[j] == 0) Nexta[i][0] = j;
            if(!Nexta[i][1] && a[j] == 1) Nexta[i][1] = j;
        }
        if(!Nexta[i][0]) Nexta[i][0] = n+1;
        if(!Nexta[i][1]) Nexta[i][1] = n+1;
    }
    FOR(i, 0, m+1){
        FOR(j, i+1, m){
            if(!Nextb[i][0] && b[j] == 0) Nextb[i][0] = j;
            if(!Nextb[i][1] && b[j] == 1) Nextb[i][1] = j;
        }
        if(!Nextb[i][0]) Nextb[i][0] = m+1;
        if(!Nextb[i][1]) Nextb[i][1] = m+1;
    }
    FORR(i, n+1, 0)
        FORR(j, m+1, 0){
            if(i == n+1 && j == m+1) continue;
            f[i][j] = f[Nexta[i][0]][Nextb[j][0]];
            if(f[i][j] > f[Nexta[i][1]][Nextb[j][1]]){
                f[i][j] = f[Nexta[i][1]][Nextb[j][1]];
                tr[i][j] = 1;
            }
            f[i][j]++;
        }
    int u = 0, v = 0;
    do{
        cout << tr[u][v];
        int x = tr[u][v];
        u = Nexta[u][x];
        v = Nextb[v][x];
    }
    while(u < n+1 || v < m+1);
}
