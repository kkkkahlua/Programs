#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        n %= 3;
        if (n) puts("Kiki");
        else puts("Cici");
    }
    return 0;
}
