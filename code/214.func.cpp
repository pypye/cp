#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
long long k, r, p, q, mod;
long long multi(long long n, long long k){
    if(k == 0) return 0;
    long long b = multi(n, k/2);
    b = (b + b) % mod;
    if(k % 2) return (b + n) % mod;
    return b;
}
struct matrix
{
    long long val[2][2];
    matrix(){
        memset(val, 0, sizeof(val));
    }
    matrix operator * (const matrix &x){
        matrix res;
        FOR(i, 0, 1)
            FOR(j, 0, 1){
                long long cv = 0;
                FOR(p, 0, 1){
                    cv = (cv + multi(val[i][p], x.val[p][j])) % mod;
                }
                res.val[i][j] = cv % mod;
            }
        return res;
    }
};

matrix power(matrix A, long long b)
{
    matrix C;
    C.val[0][0] = C.val[1][1] = 1;
    for (; b; b /= 2, A = A * A)
        if (b & 1) C = C * A;
    return C;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("func.inp");
    ofstream cout("func.out");
    while(cin >> k){
        matrix A, B;
        cin >> r >> p >> q >> mod;
        int x = __gcd(p, q);
        p /= x, q /= x;
        A.val[0][1] = 1; A.val[1][0] = 1; A.val[1][1] = r;
        B.val[0][0] = p; B.val[1][0] = q;
        A = power(A, k-1) * B;
        cout << A.val[0][0] << " " << A.val[1][0] << '\n';
    }

}
