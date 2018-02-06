#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
bool exist[maxn], vis[maxn];
int a[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int cnt=0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (!exist[a[i]]) ++cnt, exist[a[i]] = true;
    }
    int num=0;
    for (int i = n-1; i >= 0; --i) {
        if (!vis[a[i]]) ++num, vis[a[i]] = true;
        if (num == cnt) { printf("%d", a[i]); exit(0); }
    }
    return 0;
}
