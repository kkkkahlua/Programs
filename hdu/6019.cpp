#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#define MAXN 40010
#define MAX 10100
using namespace std;
typedef long long LL;
int n, m, k;
bool use[100010];
map<int, int> mp;
void work() {
    memset(use, 0, sizeof(use));
    mp.clear();
    int ans = 1, tot = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (!mp.count(x)) mp.insert(make_pair(x, tot++));
        if (use[mp[x]]) {
            ++ans;
            memset(use, 0, sizeof(use));
        }
        use[mp[x]] = true;
    }
    printf("%d\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
