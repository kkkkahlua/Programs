#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
using namespace std;
typedef long long LL;
char s[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int x, y, cnt=0;
    bool flag;
    if (s[0]=='R') x=1, y=0, flag=0;
    else x=0, y=1, flag=1;
    F(i, 1, n) {
        char ch = s[i];
        if (ch=='R') {
            ++x;
            if (x>y && flag) flag = !flag, ++cnt;
        }
        else {
            ++y;
            if (x<y && !flag) flag = !flag, ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
