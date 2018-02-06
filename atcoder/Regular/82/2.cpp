#include <bits/stdc++.h>
#define maxn 100010
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
vector<int> v;
int a[maxn], pre[maxn], succ[maxn], b[maxn];
bool flag[maxn];
int main() {
    int n;
    scanf("%d", &n);
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == i && !flag[i]) {
            if (a[i+1] == a[i+1]) {
                ++cnt;
                flag[i+1] = true;
            }
            else ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
