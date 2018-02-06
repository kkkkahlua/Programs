#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bitset<10> x;
int ans[10];
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    memset(ans, -1, sizeof ans);
    while (n--) {
        char ch;
        scanf("\n%c%d", &ch, &x);
        for (int i = 0; i < 10; ++i) {
            if (x[i]) {
                if (ch == '|') ans[i] = 1;
                else if (ch == '^') {
                    if (ans[i]==0 || ans[i]==1) ans[i] = !ans[i];
                    else ans[i] = -3-ans[i];
                }
            }
            else {
                if (ch == '&') ans[i] = 0;
            }
        }
    }
    bitset<10> andd, orr, xorr;
    for (int i = 0; i < 10; ++i) andd[i] = 1, orr[i] = 0;
    for (int i = 0; i < 10; ++i) {
        if (!ans[i]) andd[i] = 0;
        else if (ans[i]==1) orr[i] = 1;
        else if (ans[i]==-2) xorr[i] = 1;
    }
    printf("%d\n", 3);
    printf("& %d\n", andd);
    printf("| %d\n", orr);
    printf("^ %d\n", xorr);
    return 0;
}
