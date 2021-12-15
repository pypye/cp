//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn
using namespace std;
int p, ans;
float S, x;
bool checkS(int a, int b, int c){
    return S == (long long)S;
}
bool checkR(int a, int b, int c){
    float R = (1.0*a)/(4.0*S)*b*c;
    return R == (long long)R;
}
bool checkr(int a, int b, int c){
    float r = S/x;
    return r == (long long)r;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("triangle.inp");
    ofstream cout("triangle.out");
    cin >> p;
    if(p % 2 == 1) return cout << 0, 0;
    FOR(i, p/4, p/2)
        FOR(j, (p-2*i)/2, (p-i)/2){
            int a = j, c = i, b = p - i - j;
            if(b > c) continue;
            x = p/2;
            S = sqrt(x*(x - a)*(x - b)*(x - c));
            if(!checkS(a, b, c)) continue;
            if(!checkR(a, b, c)) continue;
            if(!checkr(a, b, c)) continue;
            ans++;
        }
        cout << ans;
}
