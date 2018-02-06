#include <bits/stdc++.h>
#define maxn 100010
int a[maxn], maxx[maxn], ans[maxn];
inline int max(int a, int b) { return a > b ? a: b;}
using namespace std;
struct node {
    int idx, val;
    bool operator < (node nd) const { return val > nd.val; }
    node(int a =0 ,int b =0) : idx(a), val(b) {}
};
set<node> s;
void work() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    maxx[1] = a[1];
    for (int i = 2; i <= n; ++i) maxx[i] = max(maxx[i - 1], a[i]);
    for (int i = 3; i <= n; ++i) {
        s.insert(node(i, a[i]));
//        printf("%d\n", s.begin()->val);
    }
    for (int i = 2; i <= n; ++i) {
//        printf("%d ", i);
        int max1 = maxx[i - 1];
//        printf("%d\n", s.begin()->val);
        for (set<node>::iterator it = s.begin(); it != s.end();) {
            if ((*it).idx % i == 0) {
//                printf("%d ", it->idx);
                it = s.erase(it);
            }
            else ++it;
        }
//        printf("\n");
//        printf("yes\n");
//        printf("%d\n", s.begin()->val);

        ans[i] = max(max1, s.begin()->val);
        for (int j = i + i; j <= n; j += i) s.insert(node(j, a[j]));
    }
//    printf("\n");
    printf("%d", ans[2]);
    for (int i = 3; i <= n; ++i) printf(" %d", ans[i]); printf("\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
