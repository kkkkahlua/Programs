#include <bits/stdc++.h>
#include <map>
#define maxn 125260
using namespace std;
typedef long long LL;
map<int, int> m;
int a[maxn], b[maxn], n;
void work() {
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++m[a[i]];
    }
    b[0] = a[0], b[1] = a[1];
    --m[a[0]];--m[a[1]];--m[a[0]+a[1]];
    int tot = 2;
    if (m[a[0]] == 0) m.erase(a[0]);
    if (m[a[1]] == 0) m.erase(a[1]);
    if (m[a[0]+a[1]] == 0) m.erase(a[0]+a[1]);
    for (auto it = m.begin(); it != m.end();) {
        int x = it->first;
//        printf("%d\n", x);
        b[tot++] = x;
        --m[x];
        for (int i = 0; i < tot - 1; ++i) {
            --m[b[i] + x];
            if (m[b[i] + x] == 0) m.erase(b[i]+x);
        }
        if (m[x] == 0) it = m.erase(it);
    }
    printf("%d\n%d", tot, b[0]);
    for (int i = 1; i < tot; ++i) printf(" %d", b[i]); printf("\n");
}
int main() {
//    freopen("in.txt", "r", stdin);
//    int T;
//    scanf("%d", &T);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
