#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn
using namespace std;
int n, m, a[31][31], k;
void Polyomino(){

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("key.inp");
    //ofstream cout("key.out");
    cin >> n >> m >> k;
    Polyomino();
    FOR(i, 1, n)
        FOR(j, 1, m){
            char x; cin >> x;
            if(x == '#') a[i][j] = 1;
        }
}
