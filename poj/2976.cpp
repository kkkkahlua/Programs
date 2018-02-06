#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1010
const double eps = 1e-7;
using namespace std;
int a[maxn], b[maxn], n, k;
double d[maxn];
bool check(double x) {
//    printf("%f\n", x);
    for (int i = 0; i < n; ++i) d[i] = (double)a[i] - x * b[i];
    sort(d, d + n);
    double sum = 0;
    for (int i = k; i < n; ++i) sum += d[i];
    if (sum >= 0) return true;
    return false;
}
void work() {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    double l = 0, r = 1.0, mid;
    while (r - l > eps) {
        mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%.0f\n", mid * 100);
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &k) != EOF && n + k) work();
    return 0;
}
