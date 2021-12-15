#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define maxn 100005
using namespace std;
int n, q, root1[maxn], root2[maxn];
queue <pair> q1, q2;
vector <int> a[maxn], b[maxn];
int Get_root1(int u){
    return (root1[u]) ? root1[u] = Get_root1(root1[u]) : u;
}
int Get_root2(int u){
    return (root2[u]) ? root2[u] = Get_root2(root2[u]) : u;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("balanced.inp");
    //ofstream cout("balanced.out");
    cin >> n >> q;
    while(q--){
        int type, u, v, check = 0;
        cin >> type >> u >> v;
        if(type == 1){
            int p = Get_root1(u);
            int q = Get_root1(v);
            if(p != q){
                if(p > q) swap(p, q);
                root1[p] += root1[q];
                root1[q] = p;
                q1.push({u, v});
            }
        }
        else{
            int p = Get_root2(u);
            int q = Get_root2(v);
            if(p != q){
                if(p > q) swap(p, q);
                root2[p] += root2[q];
                root2[q] = p;
                q2.push({u, v});
            }
        }
        while(q1.size()){
            pair u = q1.front();
            if(Get_root2(u.first) != Get_root2(u.second)) break;
            q1.pop();
        }
        while(q2.size()){
            pair u = q2.front();
            if(Get_root1(u.first) != Get_root1(u.second)) break;
            q2.pop();
        }
        if(q1.size() || q2.size()) cout << "No\n";
        else cout << "Yes\n";
    }
}
