#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int main() {
    freopen("in.txt", "w", stdout);
    int n=10000, m=1000, lim=100;
    srand(time(NULL));
    printf("%d %d\n", n, m);
    F(i, 0, n) printf("%d ", rand()%lim); puts("");
    F(i, 0, m) {
        int op=rand()%2+1,
            l=rand()%n,
            r=rand()%(n-l)+l;
        printf("%d %d %d\n", op, l+1, r+1);
    }
    return 0;
}
