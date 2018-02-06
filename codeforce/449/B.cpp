#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int k, p, ans[20];
LL num(int* ans, int tot) {
    LL ret = 0;
    for (int i = (tot<<1); i >= 1; --i) (ret *= 10) += ans[i];
    return ret % p;
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d %d", &k, &p);
    ans[2] = ans[1] = 1;
    LL sum = 11 % p, tot = 1;
    for (int i = 1; i < k; ++i) {
        int temp = tot;
        while (temp >= 1 && ans[temp] == 9) {
            ans[(tot<<1)-temp+1] = ans[temp] = 0;
            --temp;
        }
        if (!temp) {
            ++tot;
            ans[1] = ans[tot<<1] = 1;
        }
        else ++ans[temp], ++ans[(tot<<1)-temp+1];
        (sum += num(ans, tot)) %= p;
    }
    printf("%I64d\n", sum);
    return 0;
}
