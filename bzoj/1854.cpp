#include <bits/stdc++.h>
#define maxn 10000
using namespace std;
typedef long long LL;
bool vis[maxn+10];
int fa[maxn+10];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= maxn; ++i) fa[i] = i;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        x = find(x), y = find(y);
        if (x == y) vis[x] = true;
        else {
            if (x > y) swap(x, y);
            if (vis[x]) vis[y] = true;
            else vis[x] = true;
            fa[x] = y;
        }
    }
    int i=1;
    for (; i <= maxn && vis[i]; ++i);
    printf("%d\n", i-1);
    return 0;
}
