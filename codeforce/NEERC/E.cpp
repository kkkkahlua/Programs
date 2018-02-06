#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
typedef long long LL;
char s[maxn], rec[maxn];
int blank[maxn], n, cnt[maxn];
bool exist[maxn], exist2[maxn];
bool match(const char* s1, const char* s2) {
    memset(exist2, 0, sizeof(exist2));
    for (int i = 0; i < n; ++i) {
        if (s2[i] != '*') exist2[s2[i]] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (s2[i] == '*' && exist2[s1[i]]) return false;
    }
    for (int i = 0; i < n; ++i) {
        if (s2[i] == '*') continue;
        if (s1[i] != s2[i]) return false;
    }
    return true;
}
int main() {
    scanf("%d", &n);
    scanf("%s", s);
    int m, tot = 0;
    for (int i = 0; s[i]; ++i) if (s[i] == '*') blank[tot++] = i;
    scanf("%d", &m);
    int total = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%s", rec);
        memset(exist, 0, sizeof(exist));
        if (match(rec, s)) {
            ++total;
            for (int j = 0; j < tot; ++j) {
                exist[rec[blank[j]]] = true;
            }
            for (int j = 'a'; j <= 'z'; ++j) {
                if (exist[j]) ++cnt[j];
            }
        }
    }
    int ans = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (cnt[i] >= total) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
