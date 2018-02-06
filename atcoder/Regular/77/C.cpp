#include <bits/stdc++.h>
#define maxn 200010
int a[maxn], ans[maxn];
using namespace std;
typedef long long LL;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int i = 0, j = n-1;
    for (; j >= 0; ++i, j -= 2) ans[i] = a[j];
    j += 2;
    for (j = j ^ 1; j < n; ++i, j += 2) ans[i] = a[j];
    printf("%d", ans[0]);
    for (int i = 1; i < n; ++i) printf(" %d", ans[i]); puts("");
    return 0;
}
