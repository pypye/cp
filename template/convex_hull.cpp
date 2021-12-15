#include <bits/stdc++.h>

using namespace std;

struct Point
{
    long long x, y;
};

int orientation(Point p, Point q, Point r)
{
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

int convexHull(Point points[], int n)
{
    if (n < 3)
        return -1;
    vector<Point> hull;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q;
    do
    {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;

    } while (p != l);

    return hull.size();
}

int main(int argc, char const *argv[])
{
    if (fopen(R"(D:\Code_Cpp\codeforces\inp.txt)", "r"))
        freopen(R"(D:\Code_Cpp\codeforces\inp.txt)", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int x0, y0, x1, y1, x2, y2, x3, y3;
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Point points[] = {{x0, y0},
                          {x1, y1},
                          {x2, y2},
                          {x3, y3}};
        bool mark = true;
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                for (int k = j + 1; k < 4; k++)
                {
                    if (orientation(points[i], points[j], points[k]) == 0)
                    {
                        mark = false;
                    }
                }
            }
        }
        if (!mark)
            cout << "NO\n";
        else
            cout << (convexHull(points, 4) == 4 ? "YES" : "NO") << '\n';
    }
    return 0;
}