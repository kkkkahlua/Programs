#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
int fa[maxn], fa2[maxn], a[maxn];
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    int h;
    scanf("%d", &h);
    for (int i = 0; i <= h; ++i) scanf("%d", &a[i]);
    if (h == 1) { puts("perfect"); return 0; }
    bool flag = true;
    for (int i = 1; i < h; ++i) {
        if (a[i]>=2 && a[i+1]>=2) {
            flag = false;
            break;
        }
    }
    if (flag) { puts("perfect"); return 0; }
    puts("ambiguous");
    int tot = 0, f = 0;
    fa[tot++] = f++;
    for (int i = 1; i <= h; ++i) {
        for (int j = 0; j < a[i]; ++j) fa[tot++] = f;
        f += a[i-1];
    }
    int tot2 = 0; f = 0;
    fa2[tot2++] = f++;
    for (int i = 1; i <= h; ++i) {
        if (a[i] > 1 && a[i-1] > 1) {
            for (int j = 0; j < a[i]-1; ++j) fa2[tot2++] = f;
            fa2[tot2++] = ++f;
            f += a[i-1]-1;
        }
        else {
            for (int j = 0; j < a[i]; ++j) fa2[tot2++] = f;
            f += a[i-1];
        }
    }
    printf("%d", fa[0]);
    for (int i = 1; i < tot; ++i) printf(" %d", fa[i]); puts("");
    printf("%d", fa2[0]);
    for (int i = 1; i < tot2; ++i) printf(" %d", fa2[i]); puts("");

    return 0;
}
