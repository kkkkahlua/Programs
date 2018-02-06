#include <bits/stdc++.h>
#define eps 1e-5
#define eps2 1e-4
#define pi acos(-1.0)
inline double abs(double x) { return x > 0 ? x : -x; }
inline double min(double a, double b) { return a < b? a: b;}
void work() {
    double r; int x1, y1, x2, y2;
    scanf("%lf%d%d%d%d", &r, &x1, &y1, &x2, &y2);
    double d = sqrt(x1*x1+y1*y1), d2 = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))/2;
    double p = d*d+r*r, q = 2*d*r, alp = asin(d2/d)*2;
//    printf("%.3f", sin(pi/6));
//    printf("%.3f\n", alp);
    double ret = sqrt(p - q * 1) + sqrt(p - q * cos(alp)), minn = 0x3f3f3f3f;
    for (double sita = 0; sita < alp; sita += eps) {
        double t1 = sin(sita), t2 = sin(alp - sita), t3 = cos(sita), t4 = cos(alp - sita);
        double le = t1 * t1 * (p - q * t4);
        double ri = t2 * t2 * (p - q * t3);
//        printf("%.3f %.3f %.3f %.3f %.3f %.3f\n", le, ri, p - q * t4, t4 , alp, sita);
        minn = min(minn,abs(le - ri));

        if (abs(le - ri) < eps2) {
            double ans = sqrt(p - q * t3) + sqrt(p - q * t4);
            ret = min(ans, ret);
//            printf("%.3f\n", minn);

//            printf("%.3f %.3f\n", sita, ret);
        }
    }
//    printf("%.3f\n", minn);
    printf("%.7f\n", ret);
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("2.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
