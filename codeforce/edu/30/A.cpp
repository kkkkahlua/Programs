#include <bits/stdc++.h>
#define maxn 110
using namespace std;
int a[maxn];
typedef long long LL;
int main() {
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int sum = k * x;
    for (int i = 0; i < n-k; ++i) sum += a[i];
    printf("%d\n", sum);
    return 0;
}
