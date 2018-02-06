#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> v;
int a[maxn], cnt[maxn];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
        ++cnt[a[i]+1];
        ++cnt[a[i]+2];
    }
    int p = 0;
    for (int i = 1; i < maxn; ++i) {
        if (cnt[i] > cnt[p]) p = i;
    }
    printf("%d\n", cnt[p]);
    return 0;
}
