#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int main() {
    freopen("in.txt", "w", stdout);
    int n=20;
    printf("%d\n", n);
    srand(time(NULL));
    F(i, 0, n) {
        bool flag=rand()%2;
        int x=rand()%100;
        if (flag) putchar('-');
        printf("%d ", x);
    }
    return 0;
}
