#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
map<int, int> m;
struct node {
    node* ch[2];
    int val, key, sz;
    node() { sz = 0; key = INT_MAX; }
    node(int x);
    void update() { sz = ch[0]->sz + ch[1]->sz + 1; }
}* null = new node;
node::node(int x) { sz = 1, val = x, key = rand(); ch[0] = ch[1] = null; }
struct Treap {
    node* root;
    Treap() { root = null; }
    bool empty() { return root == null; }
    void rotate(node*& t, bool d) {
        node* p = t->ch[d];
        t->ch[d] = p->ch[!d];
        p->ch[!d] = t;
        t->update(), p->update();
        t = p;
    }
    void insert(node*& t, int x, int& lo, int& hi) {
        if (t == null) { t = new node(x); return; }
        bool d = x > t->val;
        if (d == 0) hi = t->val;
        else lo = t->val;
        insert(t->ch[d], x, lo, hi);
        if (t->ch[d]->key < t->key) rotate(t, d);
        else t->update();
    }
    int findpos(int x) {
        int lo = -inf, hi = inf;
        insert(root, x, lo, hi);
        return hi-x < x-lo ? hi : lo;
    }
    void clear(node*& t) {
        if (t->ch[0] != null) clear(t->ch[0]);
        if (t->ch[1] != null) clear(t->ch[1]);
        delete t; t = null;
    }
    void clear() { clear(root); }
    void insert(int x) { int lo, hi; insert(root, x, lo, hi); }
}* treap = new Treap;
int n, id, x;
void work() {
    if (!treap->empty()) treap->clear();
    treap->insert(1000000000);
    m.clear(); m[1000000000] = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &id, &x);
        m[x] = id;
        printf("%d %d\n", id, m[treap->findpos(x)]);
    }
}
int main() {
    while (scanf("%d", &n) && n) work();
    return 0;
}
