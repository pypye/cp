#include <bits/stdc++.h>
#define FOR(i,x,y) for(int i=x; i<=y; ++i)
using namespace std;
long long n;
int m;
typedef long long ll;
struct matrix{
    long long val[4][4];
    matrix()
    {
        reset(val);
    }
    matrix operator * (const matrix &x)
    {
        matrix res;
        FOR(u,1,3)
            FOR(v, 1, 3)
                FOR(k, 1, 3)
                    (res.val[u][v] += ((ll)val[u][k]*x.val[k][v])) %= m;
        return res;
    }
};
matrix A, ans;
matrix pow(matrix A, long long a)
{
    matrix C;
    FOR(i,0,3) C.val[i][i] = 1;
    for(;a;a/=2,A = A * A)
        if(a%2)
            C = C*A;
    return C;
}
int main()
{
    cin >> n >> m;
    A.val[1][1] = 1;
    A.val[1][2] = 1;
    A.val[1][3] = 1;
    A.val[2][1] = 1;
    A.val[3][2] = 1;
    ans = pow(A,n);
    cout <<ans.val[1][1] %m;

}

