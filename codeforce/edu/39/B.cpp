#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
void calc(int x, int y) {
    while (true) {
        if (!x || !y) { printf("%d %d\n", x,y); return; }
        if (x>=2*y) x-=2*y;
        else if (y>=2*x) y-=2*x;
        else break;
    }
    printf("%d %d\n", x, y);
}
int main() {
    LL x, y;
    scanf("%I64d%I64d", &x, &y);
    while (true) {
        if (!x || !y) { cout <<x << " "<<y<<endl; return 0; }
        LL xx=2*x;
        y = (y-1)%xx+1;
        if (y==xx) { cout <<x << " "<<0<<endl; return 0; }
        else {
            if (x<2*y) { cout <<x <<" " <<y<<endl; return 0; }
            else x %= (2*y);
        }
    }
    return 0;
}
