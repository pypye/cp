#include <bits/stdc++.h>

using namespace std;

int randint(int From, int To){
    return rand()%To + From;
}

int main(){
    srand(time(NULL));
    freopen(".inp", "w", stdout);
    int n = randint(1, 10000);
    int x = randint(1, n);
    cout << n << " " << " " << x;
}