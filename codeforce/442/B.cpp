#include <bits/stdc++.h>
#define maxn 5010
char s[maxn];
int a[maxn], b[maxn];
using namespace std;
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%s", s+1);
    int len = strlen(s+1);
    for (int i = 1; i <= len; ++i) {
        a[i] = a[i-1], b[i] = b[i-1];
        if (s[i]=='a') ++a[i];
        else ++b[i];
    }
//    for (int i = 1; i <= len; ++i) printf("%d %d\n", a[i], b[i]);
    int ans = len+1;
    for (int i = 1; i <= len+1; ++i) {
        for (int j = i; j <= len+1; ++j) {
            int x1=0, x2=0, x3=0;
            if (i > 1) x1 = b[i-1]-b[0];
            if (j > i) x2 = a[j-1]-a[i-1];
            if (j <= len) x3 = b[len]-b[j-1];
            ans = min(ans,x1+x2+x3);
//            printf("%d %d %d %d %d\n", i, j, x1, x2, x3);
        }
    }
    printf("%d\n", len-ans);
    return 0;
}
