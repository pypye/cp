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
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long
#define Task "assign"

using namespace std;

int n, m, res = 0, cur;
vector <int> ke[maxn];
int MatchX[maxn], Used[maxn];

bool DFS(int u){
    if (Used[u] == cur) return 0;
    Used[u] = cur;
    for (int v : ke[u])
        if (MatchX[v] == 0|| DFS(MatchX[v])){
            MatchX[v] = u;
            return 1;
        }
    return 0;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> m >> n;
    int u, v;
    while (cin >> u >> v) ke[u].PB(v);
    for (cur = 1; cur <= m; cur++)
        res += DFS(cur);
    cout << res << endl;
    for (int i = 1; i <= n; i++) cout << MatchX[i] << " ";
    return 0;
}

