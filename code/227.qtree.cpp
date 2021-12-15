///Phß║ím Nguyß╗àn Tuß║Ñn Ho├áng///
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define repd(i,a,b) for(int i = (a);i >= (b);i--)
#define repn(i,n) for(int i = 0;i < n;i++)
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define PB push_back
#define Task "qtree"
#define N 200012
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
template <class T> inline read(T &a){a = 0;char c;bool nega = 0;while(!isdigit(c = getchar()) && c != '-');if(c == '-') nega = 1,c = getchar();a = c - 48;while(isdigit(c = getchar()))a = a * 10 + c - 48;if(nega) a = -a;}
template <class T> inline writep(T a){if(a > 9) writep(a / 10);putchar(a % 10 + 48);}
template <class T> inline write(T a){if(a < 0) putchar('-'),a = -a;writep(a);putchar(' ');}
template <class T> inline writeln(T a){write(a);putchar('\n');}
int n,q,p[N][21],nBase,nChain;
int nChild[N],pos[N],chainHead[N],chainInd[N],nPos[N],epos[N],h[N];
long long lazy[4*N],t[4*N];
vector<int> g[N];
void DFS( int u)
{
    nChild[u] = 1;
    for (auto v : g[u])
        if(p[u][0] != v)
        {
            h[v] = h[u] + 1;
            p[v][0] = u;
            rep(i, 1, 20)
                p[v][i] = p[p[v][i-1]][i-1];
            DFS(v);
            nChild[u] += nChild[v];
        }
}
int bit(int v, int i)
{
    return (v >> i)&1;
}
int LCA(int u, int v)
{
    if (h[u] > h[v]) swap(u,v);
    int delta = h[v] - h[u];
    rep(i,0,20)
            if(bit(delta,i) == 1)
                v = p[v][i];
    repd(i, 20, 0)
        if(p[v][i] != p[u][i])
        {
            u = p[u][i];
            v = p[v][i];
        }
    if(u!=v) return p[u][0];
    else return u;

}
void HLD(int u)
{
    if(!chainHead[nChain]) chainHead[nChain] = u;
    chainInd[u] = nChain;
    pos[u] = ++ nBase;
    nPos[nBase] = u;
    int mxVtx = -1;
    for(auto v : g[u])if(v != p[u][0])
    {
        if(mxVtx == -1 || nChild[v] > nChild[mxVtx]) mxVtx = v;
    }
    if(mxVtx > -1) HLD(mxVtx);

    for(auto v : g[u])
        if(v != p[u][0] && v != mxVtx) ++nChain,HLD(v);
    epos[u] = nBase;
}
void down(int id,int l,int r)
{
    int mid = (l + r)/2;
    long long val = lazy[id]/(r-l+1);
    t[id*2] += val * (mid - l + 1);
    t[id*2+1] += val * (r - mid);
    lazy[id*2] += val *(mid - l  + 1);
    lazy[id*2+1] += val *(r - mid);
    lazy[id] = 0;
}
void update(int l,int r,int id,int u,int v,long long val)
{
    if(l > v || r < u) return;
    if(l >= u && r <= v)
    {
        t[id] += val * (r-l+1);
        lazy[id] += val * (r-l+1);
        return;
    }
    down(id,l,r);
    int mid = (l+r)/2;
    update(l,mid,id*2,u,v,val);
    update(mid+1,r,id*2+1,u,v,val);
    t[id] = t[id*2] + t[id*2+1];
}
long long get(int l,int r,int id,int u,int v)
{

    if(u > r || l > v) return 0;
    if(u <= l && v >= r)
        return t[id];
    down(id, l, r);
    int mid = (l+r) /2;
    long long left = get(l,mid,id*2,u,v);
    long long right = get(mid+1,r,id*2+1,u,v);
    return left + right;
}
long long Get(int u,int a)
{
    long long sum = 0;
    int uchain = chainInd[u], achain = chainInd[a];
    while(1)
    {
        if(uchain == achain)
        {
            sum += get(1,n,1,pos[a],pos[u]);
            break;
        }
        sum += get(1,n,1,pos[chainHead[uchain]],pos[u]);
        u = p[chainHead[uchain]][0];
        uchain = chainInd[u];
    }
    return sum;
}
void UpdateRoot(int root,int c)
{
    update(1,n,1,pos[root],epos[root],c);
}

void Update(int u,int c)
{
    update(1,n,1,pos[u],pos[u],c);
}

int main()
{
    IOS();
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >> n >> q;
    rep(i,2,n)
    {
        int u;
        cin >> u;
        g[u].PB(i);
        g[i].PB(u);
    }
    DFS(1);
    HLD(1);
    rep(i,1,q)
    {
        int type,u,v,c;
        cin >> type;
        if(type == 1){
            cin >> u >> c;
            Update(u,c);
        }
        else if(type == 2){
            cin >> u >> c;
            UpdateRoot(u,c);
        }
        else if(type == 3){
            cin >> u;
            cout << Get(u,u) << endl;
        }
        else{
            cin >> u >> v;
            int mid = LCA(u,v);
            cout << Get(u,mid) + Get(v,mid) - Get(mid,mid) << endl;
        }
    }
}
