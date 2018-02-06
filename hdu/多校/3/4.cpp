#include <bits/stdc++.h>
#define maxn 500010
typedef long long LL;
LL cnt[31][2];
int trie[maxn * 31][2], tot, a[500010], sz[maxn * 31][2][2];
void ins(int x) {
    int rt = 0;
    for (int i = 29; i >= 0; --i) {
        int bit = (x >> i) & 1;
        if (!trie[rt][bit]) trie[rt][bit] = ++tot;
        ++sz[rt][1][bit];
        rt = trie[rt][bit];
    }
}
LL query(int x) {
    int rt = 0;
    LL ans = 0;
    for (int i = 29; i >= 0; --i) {
        int bit = (x >> i) & 1;
        ans += cnt[i][bit];
        cnt[i][bit] += sz[rt][1][bit ^ 1];
        cnt[i][bit ^ 1] -= sz[rt][0][bit ^ 1];
//        printf("%d : %lld %lld\n", i, cnt[i][0], cnt[i][1]);
        --sz[rt][1][bit];
        ++sz[rt][0][bit];
        rt = trie[rt][bit];
    }
    return ans;
}
void work() {
    int n; tot = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(trie, 0, sizeof(trie));
    memset(sz, 0, sizeof(sz));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ins(a[i]);
    }
//    for (int i = 0; i <= 10; ++i)
//        printf("%d : %lld %lld\n", i, sz[i][1][0], sz[i][1][1]);
    LL ans = 0;
    for (int i = 0; i < n; ++i) ans += query(a[i]);
    printf("%lld\n", ans);
}
int main() {
    freopen("多校第三场数据和标程/数据/1004.in", "r", stdin);
    freopen("04.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
