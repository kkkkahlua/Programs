#include <bits/stdc++.h>
#define maxn 110
using namespace std;
struct span { int l, r; }span[maxn];
int st1[maxn], st2[maxn], color[maxn][maxn];
struct pos {
    int x, y;
    pos(int a = 0, int b = 0) : x(a), y(b) {}
};
vector<pos> col[maxn * maxn];
vector<int> line[maxn];
typedef long long LL;
void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m * n; ++i) col[i].clear();
    memset(span, 0, sizeof(span));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int temp;
            scanf("%d", &temp);
            color[i][j] = temp;
            col[temp].push_back(pos(i, j));
        }
    }
    LL ans = 0;
    for (int c = 0; c < m * n; ++c) {
        if (col[c].empty()) continue;
        for (int i = 0; i < n; ++i) line[i].clear();
        for (auto ele : col[c]) {
            line[ele.x].push_back(ele.y);
        }
        for (auto ele : col[c]) {
            int tot1 = 0, tot2 = 0, i = ele.x, j = ele.y;

            span[i].r = m - j;

            auto it = lower_bound(line[i].begin(), line[i].end(), j);
            if (it == line[i].begin()) span[i].l = j + 1;
            else span[i].l = j - *(it - 1);
            st2[tot2++] = span[i].l;

            for (int k = i - 1; k >= 0; --k) {
                auto it = lower_bound(line[k].begin(), line[k].end(), j);
                int diff1;
                if (it == line[k].end()) diff1 = m - j;
                else diff1 = *it - j;
                if (diff1 == 0) {
                    span[k].r = 0;
                    break;
                }
                while (tot1 > 0 && diff1 < st1[tot1 - 1]) --tot1;
                st1[tot1++] = diff1;
                span[k].r = st1[0];

                int diff2;
                if (it == line[k].begin()) diff2 = j + 1;
                else diff2 = j - *(it - 1);
                if (diff2 == 0) {
                    span[k].l = 0;
                    break;
                }
                while (tot2 > 0 && diff2 < st2[tot2 - 1]) --tot2;
                st2[tot2++] = diff2;
                span[k].l = st2[0];
            }
//            printf("i j : %d %d\n", i, j);
            for (int k = i; k >= 0; --k) {
//                printf("%d %d %d\n", k, span[k].l, span[k].r);

                if (span[k].l == 0 || span[k].r == 0) break;
                ans += (LL)span[k].l * span[k].r * (n - i);
            }
        }
    }
    int num = (n * (n + 1) >> 1) * (m * (m + 1) >> 1);
//    printf("%lld %d\n", ans, num);
    printf("%.9f\n", (double)ans / num);
}
int main() {
    freopen("多校联合第二场数据和标程/数据/1008.in", "r", stdin);
    freopen("08.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
