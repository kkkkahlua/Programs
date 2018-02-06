#include <bits/stdc++.h>
#define eps 1e-8
void work() {
    double r, x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf%lf", &r, &x1, &y1, &x2, &y2);
    double d0 = sqrt(pow(x1, 2) + pow(y1, 2));
    if (fabs(d0) < eps) {
        printf("%.7f\n", 2 * r);
        return;
    }
    double k = r * r / (d0 * d0);
    double x3 = x1 * k, x4 = x2 * k, y3 = y1 * k, y4 = y2 * k;
    double mx = (x3+x4)/2, my = (y3+y4)/2, ans;
    double d = sqrt(pow(mx,2)+pow(my,2));
//    printf("%.7f %.7f\n", k, d);
    if (d <= r) {
        double dist = sqrt(pow(x3 - x4, 2) + pow(y3 - y4, 2));
        ans = dist * d0 / r;
    }
    else {
        double kk = r / d;
        double smx = mx * kk, smy = my * kk;
        ans = 2 *sqrt(pow(smx - x1, 2) + pow(smy - y1, 2));
    }
    printf("%.7f\n", ans);
}
int main() {
//    freopen("第六次多校标程与数据/数据/1002.in", "r", stdin);
//    freopen("02.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
