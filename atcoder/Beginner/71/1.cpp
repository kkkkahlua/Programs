#include <bits/stdc++.h>
int main() {
    int x, a, b;
    scanf("%d%d%d", &x, &a, &b);
    int dist1 = abs(a - x), dist2 = abs(b - x);
    if (dist1 > dist2) printf("B\n");
    else printf("A\n");
    return 0;
}
