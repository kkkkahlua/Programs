#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void build(int id, int left, int right) {
    tree[id].l = left; tree[id].r = right; tree[id].len = tree[id].c = 0;
    if (left == right) return;
    int mid = (left + right) >> 1;
    build(id * 2 + 1, left, mid);
    build(id * 2 + 2, mid + 1, right);
}
void modify(int id, int left, int right, int color) {
    if (left == right) {
        tree[id].c = color;
        if (color == 1) tree[id].len = 1;
        return;
    }

}
void work() {
    memset(tree, 0, sizeof(tree));
    build(0, 1, (1 << 31) - 1);
    for (int i = 0; i < n; ++i) {
        int l, r; char ch;
        scanf("%d%d%c", &l, &r, &ch);
        if (ch == 'w') modify(0, l, r, 1);
        else modify(0, l, r, 0);
    }
}
int main() {
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
