#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#define MAXN 40010
#define MAX 10100
using namespace std;
typedef long long LL;
int n, m, k, in[MAX], out[MAX];
bool paired1[MAX], paired2[MAX];
vector<int> to[MAX], from[MAX];
void work() {
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(paired1, 0, sizeof(paired1));
    memset(paired2, 0, sizeof(paired2));
    for (int i = 0; i < MAX; ++i) {
        to[i].clear(); from[i].clear();
    }

    int no = 0, mo = 0;
    scanf("%d%d", &m ,&n);
    for (int i = 0; i < k; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        ++in[b];
        to[b].push_back(a);
        from[a].push_back(b);
        ++out[a];
    }
    for (int i = 0; i < m; ++i) if (out[i] == 0) ++mo;
    for (int j = 0; j < n; ++j) if (in[j] == 0) ++no;
//    printf("%d %d %d %d\n", m, mo, n, no);
//    for (int i = 0; i < m; ++i) printf("%d ", out[i]);
//    printf("\n");
//    for (int i = 0; i < n; ++i) printf("%d ", in[i]);
//    printf("\n");
    int ans = 0;
    while (true) {
//    for (int kase = 0; kase < 10; ++kase) {
//        for (int i = 0; i < m; ++i) printf("%d ", in[i]);
//        printf("\n");
        int minn = 505, minm = 505, tot = 0, value = 0, id = -1, id2 = -1;
        for (int i = 0; i < n; ++i) {
            if (paired2[i] || in[i] == 0) continue;
//            printf("%minIn : %d %d\n", minn, i);
            if (in[i] > 0 && in[i] < minn) {
                minn = in[i]; id = i;
                minm = 505; id2 = -1;
                for (int j = 0; j < to[i].size(); ++j) {
                    int fr = to[i][j];
                    if (paired1[fr]) continue;
                    if (out[fr] < minm) {
                        minm = out[fr];
                        id2 = fr;
                    }
//                    else if (out[fr] == minm) id2 = fr;
                }
            }
            else if (in[i] == minn) {
                for (int j = 0; j < to[i].size(); ++j) {
                    int fr = to[i][j];
                    if (paired1[fr]) continue;
                    if (out[fr] < minm) {
                        minm = out[fr];
                        id2 = fr;
                    }
//                    else if (out[to[i][j]] == value) v[tot++] = to[i][j];
                }
            }
        }
        int aa = id2, bb = id;
//        printf("choose : %d %d\n", aa, bb);
        paired1[aa] = paired2[bb] = true;
        ++ans;
        for (int i = 0; i < from[aa].size(); ++i) {
//            printf("follow : %d, ", from[aa][i]);
            --in[from[aa][i]];
            if (in[from[aa][i]] == 0) ++no;
        }
//        printf("\n");
        for (int i = 0; i < to[bb].size(); ++i) {
//            printf("follow : %d, ", to[bb][i]);
            --out[to[bb][i]];
            if (out[to[bb][i]] == 0) ++mo;
        }
//        printf("\n");
        if (no == n || mo == m) break;
    }
    printf("%d\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
//    int T;
//    scanf("%d", &T);
    while (scanf("%d", &k) != EOF && k != 0) work();
    return 0;
}
