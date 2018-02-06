#include <cstdio>
#include <cmath>
#define maxn 110
#define eps 1e-8
using namespace std;
int n;
typedef long long LL;
struct Point {
    double x, y;
    Point(double _x=0, double _y=0) : x(_x), y(_y) {}
    double operator * (const Point& b) const {
        return x * b.x + y * b.y;
    }
    double operator ^ (const Point& b) const {
        return x * b.y - y * b.x;
    }
    Point operator - (const Point& b) const {
        return Point(x-b.x, y-b.y);
    }
};
struct Seg {
    Point s, t;
    Seg() {}
    Seg(Point _s, Point _t) : s(_s), t(_t) {}
}a[maxn];
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x > 0) return 1;
    else return -1;
}
double xmult(Point s, Point t, Point p) {
    return (s-p) ^ (t-p);
}
bool Seg_inter_line(Point s0, Point t0, Point s, Point t) {
    double v1 = xmult(s0, t0, s), v2 = xmult(s0, t0, t);
    return sgn(v1) * sgn(v2) <= 0;
}
bool check(Point s, Point t) {
    if (!sgn(sqrt((t-s)*(t-s)))) return false;
    for (int i = 0; i < n; ++i) {
        if (!Seg_inter_line(s, t, a[i].s, a[i].t)) return false;
    }
    return true;
}
void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lf%lf%lf%lf", &a[i].s.x, &a[i].s.y, &a[i].t.x, &a[i].t.y);
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (check(a[i].s, a[j].s) || check(a[i].s, a[j].t)
                    || check(a[i].t, a[j].s) || check(a[i].t, a[j].t)) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    if (flag) printf("Yes!\n");
    else printf("No!\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
