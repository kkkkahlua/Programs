#include <bits/stdc++.h>
#include <vector>
#include <set>
#define maxn 100010
using namespace std;
vector<int> ans;
set<int> st[maxn];
int fa[maxn], sz[maxn];
int findfa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = findfa(fa[x]);
}
void init() { for (int i = 1; i < maxn; ++i) { st[i].clear(); fa[i] = i; sz[i] = 1; } }
void add(int& le, int ri) { ans.push_back(ri - le + 1); le = ri + 1; init(); }
int main() {
    int T;
    scanf("%d", &T);
    int le = 0;
    init();
    for (int ri = 0; ri < T; ++ri) {
        int i, j, e;
        scanf("%d%d%d", &i, &j, &e);
        if (e) {
            int fai = findfa(i), faj = findfa(j);
            if (fai == faj) continue;
            if (st[fai].find(faj) != st[fai].end()) { add(le, ri); continue; }
            if (sz[fai] > sz[faj]) swap(fai, faj);
            fa[fai] = faj; sz[faj] += sz[fai];
            for (auto x : st[fai]) {
                st[faj].insert(x);
                st[x].insert(faj);
            }
        }
        else {
            int fai = findfa(i), faj = findfa(j);
            if (fai == faj) { add(le, ri); continue; }
            st[fai].insert(faj);
            st[faj].insert(fai);
        }
    }
    printf("%d\n", ans.size());
    for (auto x : ans) printf("%d\n", x);
    return 0;
}
