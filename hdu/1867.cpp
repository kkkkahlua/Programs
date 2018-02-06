#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
char T[maxn], P[maxn], s[maxn], s1[maxn], s2[maxn];
int f[maxn], len;
bool big(char* s1, char* s2, int len) {
    for (int i = 0; i < len; ++i) {
        if (s1[i] > s2[i]) return true;
        else if (s1[i] < s2[i]) return false;
    }
    return false;
}
void getfail() {
    f[0] = f[1] = 0;
    for (int i = 1; i < len; ++i) {
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i+1] = s[i] == s[j] ? j+1 : 0;
    }
}
int cat(char* T, char* P) {
    strcpy(s, T), strcat(s, "*"), strcat(s, P);
    getfail();
    return f[len];
}
void work() {
    int n = strlen(T), m = strlen(P);
    len = n+1+m;
    int l1 = cat(T, P), l2 = cat(P, T);
    if (l1 > l2) strcpy(P+m-l1, T), printf("%s\n", P);
    else if (l1 < l2) strcpy(T+n-l2, P), printf("%s\n", T);
    else {
        strcpy(s1, T), strcpy(s1+n-l1, P);
        strcpy(s2, P), strcpy(s2+m-l2, T);
        if (big(s1, s2, n+m-l1)) printf("%s\n", s2);
        else printf("%s\n", s1);
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    while (scanf("%s%s", T, P) != EOF) work();
    return 0;
}
