#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005

using namespace std;
int n, cnt, r[maxn], ans[maxn],d[maxn];
char s[maxn];
struct data{
    int ty, x, y;
}qu[maxn];
int gr(int u){
    return r[u] ? r[u] = gr(r[u]) : u;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("paint.inp");
    ofstream cout("paint.out");
    cin >> n;
    if(n <= 1e4){
        while(n--){
            int type;
            cin >> type;
            if(type == 1){
                char x; cin >> x;
                s[++cnt] = x;
            }
            else{
                char x, y; cin >> x >> y;
                FOR(i, 1, cnt) if(s[i] == x) s[i] = y;
            }
        }
        FOR(i, 1, cnt) cout << s[i];
    }
    else{
        FOR(i, 1, n){
            int type;
            cin >> type;
            if(type == 1){
                char x; cin >> x;
                qu[i] = {type, x - 'a' + 1, 0};
            }
            else{
                char x, y; cin >> x >> y;
                qu[i] = {type, x - 'a'+ 1, y - 'a' + 1};
            }
        }
        FOR(i, 0, 26) d[i] = i;
        FORR(i, n, 1){
            if(qu[i].ty == 1) ans[++cnt] = d[qu[i].x];
            else d[qu[i].x] = d[qu[i].y] ? d[qu[i].y] : qu[i].y;
        }
        reverse(ans+1, ans+cnt+1);
        FOR(i, 1, cnt) cout << char(ans[i] + 'a' - 1);
    }
}
