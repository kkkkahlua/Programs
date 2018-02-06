#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#define inf 0x3f3f3f3f
#define eps 1e-6
#define maxn 110
using namespace std;
typedef long long LL;
struct POINT {
    double x;
    double y;
    POINT(double a=0, double b=0) { x=a; y=b;} //constructor
};
struct LINESEG {
    POINT s;
    POINT e;
    LINESEG(POINT a, POINT b) { s=a; e=b;}
    LINESEG() { }
}seg[maxn];
double multiply(POINT sp,POINT ep,POINT op) {
    return((sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y));
}
bool intersect(LINESEG u,LINESEG v) {
    return( (max(u.s.x,u.e.x)>=min(v.s.x,v.e.x))&&                     //排斥实验
        (max(v.s.x,v.e.x)>=min(u.s.x,u.e.x))&&
        (max(u.s.y,u.e.y)>=min(v.s.y,v.e.y))&&
        (max(v.s.y,v.e.y)>=min(u.s.y,u.e.y))&&
        (multiply(v.s,u.e,u.s)*multiply(u.e,v.e,u.s)>=0)&&         //跨立实验
        (multiply(u.s,v.e,v.s)*multiply(v.e,u.e,v.s)>=0));
}
bool inside(LINESEG l, int x1, int y1, int x2, int y2) {
    return l.s.x >= x1 && l.s.x <= x2 && l.s.y <= y1 && l.s.y >= y2;
    return l.e.x >= x1 && l.e.x <= x2 && l.e.y <= y1 && l.e.y >= y2;
}
void work() {
    int x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    if (x3 > x4) swap(x3, x4); if (y3 < y4) swap(y3, y4);
    LINESEG l(POINT(x1, y1), POINT(x2, y2));
    if (intersect(l, LINESEG(POINT(x3, y3), POINT(x3, y4))) || intersect(l, LINESEG(POINT(x3, y3), POINT(x4, y3)))
        || intersect(l, LINESEG(POINT(x4, y3), POINT(x4, y4))) || intersect(l, LINESEG(POINT(x3, y4), POINT(x4, y4)))
        || inside(l, x3, y3, x4, y4)) {
        putchar('T');
    }
    else putchar('F');
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    while (n--) work();
    return 0;
}
