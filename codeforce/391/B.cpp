#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
using namespace std;
typedef long long LL;
int cnt[maxn];
void divide(int x) {
    for (int i = 2; ; ++i) {
        if (i*i>x) break;
        if (x%i==0) {
            ++cnt[i];
            while (x%i==0) x /= i;
        }
    }
    if (x>1) ++cnt[x];
}
int main() {
//    freopen("in.txt", "r", stdin);
    int n, x, ans=0;
    scanf("%d", &n);
    F(i, 0, n) {
        scanf("%d", &x);
        divide(x);
    }
    F2(i, 2, maxn-10) ans = max(ans, cnt[i]);
    printf("%d\n", ans?ans:1);
    return 0;
}
