#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[20];
int digit(int x) {
    int ret=0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int tot=0, ans=0;
    while (n) {
        ans += (a[tot++] = n % 10);
        n /= 10;
    }
    for (int i = 1; i < 10; ++i) {
        int temp = 0;
        for (int j = 0; j < tot; ++j) {
            temp += digit(a[j] * i);
        }
        ans = min(ans, temp);
    }
    printf("%d\n", ans);
    return 0;
}
