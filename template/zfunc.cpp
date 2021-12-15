#include <bits/stdc++.h>
#define FOR(i, x, y) for (int i = x; i <= y; ++i)
#define FORR(i, x, y) for (int i = x; i >= y; --i)
#define maxn
#define maxm
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define reset(x) memset(x, 0, sizeof(x));
using namespace std;
string s;
int z[10007];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    z[0] = 0;
    int n = s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    FOR(i, 0, n - 1)
    cout << z[i] << " ";
}
