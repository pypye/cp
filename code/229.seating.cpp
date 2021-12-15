#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define F first
#define S second
#define maxn 200005
using namespace std;
int k, n, a[maxn], id[maxn];
set <int> save;
set <pair> s;
pair in[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("seating.inp");
    //ofstream cout("seating.out");
    cin >> k >> n;
    FOR(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        in[i*2-1] = {u, i};
        in[i*2] = {v, -i};
    }
    sort(in+1, in+2*n+1);
    s.insert({-k, 0});
    save.insert(0);
    save.insert(k+1);
    FOR(i, 1, 2*n)
    {
        int pos = in[i].S;
        if(pos > 0)
        {
            while(s.size())
            {
                auto it = *s.begin();
                if(save.find(it.S) != save.end() && save.find(it.S - it.F + 1) != save.end()) break;
                else s.erase(s.begin());
            }
            auto it = *s.begin();
            int mid = it.S + (-it.F+1)/2;
            id[pos] = mid;
            s.erase(s.begin());
            save.insert(mid);
            s.insert({-(mid - it.S - 1), it.S});
            s.insert({it.F/2, mid});
        }
        else
        {
            pos = -pos;
            auto it = save.find(id[pos]);
            auto itL = it, itR = it;
            itL--;
            itR++;
            save.erase(it);
            s.insert({-(*itR - *itL - 1), *itL});
        }
    }
    FOR(i, 1, n) cout << id[i] << " ";
}
