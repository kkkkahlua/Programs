#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
#include <cstring>
#define maxn 100010
using namespace std;
struct Node {
    int k, a, id;
}node[maxn];
struct TreeNode {
    int fa, lson, rson;
};
stack<int> st;
TreeNode ans[maxn], tree[maxn];
int n, f[maxn];
bool cmp(Node u, Node v) { return u.k < v.k; }
void work() {
    memset(tree, 0, sizeof(tree));
    while (!st.empty()) st.pop();
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &node[i].k, &node[i].a);
        node[i].id = i;
    }
    sort(node + 1, node + n + 1, cmp);
    for (int i = 1; i <= n; ++i) f[i] = node[i].id;
    st.push(1);
    for (int i = 2; i <= n; ++i) {
        int x = st.top();
        if (node[x].a < node[i].a) {
            tree[x].rson = i;
            tree[i].fa = x;
        }
        else {
            int x;
            while (!st.empty() && node[st.top()].a > node[i].a) {
                x = st.top();
                st.pop();
            }
            tree[x].fa = i;
            tree[i].lson = x;
            if (!st.empty()) {
                int y = st.top();
                tree[y].rson = i;
                tree[i].fa = y;
            }
        }
        st.push(i);
    }
//    for (int i = 1; i <= n; ++i) printf("%d ", f[i]); printf("\n");
    for (int i = 1; i <= n; ++i) {
        ans[f[i]].fa = f[tree[i].fa];
        ans[f[i]].lson = f[tree[i].lson];
        ans[f[i]].rson = f[tree[i].rson];
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i) {
        printf("%d %d %d\n", ans[i].fa, ans[i].lson, ans[i].rson);
    }
}
int main() {
    freopen("2201.in", "r", stdin);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
