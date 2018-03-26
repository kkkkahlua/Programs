#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int main() {
    int n;
    scanf("%d", &n);
    int cnt=0;
    F(i, 1, n) {
        if (n %i==0) ++cnt;
    }
    printf("%d\n", cnt);
    return 0;
}
