#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int main() {
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int T=1, len=1000, x;
    puts("1");
    do {
        x=rand()%10;
    }while (!x);
    putchar('0'+x);
    F(i, 1, 10) {
        x=rand()%10;
        putchar('0'+x);
    }
    puts("");
    return 0;
}
