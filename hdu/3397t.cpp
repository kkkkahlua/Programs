#include <cstdio>
#include <algorithm>
#define MAX 100010
using namespace std;
struct node {
    int id, l, r, num, l1, r1, l0, r0, max, tag = -1;
}tree[MAX * 4];
int a[MAX], n, m;
int tot = 0;
void build(int id, int l, int r) {
    printf("%d %d %d\n", id, l, r);

    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
}

void work() {

    build(1, 1, n);

}
int main() {
    freopen("3397.in", "r", stdin);
//    freopen("3397.out", "w", stdout);
    int T;
    scanf("%d", &T);
//	scanf("%d%d", &n, &m);
//	build(1, 1, n);
//    work();
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}

