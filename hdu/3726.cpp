#include <bits/stdc++.h>
#define maxn 60010
#define maxm 60010
#define maxop 500010
using namespace std;
typedef long long LL;
int val[maxn], fa[maxn], sz[maxn], u[maxn], v[maxn], n, m, tot, ne[maxn], ccc;
bool vis[maxn], flag[maxn];
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0) : to(a), ne(b) {}
}edge[maxm * 2];
struct Oper { int t, x, y; Oper(int _t=0, int _a=0, int _b=0) : t(_t), x(_a), y(_b) {}} oper[maxop];
struct node {
    node* ch[2];
    int sz, key, val;
    node() { sz = 0; key = INT_MAX; }
    node(int x);
    update() { sz = ch[0]->sz+ch[1]->sz+1; }
}*null = new node;
node::node(int x) {
    sz = 1, key = rand(), val = x;
    ch[0] = ch[1] = null;
}
struct treap {
    node* root;
    treap() { root = null; }
    void rotate(node*& t, bool d) {
        node* p = t->ch[d];
        t->ch[d] = p->ch[!d];
        p->ch[!d] = t;
        t->update(), p->update();
        t = p;
    }
    void insert(node*& t, int x) {
        if (t == null) {
            t = new node(x);
            return;
        }
        bool d = x > t->val;
        insert(t->ch[d], x);
        if (t->ch[d]->key < t->key) rotate(t, d);
        else t->update();
    }
    void erase(node*& t, int x) {
        if (t == null) return;
        if (t->val == x) {
            bool d = t->ch[1]->key < t->ch[0]->key;
            if (t->ch[d] == null) { delete t; t = null; return; }
            if (t->ch[!d] == null) { node* p = t->ch[d]; delete t; t = p; return; }
            rotate(t, d);
            erase(t->ch[!d], x);
            t->update();
            return;
        }
        bool d = x > t->val;
        erase(t->ch[d], x);
        t->update();
    }
    void replace(int x, int y) {
        erase(x); insert(y);
    }
    int calckth(int k) {
        if (k < 0 || k > root->sz) return 0;
        k = root->sz-k+1;
        bool d;
        for (node* t = root; t != null; t = t->ch[d]) {
            int cnt = t->ch[0]->sz;
            if (k == cnt+1) return t->val;
            else if (k <= cnt) d = 0;
            else d = 1, k -= (cnt+1);
        }
    }
    void mergeto(node*& t, treap* tr) {
        if (t->ch[0] != null) mergeto(t->ch[0], tr);
        if (t->ch[1] != null) mergeto(t->ch[1], tr);
        tr->insert(t->val);
        delete t; t = null;
    }
    void mergeto(treap* T) { mergeto(root, T); }
    void erase(int x) { erase(root, x); }
    void insert(int x) { insert(root, x); }
    int size() { return root->sz; }
}** Treap = new treap *[maxn];
void addEdge(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
void dfs(int u, int f) {
    vis[u] = true, fa[u] = f;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (vis[v]) continue;
        dfs(v, f);
    }
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unionn(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    fa[x] = y; sz[y] += sz[x];
    Treap[x]->mergeto(Treap[y]);
}
int kas;
void work() {
    tot = 0;
    memset(ne, -1, sizeof(ne));
    memset(sz, 0, sizeof(sz));
    memset(flag, 0, sizeof(flag));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
    }
    int num = 0; char ch;
    while (scanf("\n%c", &ch) && ch != 'E') {
        ++num;
        int x, y, p, w;
        if (ch == 'D') {
            scanf("%d", &x);
            flag[x] = true;
            oper[num] = Oper(0, x);
        }
        else if (ch == 'Q') {
            scanf("%d%d", &x, &y);
            oper[num] = Oper(1, x, y);
        }
        else if (ch == 'C') {
            scanf("%d%d", &p, &w);
            oper[num] = Oper(2, p, val[p]);
            val[p] = w;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (!flag[i]) {
            addEdge(u[i], v[i]); addEdge(v[i], u[i]);
        }
    }
    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i, i);
    for (int i = 1; i <= n; ++i) {
        Treap[i] = new treap;
        ++sz[fa[i]];
        Treap[fa[i]]->insert(val[i]);
    }
    LL ans = 0, cnt = 0;
    for (int i = num; i > 0; --i) {
        if (oper[i].t == 0) unionn(u[oper[i].x], v[oper[i].x]);
        else if (oper[i].t == 1) {
            ans += (LL)Treap[find(oper[i].x)]->calckth(oper[i].y), ++cnt;
        }
        else {
            Treap[find(oper[i].x)]->replace(val[oper[i].x], oper[i].y);
            val[oper[i].x] = oper[i].y;
        }
    }
    printf("Case %d: %.6f\n", ++kas, 1.0 * ans / cnt);
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF && n + m) work();
    return 0;
}
