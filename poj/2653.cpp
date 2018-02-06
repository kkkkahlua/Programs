#include <cstdio>
#include <cmath>
#define inf 1e200
#define eps 1e-6
using namespace std;
typedef long long LL;
struct Point {
    double x, y;
    Point(double _x=0, double _y=0) : x(_x), y(_y) {}
    Point operator + (const Point& b) const {
        return Point(x+b.x, y+b.y);
    }
    Point operator - (const Point& b) const {
        return Point(x-b.x, y-b.y);
    }
    double operator * (const Point& b) const {
        return x*b.x + y*b.y;
    }
    double operator ^ (const Point& b) const {
        return x*b.y - y*b.x;
    }
}point[20][4];
struct Seg {
    Point s, e;
    Seg(Point _s, Point _e) : s(_s), e(_e) {}
    Seg() {}
}wall[20][3];
double dist[100][100];
inline int id(int x, int y) { return 4*x+y-3; }
double euler_dist(Point a, Point b) {
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x > 0) return 1;
    return -1;
}
double xmult(Point s, Point e, Point b) {
    return (s-b) ^ (e-b);
}
bool seg_inter_line(Point s, Point e, Seg l) {
    double v1 = xmult(s, e, l.s), v2 = xmult(s, e, l.e);
    return sgn(v1) * sgn(v2) < 0;
}
bool check(Point s, Point e, int l, int r) {
    for (int i = l; i < r; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (seg_inter_line(s, e, wall[i][j])) return false;
        }
    }
    return true;
}
void build(Point e, int i, int j) {
    if (check(point[0][0], e, 1, i)) {
        dist[0][id(i,j)] = dist[id(i,j)][0] = euler_dist(point[0][0], point[i][j]);
        return;
    }
    for (int k = 1; k < i; ++k) {
        for (int t = 0; t < 4; ++t) {
            if (check(point[k][t], e, k+1, i)) {
                dist[id(k,t)][id(i,j)] = dist[id(i,j)][id(k,t)] = euler_dist(point[k][t], point[i][j]);
            }
        }
    }
}
int n;
void work() {
    point[0][0] = Point(0, 5); point[n+1][0] = Point(10, 5);
    for (int i = 0; i < 100; ++i) for (int j = i+1; j < 100; ++j) dist[i][j] = dist[j][i] = inf;
    for (int i = 1; i <= n; ++i) {
        double x,y1,y2,y3,y4;
        scanf("%lf%lf%lf%lf%lf", &x, &y1, &y2, &y3, &y4);
        point[i][0] = Point(x, y1), point[i][1] = Point(x, y2),
        point[i][2] = Point(x, y3), point[i][3] = Point(x, y4);
        wall[i][0] = Seg(Point(x, 0), point[i][0]),
        wall[i][1] = Seg(point[i][1], point[i][2]),
        wall[i][2] = Seg(point[i][3], Point(x, 10));
        for (int j = 0; j < 4; ++j) build(point[i][j], i, j);
    }
    build(point[n+1][0], n+1, 0);
    int tot = 4*n+2;
//    for (int i = 0; i < tot; ++i) {
//        for (int j = 0; j < tot; ++j) if (dist[i][j] == inf) printf("0 ");else printf("%.2f ", dist[i][j]); printf("\n");
//    }
    for (int k = 0; k < tot; ++k) {
        for (int i = 0; i < tot; ++i) {
            for (int j = i+1; j < tot; ++j) {
                if (i == k || j == k) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[j][i] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
//    for (int i = 0; i < tot; ++i) {
//        for (int j = 0; j < tot; ++j) printf("%.2f ", dist[i][j]); printf("\n");
//    }
    printf("%.2f\n", dist[0][tot-1]);
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) && n != -1) work();
    return 0;
}
