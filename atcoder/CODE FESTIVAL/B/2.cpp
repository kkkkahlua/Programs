#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
map<int, int> mp;
#define maxn 200010
int a[maxn];
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++mp[x];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
        if (mp.find(a[i]) == mp.end()) { printf("NO\n"); return 0; }
        --mp[a[i]]; if (mp[a[i]] == 0) mp.erase(a[i]);
    }
    printf("YES\n");

    return 0;
}
