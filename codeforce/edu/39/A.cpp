#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int main() {
    int n, x;
    scanf("%d", &n);
    int s1=0, s2=0;
    F(i, 0, n) {
        scanf("%d", &x);
        if (x>0) s1+=x;
        else s2+=x;
    }
    printf("%d\n", s1-s2);
    return 0;
}
