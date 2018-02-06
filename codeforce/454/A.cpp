#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int x1,x2,x3,x4;
    scanf("%d%d%d%d", &x1,&x2,&x3,&x4);
    int ans1 = 2*x1, ans2 = 2*x2, ans3;
    if (x3 == x4) ans3 = x3;
    else if (x3 > x4) {
        if (x3 <= 2 * x4) ans3 = x3;
        else ans3 = -1;
    }
    else {
        if (x4 <= 2 * x3) ans3 = x4;
        else ans3 = -1;
    }
    if (ans3==-1) puts("-1");
    else {
        if (2*x4<ans2) printf("%d\n%d\n%d\n", ans1,ans2,ans3);
        else puts("-1");
    }
    return 0;
}
