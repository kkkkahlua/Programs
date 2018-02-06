#include <bits/stdc++.h>
typedef long long LL;
int main() {
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    LL n = rand() *1000 + rand()*100+rand()*10+rand();
    LL k = rand()*100+rand()*10+rand();
    LL l = rand();
    LL r = l + rand() * 1000 + rand() * 100 + rand() * 10;
    printf("%lld %lld %lld %lld\n", n, k, l, r);
    return 0;
}
