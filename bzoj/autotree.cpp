#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
#define C 100
using namespace std;
typedef long long LL;
int fa[maxn];
int find(int x) { return fa[x]==x ? x : fa[x] = find(fa[x]); }
void unionn(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
}
int main() {
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int n=C, m=C, lim=C;
    printf("%d %d\n", n, m);
    srand(time(NULL));
    F(i, 0, n) {
        printf("%d ", rand()%lim);
        fa[i+1]=i+1;
    }
    puts("");
    printf("0 5\n");
    F(i, 1, n) {
        while (true) {
            int x = rand()%n,y;
            do {
                y = rand()%n;
            }while (x==y);
            ++x,++y;
            if (find(x)!=find(y)) {
                printf("%d %d\n", x, y);
                unionn(x,y);
                break;
            }
        }
    }
    F(i, 0, m) {
        int op = rand()%2, l=rand()%n,r=rand()%n;
        if (l>r) swap(l,r); ++l, ++r;
        printf("%d %d %d\n", op+1, l, r);
    }
    return 0;
}
