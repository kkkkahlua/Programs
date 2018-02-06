#include <bits/stdc++.h>
#define maxn 100010
int a[maxn], b[maxn], c[maxn];
using namespace std;
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);

    int j=n-1, k=n-1;
    LL ans=0, temp=0;
    for (int i = n-1; i >= 0; --i) {
        ans += temp;
        while (j >= 0 && b[j] > a[i]) {
            while (k >= 0 && c[k] > b[j]) --k;
            temp += (n-1-k);
            ans += (n-1-k);
            --j;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
