#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
using namespace std;
typedef long long LL;
struct node {
    int key, val, sz, id;
    node* ch[2];
    node() { sz = 0, key = INT_MAX; }
    node(int,int);
    void update() { sz = ch[0]->sz + ch[1]->sz + 1; }
}*null = new node;
node::node(int x, int y) { id = x, val = y, key = rand(), sz = 1, ch[0] = ch[1] = null; }
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
    void insert(node*& t, node nd) {
        if (t == null) { t = new node(nd); return; }
        bool dir = nd.val > t->val;
        insert(t->ch[dir], nd);
        if (t->ch[dir]->key < t->key) rotate(t, dir);
        else t->update();
    }
    void insert(node nd) { insert(root, nd); }
    void erase(int x) { erase(root, x); }
    void erase(node*& t, int x) {
        if (t == null) return;
        if (t->val == x) {
            bool dir = t->ch[1]->key < t->ch[0]->key;
            if (t->ch[dir] == null) { delete t; t = null; return; }
            if (t->ch[!dir] == null) { node* p = t->ch[dir]; delete t; t = p; return; }
            rotate(t, dir);
            erase(t->ch[!dir], x);
            t->update();
            return;
        }
        bool dir = x > t->val;
        erase(t->ch[dir], x);
        t->update();
    }
    node* calckth(int k) {
        bool dir;
        for (node* t = root; t != null; t = t->ch[dir]) {
            int cnt = t->ch[0]->sz;
            if (k == cnt+1) return t;
            else if (k <= cnt) dir = 0;
            else dir = 1, k -= (cnt+1);
        }
    }
    int size() { return root->sz; }
}*treap = new Treap;
int main() {
//    freopen("in.txt", "r", stdin);
    int x;
    while (scanf("%d", &x) != EOF && x) {
        if (x == 1) {
            int id, val;
            scanf("%d%d", &id, &val);
            treap->insert(node(id, val));
        }
        else {
            int sz = treap->size();
            if (!sz) puts("0");
            else {
                node* ans;
                if (x == 3) ans = treap->calckth(1);
                else ans = treap->calckth(sz);
                printf("%d\n", ans->id);
                treap->erase(ans->val);
            }
        }
    }
    return 0;
}
