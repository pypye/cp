long long catalan(int n)
{
    long long cat = 1;
    for (int i = 1; i < n; i++) {
        cat *= (4 * i - 2);
        cat /= (i + 1);
    }
    return cat;
}