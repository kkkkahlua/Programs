#include <bits/stdc++.h>
#include <map>
using namespace std;
map<int, int> m;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++m[x];
    }
    auto it = m.end();
    --it;
    int sz = m.size();
    int cnt = 1;
    while (cnt <= sz && it->second < 2) {
        --it;
        ++cnt;
    }
    if (cnt > sz) printf("0\n");
    else {
        int a = it->first;
        if (it->second >= 4) printf("%lld\n", 1LL * a * a);
        else {
            --it;
            while (cnt <= sz && it->second < 2) {
                --it;
            }
            if (cnt > sz) printf("0\n");
            else {
                int b = it->first;
                printf("%lld\n", 1LL * a * b);
            }
        }
    }
    return 0;
}
