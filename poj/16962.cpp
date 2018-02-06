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
bool cmp(node a, node b) {
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
    swap(node[1], node[idx]);
    int pos = 1;
    for (int i = 2; i <= n; ++i) {
        sort(node+i, node+n+1, cmp);
        pos = i;
    }
    printf("%d", n);
    for (int i = 1; i <= n; ++i) printf(" %d", node[i].id); putchar('\n');
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
