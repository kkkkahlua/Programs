#include <bits/stdc++.h>
#define maxn 500010
using namespace std;
typedef long long LL;
char s[maxn];
int cnt[256], n;
LL ans;
struct node {
    char ch;
    int cnt;
}a[maxn], b[maxn];
bool check(int i, int j) {
    int cnt1 = 0, cnt2 = 0, tot1 = 0, tot2 = 0;
    for (; i >= 0; --i) {
        if (s[i] == 'x') ++cnt1;
        else a[tot1++] = {s[i],cnt1}, cnt1 = 0;
    }
    for (; j < n; ++j) {
        if (s[j] == 'x') ++cnt2;
        else b[tot2++] = {s[j],cnt2}, cnt2 = 0;
    }
    if (tot1 != tot2) return false;
    ans = 0;
    for (int i = 0; i < tot1; ++i) {
        if (a[i].ch != b[i].ch) return false;
        ans += abs(a[i].cnt-b[i].cnt);
    }
    ans += abs(cnt1-cnt2);
    return true;
}
int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) ++cnt[s[i]];
    char ch; int num=0;
    for (char i = 'a'; i <= 'z'; ++i) if (i!='x'&&(cnt[i]&1)) ++num, ch = i;
    if (num > 1) { printf("-1\n"); return 0; }

    int p;
    if (num == 1) {
        int hf = cnt[ch]/2+1, pst=0;

        int i = 0;
        for (; i < n; ++i) {
            if (s[i] == ch && pst < hf) ++pst;
            if (pst == hf) break;
        }
        if (check(i-1, i+1)) printf("%lld\n", ans);
        else printf("-1\n");
    }
    else {
        int tot = 0;
        for (char i = 'a'; i <= 'z'; ++i) if (i!='x')tot += cnt[i];
        if (tot==0) { puts("0"); return 0; }
        tot /= 2;
        int i = 0, pst = 0;
        for (; i < n; ++i) {
            if (s[i] != 'x' && pst < tot) ++pst;
            if (pst == tot) break;
        }
        int p = i+1;
        while (p<n && s[p]=='x') ++p;
        if (check(i, p)) printf("%lld\n", ans);
        else printf("-1\n");
    }
    return 0;
}
