#include <bits/stdc++.h>
#define maxn 2010
using namespace std;
typedef long long LL;
int a[maxn], b[maxn];
bool exist[2100010];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), exist[a[i]] = true;
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]), exist[b[i]] = true;
    int cnt=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) { if (exist[a[i]^b[j]]) ++ cnt; }
    }
    if (cnt&1) puts("Koyomi");
    else puts("Karen");
    return 0;
}
