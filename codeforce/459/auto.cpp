#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int n = 100;

    for (int i = 0; i < n; ++i) {
        int x = rand() % 3;
        if (x==0) putchar('(');
        else if (x==1) putchar(')');
        else putchar('?');
    }
    puts("");
    return 0;
}
