#include <bits/stdc++.h>
#define N 62
#define maxn 400010
char s[maxn];
int cnt[70], fac[700], n;
char ans[maxn];
using namespace std;
typedef long long LL;
int idx(char c) {
    if (islower(c)) return c-'a';
    else if (isupper(c)) return c-'A'+26;
    else return c-'0'+52;
}
char charat(int i) {
    if (i < 26) return 'a'+i;
    else if (i < 52) return 'A'+i-26;
    else return '0'+i-52;
}
void print1() {
    puts("1");
    int p = 0;
    for (int i = 0; i < N; ++i) {
        if (cnt[i] & 1) --cnt[i], ans[n/2] = charat(i);
        while (cnt[i]) {
            ans[p] = ans[n-1-p] = charat(i);
            ++p, cnt[i] -= 2;
        }
    }
    ans[n] = '\0';
    puts(ans);
    exit(0);
}
void printn() {
    printf("%d\n", n);
    putchar(s[0]);
    for (int i = 1; i < n; ++i) printf(" %c", s[i]); puts("");
    exit(0);
}
void print(int num, int sz) {
    printf("%d\n", num);
    for (int i = 0; i < num-1; ++i) {
        char temp = ans[i*sz+sz];
        ans[i*sz+sz] = '\0';
        printf("%s ", ans+i*sz);
        ans[i*sz+sz] = temp;
    }
    printf("%s\n", ans+sz*(num-1));
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i) ++cnt[idx(s[i])];
    int k = 0;
    for (int i = 0; i < N; ++i) if (cnt[i]&1) ++k;
    if (!k || k==1) print1();

    int tot = 0;
    for (int i = 1; i*i <= n; ++i) {
        if (i*i == n) fac[tot++] = i;
        else {
            if (n % i == 0) fac[tot++] = i, fac[tot++] = n/i;
        }
    }
    sort(fac, fac+tot);
    int p = lower_bound(fac, fac+tot, k) - fac;
    for (; p < tot; ++p) {
        if (!((fac[p]-k)&1) && ((n/fac[p])&1)) break;
    }
    int sz = n/fac[p], curm = 0, cur = 0;
    if (sz == 1) printn();

    for (int i = 0; i < N; ++i) {
        if (cnt[i] & 1) ans[curm*sz+sz/2] = charat(i), ++curm, --cnt[i];
    }
    for (int i = 0; i < N; ++i) {
        if (curm == fac[p]) break;
        while (cnt[i] && curm < fac[p]) ans[curm*sz+sz/2] = charat(i), ++curm, --cnt[i];
    }

    int l = 0, r = sz-1;
    for (int i = 0; i < N; ++i) {
        if (cur == fac[p]) break;
        if (l == sz/2) ++cur, l = 0, r = sz-1;
        while (cnt[i]) {
            if (l == sz/2) ++cur, l = 0, r = sz-1;
            ans[cur*sz+l++] = ans[cur*sz+r--] = charat(i);
            cnt[i] -= 2;
        }
    }

    print(fac[p], sz);

    return 0;
}
