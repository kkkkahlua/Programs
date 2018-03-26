#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define inf 1000000000
#define maxn 100010
using namespace std;
char s[maxn];
int a[maxn];
typedef long long LL;
int minn(int p) { int ret = a[p]; F(i, p+1, p+5) ret = min(ret, a[i]); return ret; }
int maxx(int p) { int ret = a[p]; F(i, p+1, p+5) ret = max(ret, a[i]); return ret; }
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    F(i, 0, n) scanf("%d", &a[i]);
    scanf("%s", s);
    bool flag = false;
    int r = inf, l = -inf;
    F(i, 0, n) {
        if (s[i]-'0'!=flag) {
            if (flag) r = min(r, minn(i-4)-1);
            else l = max(l, maxx(i-4)+1);
            flag = !flag;
        }
    }
    printf("%d %d\n", l, r);
    return 0;
}
