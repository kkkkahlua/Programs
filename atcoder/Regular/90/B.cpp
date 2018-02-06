#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
typedef long long LL;
int fa[maxn], off[maxn];
int find(int x) {
    if (fa[x] == x) return x;
    int temp = fa[x];
    fa[x] = find(fa[x]);
    off[x] += off[temp];
    return fa[x];
}
int main() {
//    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 0; i < m; ++i) {
        int l, r, d;
        scanf("%d%d%d", &l, &r, &d);
        int fl = find(l), fr = find(r);
        if (fl == fr) {
            if (off[r] - off[l] == d) continue;
            else { puts("No"); return 0; }
        }
        else {
            fa[fr] = fl;
            off[fr] = d - off[r] + off[l];
        }
    }
    puts("Yes");
    return 0;
}
