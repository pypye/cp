//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100005
#define ncount 10000002
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define pll pair<long long, long long>
#define Task "word"

using namespace std;

typedef long long ll;
typedef long double ld;

const long long xmax = 1ll << 60;

pll b[maxn];
int n, m, k;
long long res = 0;

int Next[ncount][2], cnt=0;
int Link[ncount];

void Add(string s) {
    int u=0;
    for (char c : s)
    {
        int p = c - '0';
        if (!Next[u][p]) Next[u][p] = ++cnt;
        u = Next[u][p];
    }
    num[u] = 1;
}

int Get_next(int u, int k) {
    for (int i = u; i!=-1; i = Link[i])
        if (Next[i][k]) return Next[i][k];
    return 0;
}

void BFS() {
    queue<int> qu;
    qu.push(0);
    Link[0]=-1;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (int p = 0; p < 2; p++)
            if (int v = Next[u][p])
            {
                Link[v] = Get_next(Link[u], p);
                qu.push(v);
            }
    }
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        string s; cin >> s;
        Add(s);
    }
    BFS();
    return 0;
}

