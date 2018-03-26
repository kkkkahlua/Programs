#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
using namespace std;
char s[maxn];
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%s", s);
    int len = strlen(s);
    char cur='a';
    F(i, 0, len) {
        if (s[i]<=cur) {
            s[i] = cur;
            if (cur=='z') { puts(s); return 0; }
            ++cur;
        }
    }
    puts("-1");
    return 0;
}
