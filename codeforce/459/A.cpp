#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool flag[1010];
int main() {
//    freopen("in.txt", "r", stdin);
    int a = 1, b = 1;
    flag[a] = flag[b] = true;
    while (true) {
        int c = a+b;
        if (c > 1000) break;
        flag[c] = true;
        a = b; b =c;
    }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        if (flag[i]) putchar('O');
        else putchar('o');
    }
    puts("");
    return 0;
}
