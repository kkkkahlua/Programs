#include <bits/stdc++.h>
#define maxn 100010
int a[maxn], maxx[maxn], ans[maxn];
inline int max(int a, int b) { return a > b ? a: b;}
using namespace std;
map<int, int> m;
void work() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    maxx[1] = a[1];
    for (int i = 2; i <= n; ++i) maxx[i] = max(maxx[i - 1], a[i]);
    for (int i = 2; i <= n; ++i) {
        if (m.find(a[i]) != m.end()) ++m[a[i]];
        else m.insert(make_pair(a[i], 1));
    }
//        printf("sz : %d : ", m.size());
//        for (auto x : m) printf("%d ", x); printf("\n");
    for (int i = 2; i <= n; ++i) {
        int max1 = maxx[i - 1];

        for (int j = i; j <= n; j += i) {
            --m[a[j]];
//            printf("%d : %d\n", j, m[a[j]]);
            if (m[a[j]] == 0) m.erase(a[j]);
//            if (m.find(4) != m.end()) printf("%d : yes\n", j);
        }
//        printf("sz : %d : ", m.size());
//        for (auto x : m) printf("%d ", x); printf("\n");
//        printf("yes\n");
        if (m.empty()) ans[i] = max1;
        else {
            auto it = m.end();
            --it;
//            printf("%d %d\n", i, it->first);
            ans[i] = max(max1, it->first);
        }
        for (int j = i + i; j <= n; j += i) {
            if (m.find(a[j]) != m.end()) ++m[a[j]];
            else m.insert(make_pair(a[j], 1));
        }
    }
//    printf("\n");
    printf("%d", ans[2]);
    for (int i = 3; i <= n; ++i) printf(" %d", ans[i]); printf("\n");
}
int main() {
    freopen("in.txt", "r" ,stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
