#include <cstdio>
#include <climits>
#include <cstdlib>
#include <ctime>
#define maxn 30010
using namespace std;
int n, m, a[maxn];
struct node {
    node* ch[2];
    int val, key, sz;
    node() { sz = 0, key = INT_MAX; }
    node(int x);
    void update() {
        sz = ch[0]->sz + ch[1]->sz + 1;
    }
}*null = new node;
node::node(int x) {
    ch[0] = ch[1] = null;
    sz = 1, val = x, key = rand();
}
struct treap {
    node* root;
    treap() { root = null; }
    void rotate(node*& t, bool b) {
        node* p = t->ch[b];
        t->ch[b] = p->ch[!b];
        p->ch[!b] = t;
        t->update();
        p->update();
        t = p;
    }
    void insert(node*& t, int x) {
        if (t == null) {
            t = new node(x);
            return;
        }
        bool dir = x > t->val;
        insert(t->ch[dir], x);
        if (t->ch[dir]->key < t->key) rotate(t, dir);
        else t->update();
    }
    int calckth(int k) {
        int dir;
        for (node* t = root; t != null; t = t->ch[dir]) {
            int cnt = t->ch[0]->sz;
            if (k == cnt+1) return t->val;
            else if (k <= cnt) dir = 0;
            else dir = 1, k -= (cnt+1);
        }
    }
    void insert(int x) { insert(root, x); }
    int size() { return root->sz; }
};
void work() {
    treap* Treap = new treap;
    for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
    int p = 0, k = 1;
    while (n--) {
        int x;
        scanf("%d", &x);
        while (p < x) {
            int y = a[p++];
            Treap->insert(y);
        }
        printf("%d\n", Treap->calckth(k));
        ++k;
    }
}
int main() {
    while (scanf("%d%d", &m, &n) != EOF) work();
    return 0;
}
