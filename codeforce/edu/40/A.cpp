#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 110
using namespace std;
char s[maxn];
typedef long long LL;
int main() {
    int n, cnt=0;
    scanf("%d%s", &n, s);
    bool used=0;
    F(i, 1, n) {
        if (!used && ((s[i]=='U'&&s[i-1]=='R') || (s[i]=='R'&&s[i-1]=='U'))) {
            ++cnt, used = true;
        }
        else used = false;
    }
    printf("%d\n", n-cnt);
    return 0;
}
