#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 40005
using namespace std;
int n, k;
long long a[maxn], t1[4*maxn], t2[4*maxn], t3[4*maxn], t4[4*maxn], ans;
void init(int l, int r, int id){
    if(l == r){
        t1[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(l, mid, id*2);
    init(mid+1, r, id*2+1);
    t1[id] = max(max(t2[id*2], t1[id*2]) + t3[id*2+1], t2[id*2] + max(t1[id*2+1], t3[id*2+1]));
    t2[id] = max(t1[id*2] + t4[id*2+1], t2[id*2] + max(t2[id*2+1], t4[id*2+1]));
    t3[id] = max(max(t3[id*2], t4[id*2]) + t3[id*2+1], t4[id*2] + t1[id*2+1]);
    t4[id] = max(t3[id*2] + t4[id*2+1], t4[id*2] + max(t2[id*2+1], t4[id*2+1]));
}
void update(int l, int r, int id, int x, int y){
    if (l == r)
    {
        t1[id] = y;
        return;
    }
    int mid = (l + r) / 2;
    if(x <= mid) update(l, mid, id*2, x, y);
    else update(mid+1, r, id*2+1, x, y);
    t1[id] = max(max(t2[id*2], t1[id*2]) + t3[id*2+1], t2[id*2] + max(t1[id*2+1], t3[id*2+1]));
    t2[id] = max(t1[id*2] + t4[id*2+1], t2[id*2] + max(t2[id*2+1], t4[id*2+1]));
    t3[id] = max(max(t3[id*2], t4[id*2]) + t3[id*2+1], t4[id*2] + t1[id*2+1]);
    t4[id] = max(t3[id*2] + t4[id*2+1], t4[id*2] + max(t2[id*2+1], t4[id*2+1]));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("money.inp");
    //ofstream cout("money.out");
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    init(1, n, 1);
    FOR(i, 1, k){
        int x, y;
        cin >> x >> y;
        update(1, n, 1, x, y);
        ans += max(max(t1[1], t2[1]), max(t3[1], t4[1]));
    }
    cout << ans;

}
