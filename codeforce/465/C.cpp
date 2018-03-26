#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    double R,x1,y1,x2,y2;
    scanf("%lf%lf%lf%lf%lf", &R, &x1, &y1, &x2, &y2);
    double d2 = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    if (x1==x2&&y1==y2) {
        printf("%.12f %.12f %.12f\n", x1, y1+R/2, R/2);
    }
    else if (d2>=R) {
        printf("%.12f %.12f %.12f\n", x1, y1, R);
    }
    else {
        double r = (R+d2)/2,
            d1 = R - r;
        double yy = y1+d1*(y1-y2)/d2,
            xx = x1+d1*(x1-x2)/d2;
        printf("%.12f %.12f %.12f\n", xx, yy, r);
    }
    return 0;
}
