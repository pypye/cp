//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define pair pair <int, int>
#define F first
#define S second
#define maxn 100005
using namespace std;
int n;
long long res, temp;
pair a[maxn];
priority_queue <long long> q;
void calc(long long x){
    while(q.size() && temp + (-q.top()) <= x){
        temp += -q.top();
        res += temp;
        q.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("fine.inp");
    ofstream cout("fine.out");
    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;
    sort(a+1, a+n+1);
    FOR(i, 1, n){
        calc(a[i].F);
        res -= a[i].F;
        if(q.size()){
            long long x = -q.top(); q.pop();
            q.push(-(temp + x - a[i].F));
        }
        temp = a[i].F;
        q.push(-a[i].S);
    }
    calc(1e18);
    cout << res;
}
