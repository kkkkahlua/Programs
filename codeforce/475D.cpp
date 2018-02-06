#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
int a[maxn];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
struct node { int x, p; };
map<int, LL> mp;
vector<node> v[2];
int main() {
    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        bool me = i & 1,
            op = !me;
        v[me].clear();
        v[me].push_back({a[i], i});
        int last = a[i];
        for (auto nd : v[op]) {
            int temp = gcd(nd.x, a[i]);
            if (temp == last) v[me][v[me].size()-1].p = nd.p;
            else v[me].push_back({temp, nd.p}), last = temp;
        }
        int now = i;
        for (auto nd : v[me]) {
            int pre = nd.p;
            mp[nd.x] += now - pre + 1;
            now = pre - 1;
        }
    }
    int q, x;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        printf("%I64d\n", mp[x]);
    }
    return 0;
}
