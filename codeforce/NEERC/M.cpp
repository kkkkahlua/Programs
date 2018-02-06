#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int x1, x2,y1, y2, ans;
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
    if (y1 == y2) ans = 2 * (1+abs(x1-x2)) + 4;
    else if (x1 == x2) ans = 2 * (1+abs(y1-y2)) + 4;
    else {
        if (x2 > x1) ++x2;
        else --x2;
        if (y2 > y1) ++y2;
        else --y2;
        ans = 2 * (abs(y1-y2) + abs(x1-x2));
    }
    printf("%d\n", ans);
    return 0;
}
