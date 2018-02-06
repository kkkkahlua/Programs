#include <bits/stdc++.h>
#define maxn 1010
#define maxl 2000010
typedef long long LL;
const LL mod = 1e9 + 7;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
int a[maxn], id[maxn]; char c;
bool dp[maxl];
void work() {
    memset(dp, 0, sizeof(dp));
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("\n%c", &c);
    int netu = a[0], nega = 0, posi = 0;
    for (int i = 1; i < n; ++i) {
        scanf(" %c", &c);
        if (c == 'L') posi += a[i];
        else if (c == 'D') nega -= a[i];
        else netu += a[i];
    }
    int le = nega - netu, ri = posi + netu;
    if (k < le || k > ri) {
        printf("no\n");
        return;
    }
    printf("yes\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
