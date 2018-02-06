#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
char s[maxn];
int cnt[256], n;
LL ans;
bool check(int i, int j) {
        ans = 0;
        for (; i>=0, j<n; ) {
            if (s[i]==s[j]) {--i, ++j; continue; }
            if (s[i]!='x'&&s[j]!='x') return 0;
            if (s[i]=='x') ++ans, --i;
            else if (s[j]=='x') ++ans, ++j;
        }
        if (i==-1) {
            ans += n-j;
            for (; j < n; ++j) if (s[j]!='x') {return 0; }
        }
        if (j==n) {
            ans += i+1;
            for (; i >= 0; --i) if (s[i]!='x') { return 0; }
        }
        return 1;
}
int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) ++cnt[s[i]];
    char ch;
    int tot = 0, odd = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (i == 'x') continue;
        if (cnt[i] & 1) ++odd;
        tot += cnt[i];
    }
    if (odd > 1) { puts("-1"); return 0;}
    if (tot == 0) { puts("0"); return 0; }
    (tot /= 2) += 1;
    int cur=0, i = 0, l=0, r=0;
    for (; i < n; ++i) {
        if (s[i] != 'x') ++cur;
        if (cur == tot-1 && !r) r = i+1;
        if (cur == tot) { l = i; break; }
    }
    if (odd) r = i, l = i+1;
    if (check(r-1, l)) printf("%d\n", ans);
    else printf("-1\n");
    return 0;
}
