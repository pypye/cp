#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define maxn 200005
#define MOD 1016959
using namespace std;
const long long MM = 1ll * MOD * MOD;
const int Base = 51;
string s;
int n, dd[MOD*10], d[MOD*10], cur;
long long H[maxn], a[maxn], b[maxn];

long long get(long long x[], int u, int v){
    return (x[v] - x[u-1] * H[v-u+1] + MM) % MOD;
}
void Make_Hash(string st, int len, int id){
    int l = st.size();
    st = " " + st + st;
    b[0] = 0;
    FOR(i, 1, st.size()-1) b[i] = (b[i-1] * Base + st[i] - 'a' + 1) % MOD;
    FOR(i, 1, l){
        long long val = get(b, i, i + len - 1);
        dd[val] = id;
    }
}
bool check(int len){
    int l = 0, r = 0, ok = 0;
    long long val;
    FOR(i, 1, cur){
        l = r + 1;
        r = i * len;
        val = get(a, l, r);
        if(d[dd[val]] == cur) continue;
        if(dd[val] == cur) ok--, d[dd[val]] = cur;
        else{
            ok++;
            string tmp = s.substr(l, len);
            Make_Hash(tmp, len, cur);
        }
    }
    return (ok == 0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("STRkARY.inp", "r", stdin);
	freopen("STRkARY.out", "w", stdout);
    cin >> s;
    string str = s;
    bool cc = 1;
    vector <int> res;
    res.push_back(1);
    n = s.size();
    s = " " + s;
    H[0] = 1; a[0] = 0;
    FOR(i, 1, n){
        H[i] = (H[i-1] * Base) % MOD;
        a[i] = (a[i-1] * Base + s[i] - 'a' + 1) % MOD;
    }
    for(cur = 2; cur < n; ++cur)
        if(n % cur) continue;
        else if(check(n/cur)) res.push_back(cur);
    FOR(i, 1, str.size()-1) if(str[i] != str[i-1]) cc = 0;
    if(cc && str.size() != 1) res.push_back(str.size());
    cout << res.size() << "\n";
    for(int k : res) cout << k << " ";
}
