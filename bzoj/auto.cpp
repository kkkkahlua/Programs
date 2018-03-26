#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int main() {
    freopen("in.txt", "w", stdout);
    int n=10, m=5, lim=10;
    srand(time(NULL));
    printf("%d\n", n);
    F(i, 0, n) printf("%d ", rand()%lim+1); puts("");
    printf("%d\n", m);
    F(i, 0, m) {
        int l=rand()%n,
            r=rand()%(n-l)+l;
        printf("%d %d\n", l+1, r+1);
    }
    return 0;
}
