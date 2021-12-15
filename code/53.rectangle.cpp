#include <bits/stdc++.h>

#define Task "rectangle"

#define N 50005
#define T 200005

using namespace std;

struct MaxTree {
    int val[T];
    int lazy[T];

    int n;
    int x, y;

    void clear() {
        memset(val, 0, sizeof val);
        memset(lazy, 0, sizeof lazy);
    }

    void apply(int i, int d) {
        val[i] += d;
        lazy[i] += d;
    }

    void propagate(int i) {
        if (lazy[i]) {
            apply(i + i, lazy[i]);
            apply(i + i + 1, lazy[i]);
            lazy[i] = 0;
        }
    }

    void update(int l, int r, int i, int d) {
        if (x <= l && r <= y) {
            apply(i, d);
        } else {
            propagate(i);
            int mid = (l + r) >> 1;
            if (mid >= x) {
                update(l, mid, i + i, d);
            }
            if (mid < y) {
                update(mid + 1, r, i + i + 1, d);
            }
            val[i] = max(val[i + i], val[i + i + 1]);
        }
    }

    void update(int l, int r, int d) {
        x = l;
        y = r;
        if (l <= r && r >= 0 && l < n) {
            update(0, n - 1, 1, d);
        }
    }

    int get(int l, int r, int i) {
        if (x <= l && r <= y) {
            return val[i];
        }
        if (r < x || l > y) {
            return 0;
        }
        propagate(i);
        int mid = (l + r) >> 1;
        return max(get(l, mid, i + i), get(mid + 1, r, i + i + 1));
    }

    int get(int l, int r) {
        x = l;
        y = r;
        if (l <= r && r >= 0 && l < n) {
            return get(0, n - 1, 1);
        }
        return 0;
    }

    pair<int, int> find(int l, int r, int i) {
        if (l == r) {
            return {l, val[i]};
        }
        propagate(i);
        int mid = (l + r) >> 1;
        if (val[i + i + 1] < 0)  {
            return find(l, mid, i + i);
        } else {
            return find(mid + 1, r, i + i + 1);
        }
    }

    pair<int, int> find_zero_position() {
        return find(0, n - 1, 1);
    }
} t_00, t_01, t_10, t_11, f_left, f_right;

int SZ;
int n, k;
vector<int> y_lst;
pair<int, int> a[N];

void gen_l(vector<int> &l, int len) {
    for (int i = SZ - 1, j = SZ - 1; i >= 0; i--) {
        while (j >= 0 && y_lst[i] - y_lst[j] < len) {
            j--;
        }
        l[i] = j;
    }
}

int check(int len) {
    t_00.clear();
    t_01.clear();
    t_10.clear();
    t_11.clear();
    f_left.clear();
    f_right.clear();

    vector<int> l(SZ);
    gen_l(l, len);

    // for (int i = 0; i < SZ; i++) {
    //     cout << y_lst[i] << " " << i << " " << l[i] << "\n";
    // }
    auto add_left = [&](int p) {
        // cout << "add_left " << p << " " << l[p] << "\n";
        t_00.update(p, SZ - 1, 1);
        t_01.update(p, SZ - 1, 1);
        t_01.update(0, l[p], 1);
        t_11.update(0, l[p], 1);
        f_left.update(p, SZ - 1, -1);
        f_right.update(0, l[p], 1);
    };

    auto add_right = [&](int p) {
        t_00.update(p, SZ - 1, 1);
        t_10.update(p, SZ - 1, 1);
        t_10.update(0, l[p], 1);
        t_11.update(0, l[p], 1);
        f_left.update(0, l[p], 1);
        f_right.update(p, SZ - 1, -1);
    };

    auto remove_right = [&](int p) {
        t_00.update(p, SZ - 1, -1);
        t_10.update(p, SZ - 1, -1);
        t_10.update(0, l[p], -1);
        t_11.update(0, l[p], -1);
        f_left.update(0, l[p], -1);
        f_right.update(p, SZ - 1, 1);
    };

    for (int i = 0; i < n; i++) {
        add_right(a[i].second);
    }
    for (int i = 0, j = 0; j <= n - k;) {
        while (j < n && a[j].first - a[i].first < len) {
            remove_right(a[j++].second);
        }
        for (int u = i; i < n && a[u].first == a[i].first; i++) {
            add_left(a[i].second);
        }
        if (j > n - k) {
            return 0;
        }
        if (i >= k) {
            pair<int, int> left_zero_pos = f_left.find_zero_position();
            pair<int, int> right_zero_pos = f_right.find_zero_position();
            // cout << i << " " << j <<  " left: " << left_zero_pos.first << " " << left_zero_pos.second << "; right: " << right_zero_pos.first << " " << right_zero_pos.second << "\n";
            if (left_zero_pos.second < 0) {
                left_zero_pos.first--;
            }
            if (right_zero_pos.second < 0) {
                right_zero_pos.first--;
            }
            int p = min(left_zero_pos.first, right_zero_pos.first);
            int q = max(left_zero_pos.first + 1, right_zero_pos.first + 1);
            int r = max(t_00.get(0, p), t_11.get(q, SZ - 1));
            // cout << "t00 = " << t_00.get(0, p) << "\n";
            // cout << "t11 = " << t_11.get(q, SZ - 1) << "\n";
            if (q - p > 1) {
                p++;
                q--;
                // cout << p << " " << q << "\n";
                if (left_zero_pos.first < right_zero_pos.first) {
                    // cout << "- t10 = " << t_10.get(p, q) << "\n";
                    r = max(r, t_10.get(p, q));
                } else {
                    // cout << "- t01 = " << t_01.get(p, q) << "\n";
                    r = max(r, t_01.get(p, q));
                }
            }
            if (r >= k) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        y_lst.push_back(y);
    }
    sort(y_lst.begin(), y_lst.end());
    y_lst.resize(unique(y_lst.begin(), y_lst.end()) - y_lst.begin());
    for (int i = 0; i < n; i++) {
        a[i].second = lower_bound(y_lst.begin(), y_lst.end(), a[i].second) - y_lst.begin();
    }
    sort(a, a + n);
    SZ = y_lst.size();

    t_00.n = SZ;
    t_01.n = SZ;
    t_10.n = SZ;
    t_11.n = SZ;
    f_left.n = SZ;
    f_right.n = SZ;

    // cout << check(3);
    // return 0;
    int l = 0;
    int r = 1 << 21;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l;
}
