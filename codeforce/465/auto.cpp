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
    int n = 2, m = rand()%10;
    printf("%d %d\n", n, m);
    F(i, 0, n) {
        bool flag = rand()%2;
        if (flag) printf("0 ");
        else printf("%d ", rand()%m);
    }puts("");
    F(i, 0, n) {
        bool flag = rand()%2;
        if (flag) printf("0 ");
        else printf("%d ", rand()%m);
    }puts("");
    return 0;
}
