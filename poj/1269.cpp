#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
struct Line {
    int a, b, c;
    Line(int _a=0, int _b=0, int _c=0) : a(_a), b(_b), c(_c) {}
};
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int abs(int x) { return x > 0 ? x : -x; }
Line make_line(int x1, int y1, int x2, int y2) {
    if (x1 == x2) return Line(1, 0, -x1);
    if (y1 == y2) return Line(0, 1, -y1);
    int div = gcd(abs(x2-x1), abs(y2-y1));
    int b = (x2-x1) / div, a = (y1-y2) / div;
    if (a < 0) a = -a, b = -b;
    int c = -a * x1 - b * y1;
    return Line(a, b, c);
}
void work() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    Line l1 = make_line(x1, y1, x2, y2), l2 = make_line(x3, y3, x4, y4);
    int det = l1.a * l2.b - l2.a * l1.b;
    if (det) {
        int dx = l2.c * l1.b - l1.c * l2.b,
            dy = l2.a * l1.c - l1.a * l2.c;
        printf("POINT %.2f %.2f\n", 1.0*dx/det, 1.0*dy/det);
    }
    else {
        if (l1.c == l2.c) printf("LINE\n");
        else printf("NONE\n");
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    printf("INTERSECTING LINES OUTPUT\n");
    int n;
    scanf("%d", &n);
    while (n--) work();
    printf("END OF OUTPUT\n");
    return 0;
}
