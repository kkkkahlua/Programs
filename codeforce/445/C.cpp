#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
int p[maxn], b[maxn];
int main() {
    int n;
    scanf("%d", &n);
    p[0] = 0; b[0] = 0;
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        if (p[b[x]] == x) b[i] = b[x];
        else b[i] = ++cnt;
        p[b[i]] = i;
    }
    printf("%d\n", cnt+1);
    return 0;
}
