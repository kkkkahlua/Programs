#include <bits/stdc++.h>
#define range 2000
#define n 10
#define k 5
int a[n + 10];
int main() {
    freopen("2566.in", "w", stdout);
    srand(time(NULL));
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int sign = (rand() & 1 ? 1 : -1);
        a[i] = sign * rand() % range;
        sum += a[i];
    }
    sum = abs(sum);
    printf("%d %d\n", n, k);
    for (int i = 0; i < n; ++i) printf("%d ", a[i]); printf("\n");
    for (int i = 0; i < k; ++i) printf("%d ", rand() % sum); printf("\n");
    printf("0 0\n");
    return 0;
}
