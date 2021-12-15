//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define F first
#define S second
#define maxn 100005
using namespace std;
int n, p[maxn], ans, ans2;
pair q[maxn];
vector <int> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("emergency.inp");
    ofstream cout("emergency.out");
    cin >> n;
    FOR(i, 1, n){
        int x; cin >> x;
        if(!x) a.push_back(i);
    }
    a.push_back(1e9);
    FOR(i, 1, n){
        if(i <= a[0]){
            p[i] = a[0];
            continue;
        }
        int l = a[upper_bound(a.begin(), a.end(), i) - a.begin() - 1];
        int r = *upper_bound(a.begin(), a.end(), i);
        if(r - i > i - l) p[i] = l;
        if(r - i < i - l) p[i] = r;
        if(r - i == i - l) q[i] = {l, r};

    }
    FOR(i, 1, n) if(p[i] == 0){
        if(q[i].F != p[q[i].F * 2 - i]){
            p[i] = q[i].F;
            continue;
        }
        if(q[i].S != p[q[i].S * 2 - i]){
            p[i] = q[i].S;
            continue;
        }
        p[i] = q[i].F;

    }
    FOR(i, 1, n){
        if(p[i] < i && 2 * p[i] - i > 0  && p[i] == p[2 * p[i] - i]) ans++;
    }
    cout << ans << '\n';
    FOR(i, 1, n) cout << p[i] << " ";
}
