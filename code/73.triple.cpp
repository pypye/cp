//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 3005
using namespace std;
int n;
long long a[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("triple.inp");
    ofstream cout("triple.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    n = unique(a+1, a+n+1) - a - 1;
    FOR(i, 1, n){
        int x = i+2;
        FOR(j, i+1, n){
            while(x <= n && 2ll*a[j] - a[i] > a[x]) x++;
            if(x <= n && 2ll*a[j] - a[i] == a[x]) return cout << "YES " << a[i] << " " << a[j] << " " << a[x], 0;
        }
    }
    cout << "NO";
}
