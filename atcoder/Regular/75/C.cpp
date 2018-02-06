#include <bits/stdc++.h>
#define maxn 110
using namespace std;
typedef long long LL;
int a[maxn];
int main() {
    int n;
    scanf("%d", &n);
    int sum=0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), sum += a[i];
    sort(a,a+n);
    if (sum % 10) printf("%d\n", sum);
    else {
        int i=0;
        for (; i < n; ++i) if (a[i] % 10) break;
        if (i == n) puts("0");
        else printf("%d\n", sum-a[i]);
    }
    return 0;
}
