#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <long long, long long>
#define F first
#define S second
#define maxn 400005
using namespace std;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
int n, m, k, x0, y0, direction, cnt;
vector <long long> res[maxn], ans;
unordered_map <long long, long long> M[5];
queue <pair> q;
int ChangeDir(int x, char c){
    if(x == 1){
        if(c == 'U') return 1; if(c == 'R') return 2;
        if(c == 'D') return 3; if(c == 'L') return 4;
    }
    if(x == 2){
        if(c == 'U') return 2; if(c == 'R') return 3;
        if(c == 'D') return 4; if(c == 'L') return 1;
    }
    if(x == 3){
        if(c == 'U') return 3; if(c == 'R') return 4;
        if(c == 'D') return 1; if(c == 'L') return 2;
    }
    if(x == 4){
        if(c == 'U') return 4; if(c == 'R') return 1;
        if(c == 'D') return 2; if(c == 'L') return 3;
    }
}
long long GoDir(long long x, int dir){
    if(dir == 1) return x-1;
    if(dir == 3) return x+1;
    if(dir == 2) return x+(m+1);
    if(dir == 4) return x-(m+1);
}
char Priority[4] = {'L', 'U', 'R', 'D'};
void Go(int &x, int &y, char c){
    if(c == 'L') x -= 1, direction = 1;
    if(c == 'U') y += 1, direction = 2;
    if(c == 'R') x += 1, direction = 3;
    if(c == 'D') y -= 1, direction = 4;
}
long long To(int x, int y){
    return 1ll * (m + 1) * y + x;
}
pair Convert(long long u){
    return {u % (m+1), u / (m+1)};
}
void Find(long long x, long long y, int dir){
    bool check = 0;
    FOR(i, 1, 4){
        if(M[i][x] == y) check = 1;
    }
    if(!check){
        M[dir][x] = y;
        q.push({x, y});
    }
}
int FindDir(long long x, long long y){
    FOR(i, 1, 4) if(M[i][x] == y) return i;
    return 0;
}
void ResetDir(long long x, long long y){
    FOR(i, 1, 4) if(M[i][x] == y) M[i][x] = 0;
}
int main()
{
//    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    freopen("chocolate.inp", "r", stdin);
    freopen("chocolate.out", "w", stdout);
    read(m); read(n); read(k); read(x0); read(y0);
    FOR(i, 1, m){
        Find(To(i-1, 0), To(i, 0), 3);
        Find(To(i, n), To(i-1, n), 1);
    }
    FOR(i, 1, n){
        Find(To(0, i), To(0, i-1), 4);
        Find(To(m, i-1), To(m, i), 2);
    }
    FOR(i, 1, k){
        char c;
        c = getchar();
        int x = x0, y = y0;
        Go(x0, y0, c);
        Find(To(x, y), To(x0, y0), direction);
        if(direction % 2) Find(To(x0, y0), To(x, y), 4 - direction);
        else Find(To(x0, y0), To(x, y), 6 - direction);
    }
    while(q.size()){
        while(q.size() && !FindDir(q.front().F, q.front().S)) q.pop();
        if(q.size()){
            cnt++;
            auto x = q.front(); q.pop();
            long long u = x.F, v = x.S, firstdir = FindDir(x.F, x.S);
            while(FindDir(u, v)){
                long long newdir, newpos;
                FOR(i, 0, 3){
                    newdir = ChangeDir(FindDir(u, v), Priority[i]);
                    newpos = GoDir(v, newdir);
                    if(FindDir(v, newpos)) {
                        if(i == 0 || i == 2) res[cnt].push_back(v);
                        break;
                    }
                }
                int lastdir = FindDir(u, v);
                ResetDir(u, v);
                u = v;
                v = newpos;
                if(u == x.F) {
                    if(firstdir != lastdir) res[cnt].push_back(u);
                    break;
                }
            }
        }
    }
    FOR(i, 1, cnt){
        long long s = 0;
        if(res[i].size() < 2) continue;
        res[i].push_back(res[i][0]);
        FOR(v, 1, res[i].size()-1){
            int x = Convert(res[i][v]).F, y = Convert(res[i][v]).S;
            int x1 = Convert(res[i][v-1]).F, y1 = Convert(res[i][v-1]).S;
            s += 1ll * (x - x1) * (y + y1);
        }
        if(s != 0) ans.push_back(-s/2);
    }
    sort(ans.begin(), ans.end());
    writeln(ans.size());
    for(auto v : ans) write(v);
}
