#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
using namespace std;
typedef long long LL;
int cnt[256];
char dict1[] = {'B', 'l', 'b', 's', 'r'};
char dict2[] = {'u', 'a'};
char s[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%s", s);
    int len = strlen(s), ans=len;
    F(i, 0, len) ++cnt[s[i]];
    F(i, 0, 5) ans = min(ans, cnt[dict1[i]]);
    F(i, 0, 2) ans = min(ans, cnt[dict2[i]]>>1);
    printf("%d\n", ans);
    return 0;
}
