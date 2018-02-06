#include <bits/stdc++.h>
#define maxn 5010
char s[maxn];
int n;
inline int max(int a, int b) { return a > b ? a : b; }
int count1(char* s) {
    int len = strlen(s), ret = 0;
    for (int i = 0; i < len - 1; ++i) {
//        printf("%d : \n", i);
        int l1, r1, l2, r2, sum = 0, ans = 0;
        l1 = r1 = i, l2 = r2 = i + 1;
        while (true) {
            bool flag = false;
            while (l1 >= 0 && r2 < len) {
                sum += abs(s[l1] - s[r2]);
                if (sum > n) break;
                --l1, ++r2;
//                sum += abs(s[l1--] - s[r2++]);
            }
            ans = max(ans, r1 - l1);
            if (sum <= n) break;
//            printf("%d %d\n", l1, r1);
//            while (l1 >= 0 && r2 < len && sum <= n) sum += abs(s[l1--] - s[r2++]);
            sum -= abs(s[r1--] - s[l2++]);
            --l1, ++r2;
        }
        ret = max(ret, ans);
    }
//    printf("%d\n", ret);
    return ret;
}
int count2(char* s) {
    int len = strlen(s), ret = 0;
    for (int i = 1; i < len - 1; ++i) {
        int l1, r1, l2, r2, sum = 0, ans = 0;
        l1 = r1 = i - 1, l2 = r2 = i + 1;
        while (true) {
            bool flag = false;
            while (l1 >= 0 && r2 < len) {
                sum += abs(s[l1] - s[r2]);
                if (sum > n) break;
                --l1, ++r2;
//                sum += abs(s[l1--] - s[r2++]);
            }
            ans = max(ans, r1 - l1);
            if (sum <= n) break;
//            printf("%d %d\n", l1, r1);
//            while (l1 >= 0 && r2 < len && sum <= n) sum += abs(s[l1--] - s[r2++]);
            sum -= abs(s[r1--] - s[l2++]);
            --l1, ++r2;
        }
        ret = max(ret, ans);
    }
//    printf("%d\n", ret);
    return ret;
}
void work() {
    scanf("%d%s", &n, s);
    printf("%d\n", max(count1(s), count2(s)));
}
int main() {
    freopen("第六次多校标程与数据/数据/1008.in", "r", stdin);
    freopen("08.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
