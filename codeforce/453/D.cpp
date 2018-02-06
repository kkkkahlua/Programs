#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
typedef long long LL;
int a[maxn], b[maxn], temp[maxn];
int main() {
    int n;
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    a[0] = 1; b[0] = 0; b[1] = 1;
    int l1 = 1, l2 = 2;
    for (int i = 1; i < n; ++i) {
        temp[0] = 0;
        for (int j = 0; j < l2; ++j) temp[j+1] = b[j];
        bool flag = true;
        for (int j = 0; j < l1; ++j) {
            temp[j] += a[j];
            if (abs(temp[j]) > 1) { flag = false; break; }
        }
        if (!flag) {
            temp[0] = 0;
            for (int j = 0; j < l2; ++j) temp[j+1] = b[j];
            for (int j = 0; j < l1; ++j) temp[j] -= a[j];
        }
        swap(a, b);
        swap(b, temp);
        ++l1, ++l2;
    }
    printf("%d\n%d", l2-1, b[0]);
    for (int i = 1; i < l2; ++i) printf(" %d", b[i]); puts("");
    printf("%d\n%d", l1-1, a[0]);
    for (int i = 1; i < l1; ++i) printf(" %d", a[i]); puts("");
    return 0;
}
