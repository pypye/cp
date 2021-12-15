#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn
using namespace std;
int a[4][4], cntx, cnto, cnt, won;
int check(int a, int b, int c){
    if(a == b && b == c) return a;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("caro.inp");
    ofstream cout("caro.out");
    FOR(i, 1, 3)
        FOR(j, 1, 3){
            char x;
            cin >> x;
            if(x == 'X'){
                cntx++;
                a[i][j] = 1;
                continue;
            }
            if(x == '0'){
                cnto++;
                a[i][j] = 2;
                continue;
            }
            cnt++;
        }
    if(cnto > cntx || cntx - cnto > 1) return cout << "invalid", 0;
    FOR(i, 1, 3){
        if(check(a[i][1], a[i][2], a[i][3]) == 1){
            if(won == 2) return cout << "invalid", 0;
            won = 1;
        }
        if(check(a[i][1], a[i][2], a[i][3]) == 2){
            if(won == 1) return cout << "invalid", 0;
            won = 2;
        }
    }
    FOR(i, 1, 3){
        if(check(a[1][i], a[2][i], a[3][i]) == 1){
            if(won == 2) return cout << "invalid", 0;
            won = 1;
        }
        if(check(a[1][i], a[2][i], a[3][i]) == 2){
            if(won == 1) return cout << "invalid", 0;
            won = 2;
        }
    }
    if(check(a[1][1], a[2][2], a[3][3]) == 1){
        if(won == 2) return cout << "invalid", 0;
        won = 1;
    }
    if(check(a[1][1], a[2][2], a[3][3]) == 2){
        if(won == 1) return cout << "invalid", 0;
        won = 2;
    }
    if(check(a[1][3], a[2][2], a[3][1]) == 1){
        if(won == 2) return cout << "invalid", 0;
        won = 1;
    }
    if(check(a[1][3], a[2][2], a[3][1]) == 2){
        if(won == 1) return cout << "invalid", 0;
        won = 2;
    }
    if(won == 1 && cnto == cntx) return cout << "invalid", 0;
    if(won == 2 && cnto != cntx) return cout << "invalid", 0;
    if(won == 1) return cout << "TL won", 0;
    if(won == 2) return cout << "BD won", 0;
    if(cnt == 0) return cout << "draw", 0;
    if(cntx > cnto) return cout << "BD was making a move", 0;
    else return cout << "TL was making a move", 0;
}
