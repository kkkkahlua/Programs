#include <bits/stdc++.h>
#define eps 1e-5
#define eps2 1e-4
#define pi acos(-1.0)
inline double abs(double x) { return x > 0 ? x : -x; }
inline double min(double a, double b) { return a < b? a: b;}
double p, q, alp;
double rec[110][110];
double calc(double sita) {
    double t3 = cos(sita), t4 = cos(alp-sita);
    return sqrt(p - q * t3) + sqrt(p - q * t4);
}
double find(double sita1, double sita2) {
    double l = sita1, r = sita2, d1, d2;
    while (fabs(l-r) > eps) {
        double mid = (l+r)/2,
            midmid = (l+mid)/2;
        d1 = calc(mid), d2 = calc(midmid);
        if (d1 < d2) l = mid;
        else r = midmid;
    }
    return d1;
}
void init(int r, int r2) {
    int x1 = 0, y1 = r2, x2 = 0, y2 = -r2;
    double d = r2, d2 = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))/2;
    p = d*d+r*r, q = 2*d*r, alp = pi/2;
    double ans;
    double val1 = calc(0), val2 = calc(eps);
    if (val1 < val2) ans = val1;
    else ans = find(0, alp/2);
    rec[r][r2] = ans;
}
//void work(int R, int r) {
//    double r; int x1, y1, x2, y2;
//    scanf("%lf%d%d%d%d", &r, &x1, &y1, &x2, &y2);
//    double d = sqrt(x1*x1+y1*y1), d2 = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))/2;
//    p = d*d+r*r, q = 2*d*r, alp = asin(d2/d)*2;
//    double ans;
//    double val1 = calc(0), val2 = calc(eps);
//    if (val1 < val2) ans = val1;
//    else ans = find(0, alp/2);
//    printf("%.7f\n", ans);
//}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("22.out", "w", stdout);
    int R = 100;
    for (int R = 100; R >= 1; --R) {
        for (int r = R; r >= 1; --r) {
            init(R, r);
        }
    }
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) printf("%.7f,", rec[i][j]);
    }
//    int T;
//    scanf("%d", &T);
//    while (T--) work();
    return 0;
}
