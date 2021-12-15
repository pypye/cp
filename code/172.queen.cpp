//Pye
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define maxn 1005
using namespace std;
int n, m, a[maxn][maxn], sum[maxn][maxn], dl[maxn][maxn], dr[maxn][maxn];
int getRect(int u, int v, int x, int y){
    return sum[x][y] - sum[x][v-1] - sum[u-1][y] + sum[u-1][v-1];
}
int getDL(int u, int v, int x, int y){
    return dl[x][y] - dl[u-1][v-1];
}
int getDR(int u, int v, int x, int y){
    return dr[u][v] - dr[x-1][y+1];
}
int findCol(int i, int j){
    int l = 1, r = i+1, ans = 0;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(getRect(i-mid+1, j, i, j) == 0) l = mid;
        else r = mid;
    }
    ans += l-1;
    l = 1, r = n-i+2;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(getRect(i, j, i+mid-1, j) == 0) l = mid;
        else r = mid;
    }
    ans += l-1;
    return ans;
}
int findRow(int i, int j){
    int l = 1, r = j+1, ans = 0;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(getRect(i, j-mid+1, i, j) == 0) l = mid;
        else r = mid;
    }
    ans += l-1;
    l = 1, r = m-j+2;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(getRect(i, j, i, j+mid-1) == 0) l = mid;
        else r = mid;
    }
    ans += l-1;
    return ans;
}
int findDL(int i, int j){
    int l = 1, r = min(i+1, j+1), ans = 0;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(getDL(i-mid+1, j-mid+1, i, j) == 0) l = mid;
        else r = mid;
    }
    ans += l-1;
    l = 1, r = min(n-i, m-j) + 2;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(getDL(i, j, i+mid-1, j+mid-1) == 0) l = mid;
        else r = mid;
    }
    ans += l-1;
    return ans;
}
int findDR(int i, int j){
    int l = 1, r = min(i+1, m-j+2), ans = 0;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(getDR(i, j, i-mid+1, j+mid-1) == 0) l = mid;
        else r = mid;
    }
    ans += l-1;
    l = 1, r = min(n-i+2, j+1);
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(getDR(i+mid-1, j-mid+1, i, j) == 0) l = mid;
        else r = mid;
    }
    ans += l-1;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("queen.inp");
    ofstream cout("queen.out");
    cin >> n >> m;
    FOR(i, 1, n)
        FOR(j, 1, m){
            char x; cin >> x; a[i][j] = (x == '#');
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    FOR(i, 1, n)
        FOR(j, 1, m) dl[i][j] = dl[i-1][j-1] + a[i][j];
    FOR(i, 1, n)
        FORR(j, m, 1) dr[i][j] = dr[i-1][j+1] + a[i][j];
    FOR(i, 1, n){
        FOR(j, 1, m)
            if(!a[i][j]) cout << findCol(i, j) + findRow(i, j) + findDL(i, j) + findDR(i, j) + 1 << " ";
            else cout << 0 << " ";
        cout << '\n';
    }

}
