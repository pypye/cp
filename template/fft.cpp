#include <bits/stdc++.h>
using namespace std;

typedef complex<double> base;
void fft(vector<base> &P, bool invert)
{
    int n = P.size();
    if (n == 1)
        return;
    vector<base> Ps(n / 2), P0(n / 2);
    for (int i = 0, j = 0; i < n; i += 2, j++)
    {
        Ps[j] = P[i];
        P0[j] = P[i + 1];
    }

    fft(Ps, invert);
    fft(P0, invert);

    double angels = 2 * acos(-1) / n * (invert ? -1 : 1);
    base w(1), wn(cos(angels), sin(angels));

    for (int k = 0; k < n / 2; k++)
    {
        P[k] = Ps[k] + w * P0[k];
        P[k + n / 2] = Ps[k] - w * P0[k];
        if (invert)
        {
            P[k] /= 2;
            P[k + n / 2] /= 2;
        }
        w *= wn;
    }
}

void multiply(vector<double> &a, vector<double> &b, vector<double> &result)
{
    vector<base> fx(a.begin(), a.end()), fy(b.begin(), b.end()), hx;
    size_t n = 1;
    while (n < max(a.size(), b.size()))
    {
        n <<= 1;
    }
    n <<= 1;
    fx.resize(n), fy.resize(n), hx.resize(n);

    fft(fx, false);
    fft(fy, false);

    for (size_t i = 0; i < n; i++)
    {
        hx[i] = fx[i] * fy[i];
    }

    fft(hx, true);

    result.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        result[i] = hx[i].real();
    }
}

int main(int argc, char const *argv[])
{
    vector<double> fx = {1, 1, 1}; // f(x) = 1 + x + x^2
    vector<double> gx = {1, 3};    // g(x) = 1+3x

    std::vector<double> res;

    multiply(fx, gx, res);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " "; // h(x) = 1+ 4x + 4x^2 + 3x^3
    cout << endl;
    return 0;
}
