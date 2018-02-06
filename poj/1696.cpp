#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#define INF 1e200
#define EP 1E-10
#define maxn 110
using namespace std;
typedef long long LL;
struct POINT {
    double x;
    double y;
    POINT(double a=0, double b=0) { x=a; y=b;} //constructor
};
struct Node {
    int id;
    POINT p;
    Node(int _id, POINT _p) : id(_id), p(_p) {}
    Node() {}
}node[110];
bool use[110];
double dist(POINT p1,POINT p2) {
    return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) );
}
double angle(POINT o,POINT s,POINT e) {
    double cosfi,fi,norm;
    double dsx = s.x - o.x;
    double dsy = s.y - o.y;
    double dex = e.x - o.x;
    double dey = e.y - o.y;

    cosfi=dsx*dex+dsy*dey;
    norm=(dsx*dsx+dsy*dsy)*(dex*dex+dey*dey);
    cosfi /= sqrt( norm );

    if (cosfi >=  1.0 ) return 0;
    if (cosfi <= -1.0 ) return -3.1415926;

    fi=acos(cosfi);
    if (dsx*dey-dsy*dex>0) return fi;
    return -fi;
}
POINT mirror(POINT e, POINT o) {
    return POINT(2*o.x-e.x, 2*o.y-e.y);
}
void work() {
    int n;
    scanf("%d", &n);
    int miny = 101, minx = 101, idx = -1;
    for (int i = 1; i <= n; ++i) {
        int id, x, y;
        scanf("%d%d%d", &id, &x, &y);
        node[i] = Node(id, POINT(x, y));
        if (y < miny || (y == miny && x < minx)) miny = y, minx = x, idx = id;
    }
    memset(use, 0, sizeof(use));
    use[idx] = true;
    printf("%d %d", n, idx);
    POINT ori = node[idx].p, base = POINT(101, 0);
    for (int tot = 1; tot < n; ++tot) {
        double minfi = INF, mindis = INF;
        int tid = -1;
        for (int i = 1; i <= n; ++i) {
            if (!use[i]) {
                double fi = angle(ori, base, node[i].p), dis = dist(ori, node[i].p);
                if (fi < minfi || (fabs(fi-minfi)<EP && dis < mindis)) minfi = fi, mindis = dis, tid = i;
            }
        }
        use[tid] = true;
        printf(" %d", tid);
        base = mirror(ori, node[tid].p); ori = node[tid].p;
    }
    putchar('\n');
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
