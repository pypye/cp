//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 200005
using namespace std;
int n, ans;
long long d, d2, l[maxn], r[maxn], len[maxn], a[maxn], fen[maxn], pos = 1e18;
map <long long, long long> M;
vector <long long> s;
#define all(s) s.begin(), s.end()
void compress(){
    FOR(i, 1, n) s.push_back(l[i]), s.push_back(r[i]);
    sort(all(s));
    s.resize(unique(all(s)) - s.begin());
    d2 = s.size();
    FOR(i, 1, n){
        long long x = l[i];
        l[i] = lower_bound(all(s), l[i]) - s.begin() + 1;
        r[i] = lower_bound(all(s), r[i]) - s.begin() + 1;
        M[l[i]] = x;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("festivals.inp");
//    ofstream cout("festivals.out");
    cin >> n >> d;
    FOR(i, 1, n){
        cin >> l[i] >> r[i];
        len[i] = r[i] - l[i] + 1;
        l[i] = (l[i] % d) + 1;
        r[i] = (r[i] % d) + 1;
    }
    compress();
    FOR(i, 1, n){
        if(len[i] >= d) fen[1]++, fen[d2+1]--;
        else{
            if(l[i] <= r[i]) fen[l[i]]++, fen[r[i]+1]--;
            else{
                fen[1]++; fen[r[i]+1]--;
                fen[l[i]]++; fen[d2+1]--;
            }
        }
    }
    FOR(i, 1, d2) a[i] = a[i-1] + fen[i];
    FOR(i, 1, d2){
        if(ans < a[i]){
            ans = a[i];
            pos = M[i]-1;
        }
    }
    if(pos == -1) pos = 0;
    cout << ans << " " << pos << '\n';
//    cout << M[1];

}
