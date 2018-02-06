#include <bits/stdc++.h>
#define maxn 100010
int fa[maxn], sz[maxn], val[maxn];
using namespace std;
map<int, int> mp;
struct node {
    int key, val, sz;
    node* ch[2];
    node() { sz = 0, key = INT_MAX; }
    node(int x);
    void update() { sz = ch[0]->sz + ch[1]->sz + 1; }
}*null = new node;
node::node(int x) { val = x, key = rand(), sz = 1, ch[0] = ch[1] = null; }
struct Treap {
    node* root;
    Treap() { root = null; }
    void rotate(node*& t, bool d) {
        node* p = t->ch[d];
        t->ch[d] = p->ch[!d];
        p->ch[!d] = t;
        t->update(), p->update();
        t = p;
    }
    void insert(node*& t, int x) {
        if (t == null) { t = new node(x); return; }
        bool dir = x > t->val;
        insert(t->ch[dir], x);
        if (t->ch[dir]->key < t->key) rotate(t, dir);
        else t->update();
    }
    void insert(int x) { insert(root, x); }
    void mergeto(node*& t, Treap* tr) {
        if (t->ch[0] != null) mergeto(t->ch[0], tr);
        if (t->ch[1] != null) mergeto(t->ch[1], tr);
        tr->insert(t->val);
        delete t; t = null;
    }
    void mergeto(Treap* tr) { mergeto(root, tr); }
    int calckth(int k) {
        if (k <= 0 || k > root->sz) return INT_MIN;
        bool dir;
        for (node* t = root; t != null; t = t->ch[dir]) {
            int cnt = t->ch[0]->sz;
            if (k == cnt+1) return t->val;
            else if (k <= cnt) dir = 0;
            else dir = 1, k -= (cnt+1);
        }
    }
}**treap = new Treap*[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unionn1(int& x, int& y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    fa[x] = y; sz[y] += sz[x];
}
void unionn2(int x, int y) {
    unionn1(x, y);
    treap[x]->mergeto(treap[y]);
}
int n, m, q;
void work() {
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val[i]);
        mp[val[i]] = i;
    }
    for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        unionn1(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        treap[i] = new Treap();
        fa[i] = find(i);
    }
    for (int i = 1; i <= n; ++i) {
        treap[fa[i]]->insert(val[i]);
    }
    scanf("%d", &q);
    while (q--) {
        char c; int x, y;
        scanf("\n%c%d%d", &c, &x, &y);
        if (c == 'Q') {
            int ans = treap[find(x)]->calckth(y);
            printf("%d\n", ans == INT_MIN ? -1 : mp[ans]);
        }
        else unionn2(x, y);
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
