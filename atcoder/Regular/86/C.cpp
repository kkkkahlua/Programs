#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool cmp(int a, int b) { return a > b; }
int cnt[200010];
int main() {
    int n, k, x;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &x), ++cnt[x];
    sort(cnt,cnt+n, cmp);
    int sum=0;
    for (int i = 0; i < k; ++i) sum += cnt[i];
    printf("%d\n", n-sum);
    return 0;
}
