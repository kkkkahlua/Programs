#include <bits/stdc++.h>
void upright(int x, int y, int ri, int up) {
    if (x < up || y > ri) return;
    while (true) {
        auto it = lower_bound(row.begin(), row.end(), )
    }
}
int calc(int x, int y) {
//    vector<int>& r = row[x], &c= col[y];
//    int le(0), ri(0), down(0), up(0);
//    auto it1 = lower_bound(r.begin(), r.end(), y),
//        it2 = lower_bound(c.begin(), c.end(), x);
//    if (it1 == r.end()) ri = m;
//    else ri = *it1;
//    if (it1 == r.begin()) le = 0;
//    else le = *(it1 - 1);
//    if (it2 == c.end()) down = n;
//    else down = *it2;
//    if (it2 == c.begin()) up = 0;
//    else up = *(it2 - 1);
//

//    int r = x * m + y, c = y * n + x, le(0), ri(0), down(0), up(0);
//    auto it1 = lower_bound(row.begin(), row.end(), r),
//        it2 = lower_bound(col.begin(), col.end(), c);
//    if (it1 == row.end()) ri = m - 1;
//    else {
//        int p = *it1;
//        int xp = p / m, yp = p % m;
//        if (xp == x) ri = yp - 1;
//        else ri = m - 1;
//    }
//    if (it1 == row.begin()) le = 0;
//    else {
//        int p = *(it1 - 1);
//        int xp = p / m, yp = p % m;
//        if (xp == x) le = yp + 1;
//        else le = 0;
//    }
//    if (it2 == col.end()) down = n - 1;
//    else {
//        int p = *it2;
//        int yp = p / n, xp = p % n;
//        if (yp == y) down = xp - 1;
//        else down = n - 1;
//    }
//    if (it2 == col.begin()) up = 0;
//    else {
//        int p = *(it2 - 1);
//        int yp = p / n, xp = p % n;
//        if (yp == p) up = xp + 1;
//        else up = 0;
//    }
    upright(x + 1, y + 1, ri, up);
}
void work() {
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
//        row[x].push_back(y);
//        col[y].push_back(x);
        row.push_back(x * m + y);
        col.push_back(y * n + x);
    }
//    for (int i = 0; i < n; ++i) sort(row[i].begin(), row[i].end());
//    for (int i = 0; i < m; ++i) sort(col[i].begin(), col[i].end());
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        printf("%d\n", calc(x, y));
    }
}
int main() {
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
