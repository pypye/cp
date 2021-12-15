#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005

using namespace std;
int n, m, cnt, ver[maxn];
struct data{
    int op, cl, l, r;
}fen[16*maxn];
string str;
void modify(int id){
    int low = fen[id].l, high = fen[id].r;
    fen[id].op = max(fen[low].op - fen[high].cl, 0) + fen[high].op;
    fen[id].cl = max(fen[high].cl - fen[low].op, 0) + fen[low].cl;
}
void init(int l = 1, int r = m, int id = 1){
    if(l == r){
        if(str[l] == ')') fen[id] = {0, 1, 0, 0};
        else fen[id] = {1, 0, 0, 0};
        return;
    }
    int mid = (l + r) >> 1;
    init(l, mid, id*2);
    init(mid+1, r, id*2+1);
    fen[id].l = id*2, fen[id].r = id*2+1;
    modify(id);
}
int update(int u, int id, int l = 1, int r = m){
    if(l == r){
        ++cnt;
        fen[cnt] = {fen[id].op^1, fen[id].cl^1, fen[id].l, fen[id].r};
        return cnt;
    }
    int mid = (l + r) >> 1;
    int cur = ++cnt;
    if(u <= mid){
        fen[cur].l = update(u, fen[id].l, l, mid);
        fen[cur].r = fen[id].r;
        modify(cur);
    }
    else{
        fen[cur].l = fen[id].l;
        fen[cur].r = update(u, fen[id].r, mid+1, r);
        modify(cur);
    }
    return cur;
}
#define M INT_MAX
data get(int u, int v, int id, int l = 1, int r = m){
    if(l > v || r < u) return {0, 0, M, M};
    if(l >= u && r <= v) return fen[id];
    int mid = (l + r) >> 1;
    data low = get(u, v, fen[id].l, l, mid);
    data high = get(u, v, fen[id].r, mid+1, r);
    return {max(low.op - high.cl, 0) + high.op, max(high.cl - low.op, 0) + low.cl, M, M};
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("fixstr.inp");
//    ofstream cout("fixstr.out");
    cin >> str;
    m = str.size();
    str = ' ' + str;
    cin >> n;
    init();
    ver[0] = 1;
    cnt = 4*m;
    FOR(i, 1, n){
        char ty; cin >> ty;
        if(ty == 'C'){
            int x; cin >> x;
            ver[i] = update(x, ver[i-1]);
        }
        if(ty == 'U'){
            int x; cin >> x;
            ver[i] = ver[x-1];
        }
        if(ty == 'Q'){
            ver[i] = ver[i-1];
            int l, r; cin >> l >> r;
            cout << get(l, r, ver[i]).op + get(l, r, ver[i]).cl << '\n';
        }
    }
}
