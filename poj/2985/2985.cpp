#include <cstdio>
#include <climits>
#include <cstdlib>
#include <iostream>
#define maxn 200010
using namespace std;
int fa[maxn], sz[maxn];
struct node {
    node* ch[2];
    int val, key, sz;
    node() { sz = 0, key = INT_MAX; }
    node(int x);
    void update() { sz = ch[0]->sz + ch[1]->sz + 1; }
}*null = new node;
node::node(int x) {
    ch[0] = ch[1] = null;
    val = x, key = rand(), sz = 1;
}
struct treap {
    node* root;
    treap() { root = null; }
    void rotate(node*& t, bool d) {
        node* p = t->ch[d];
        t->ch[d] = p->ch[!d];
        p->ch[!d] = t;
        t->update();
        p->update();
        t = p;
    }
    void insert(node*& t, int x) {
//        printf("insert %d\n", t->val);
        if (t == null) {
            t = new node(x);
            return;
        }
        bool dir = x > t->val;
        insert(t->ch[dir], x);
        if (t->ch[dir]->key < t->key) rotate(t, dir);
        else t->update();
    }
    void erase(node*& t, int x) {
        if (t == null) return;
        if (t->val == x) {
            bool d = t->ch[1]->key < t->ch[0]->key;
//            printf("%d %d\n", d, t->ch[d]->val);
            if (t->ch[d] == null) {
                delete t;
                t = null;
                return;
            }
            if (t->ch[!d] == null) {
                node* p = t->ch[d];
                delete t;
                t = p;
                return;
            }
            rotate(t, d);
//            printf("%d %d %d\n", t->val, t->ch[0]->val, t->ch[1]->val);
            erase(t->ch[!d], x);
            t->update();
            return;
        }
        bool d = x > t->val;
        erase(t->ch[d], x);
        t->update();
    }
    int calckth(int k) {
        int dir;
        for (node* t = root; t != null; t = t->ch[dir]) {
            int sz = t->ch[0]->sz;
            if (k == sz+1) return t->val;
            else if (k <= sz) dir = 0;
            else dir = 1, k -= (sz+1);
        }
    }
    void insert(int x) { insert(root, x); }
    void erase(int x) { erase(root, x); }
    int size() { return root->sz; }
}* Treap;
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int n, m;
void unionn(int u, int v) {
    int fau = find(u), fav = find(v);
    if (fau == fav) return;
    --n;
    Treap->erase(sz[fau]);
//    printf("root : %d %d %d\n", Treap->size(), fau, sz[fau]);
    Treap->erase(sz[fav]);
//    printf("root : %d %d %d\n", Treap->size(), fav, sz[fav]);
    if (sz[fau] > sz[fav]) swap(fau, fav);
    fa[fau] = fav, sz[fav] += sz[fau];
    Treap->insert(sz[fav]);
//    printf("root : %d %d %d\n", Treap->size(), fav, sz[fav]);
}
void work() {
    Treap = new treap;
    for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1, Treap->insert(1);
    while (m--) {
        int x, u, v, k;
        scanf("%d", &x);
        if (x == 0) {
            scanf("%d%d", &u, &v);
            unionn(u, v);
        }
        else {
            scanf("%d", &k);
            printf("%d\n", Treap->calckth(n-k+1));
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("2985.out", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
