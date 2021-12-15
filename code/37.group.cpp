#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 100005
using namespace std;
long long n, a[maxn], s[maxn], p, res, fen[maxn];
vector <long long> b;
void compress()
{
    FOR(i, 1, n) b.push_back(s[i]);
    b.push_back(0);
    sort(b.begin(), b.end());
    FOR(i, 1, n) s[i] = lower_bound(b.begin(), b.end(), s[i]) - b.begin() + 1;
}
void update(int x)
{
    for(; x <= n+1; x += x & (-x))
        fen[x]++;
}
int get(int x)
{
    long long ans = 0;
    for(; x; x -= x & (-x))
        ans += fen[x];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("group.inp");
    //ofstream cout("group.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> p;
    FOR(i, 1, n) a[i] -= p, s[i] = s[i-1] + a[i];
    compress();
    update(lower_bound(b.begin(), b.end(), 0) - b.begin() + 1);
    FOR(i, 1, n)
    {
        res += get(s[i]);
        update(s[i]);
    }
    cout << res;
}
