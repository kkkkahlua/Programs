#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
set<int> s;
int n, id, x;
void work() {
    s.clear(); s.insert(1000000000);
    m.clear(); m[1000000000] = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &id, &x);
        auto it = s.lower_bound(x);
        int g;
        if (it == s.begin()) g = *it;
        else if (it == s.end()) g = *(--it);
        else {
            int hi = *it; int lo = *(--it);
            g = hi - x < x - lo ? hi : lo;
        }
        printf("%d %d\n", id, m[g]);
        m[x] = id;
        s.insert(x);
    }
}
int main() {
    while (scanf("%d", &n) != EOF && n) work();
    return 0;
}
