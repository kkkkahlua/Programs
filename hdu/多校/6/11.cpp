#include <bits/stdc++.h>
inline int max(int a, int b) { return a > b ? a: b;}
void work() {
    int n;
    scanf("%d", &n);
    int ans=  0;
    for (int i = 0; i < n; ++i) {
        int a,b,c,ab,ac,bc,abc;
        scanf("%d%d%d%d%d%d%d", &a, &b, &c, &ab, &bc, &ac, &abc);
        int tot = 0;
        if (a-ab-ac+abc >= 0 && b-ab-bc+abc >= 0 && c-ac-bc+abc >= 0 && ab-abc >= 0 && bc-abc >= 0 && ac-abc >=0 && abc >= 0) {
            tot = a + b +c-ab-ac-bc+abc;
            ans = max(ans, tot);
        }
    }
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
