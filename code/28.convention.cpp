//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define F first
#define S second
#define maxn 200005

using namespace std;

int n, f[maxn];
vector <int> fen[8*maxn], FF, vect;
pair q[maxn];

struct data{
    int F, S, id;
}a[maxn];

#define all(s) s.begin(), s.end()

void compress(){
    vector <int> s;
    FOR(i, 1, n) s.push_back(a[i].F), s.push_back(a[i].S);
    sort(all(s));
    FOR(i, 1, n){
        a[i].F = lower_bound(all(s), a[i].F) - s.begin() + 1;
        a[i].S = lower_bound(all(s), a[i].S) - s.begin() + 1;
    }
}
void update(int x, vector <int> val, int w, int l = 1, int r = 2*n, int id = 1){
    if(l > x || r < x) return;
    if(l == r){
        fen[id] = val;
        fen[id].push_back(w);
        sort(all(fen[id]));
        return;
    }
    int mid = (l + r) >> 1;
    if(mid >= x) update(x, val, w, l, mid, id*2);
    else update(x, val, w, mid+1, r, id*2+1);
    fen[id] = Max(fen[id*2], fen[id*2+1]);
}

vector <int> get(int u, int v, int l = 1, int r = 2*n, int id = 1){
    if(l > v || r < u) return FF;
    if(l >= u && r <= v) return fen[id];
    int mid = (l + r) >> 1;
    return Max(get(u, v, l, mid, id*2), get(u, v, mid+1, r, id*2+1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("convention.inp");
    //ofstream cout("convention.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S, a[i].id = i;
    compress();
    sort(a+1, a+n+1, [](data i, data j){return i.F < j.F;});
    int ans = 0;
    FOR(i, 1, n){
        vector <int> h = get(1, a[i].F-1);
        f[i] = h.size() + 1;
        vector <int> vect2 = h;
        vect2.push_back(a[i].id);
        sort(all(vect2));
        if(ans < f[i]){
            ans = f[i];
            vect = h;
            vect.push_back(a[i].id);
            sort(all(vect));
        }
        else if(ans == f[i] && vect > vect2) vect = vect2;
        update(a[i].S, h, a[i].id);
    }
    cout << ans << '\n';
    for(auto v : vect) cout << v << " ";
}
