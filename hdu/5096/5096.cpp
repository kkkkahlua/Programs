#include <bits/stdc++.h>
#define maxn 20010
using namespace std;
int cnt[maxn], trial[maxn][12], last[maxn], pen[maxn], lstacc[maxn];
bool solve[maxn][12];
char s[100];
struct Sta {
    int cnt, pen;
    Sta(int _cnt=0, int _pen=0) : cnt(_cnt), pen(_pen) {}
    bool operator < (const Sta& sta) const {
        return cnt > sta.cnt || (cnt == sta.cnt && pen < sta.pen);
    }
    bool operator == (const Sta& sta) const {
        return cnt == sta.cnt && pen == sta.pen;
    }
};
struct cmp {
    bool operator()(const int &a, const int &b) const{
        if(lstacc[a] == -1 && lstacc[b] == -1) return a < b;
        if(lstacc[a] == -1 || lstacc[b] == -1) return lstacc[b] == -1;
        return lstacc[a] < lstacc[b];
    }
};
struct node {
    Sta val; int key, sz, cnt;
    node* ch[2];
    set<int, cmp> s;
    node() { sz = 0, key = INT_MAX, s.clear(); }
    node(Sta sta, int id);
    update() { sz = ch[0]->sz + ch[1]->sz + cnt; }
}* null = new node;
node::node(Sta sta, int id) {
    val = sta, key = rand(), sz = cnt = 1;
    ch[0] = ch[1] = null;
    s.clear(); s.insert(id);
}
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
    void insert(node*& t, Sta sta, int id) {
        if (t == null) { t = new node(sta, id); return; }
        if (t->val == sta) {
            ++t->cnt, t->s.insert(id);
            t->update();
            return;
        }
        bool dir = !(sta < t->val);
        insert(t->ch[dir], sta, id);
        if (t->ch[dir]->key < t->key) rotate(t, dir);
        else t->update();
    }
    void erase(node*& t, Sta sta, int id) {
        if (t == null) return;
        if (t->val == sta) {
            if (t->cnt > 1) {
                --t->cnt; t->s.erase(id);
                t->update();
                return;
            }
            bool dir = t->ch[1]->key < t->ch[0]->key;
            if (t->ch[dir] == null) { delete t; t = null; return; }
            if (t->ch[!dir] == null) { node* p = t->ch[dir]; delete t; t = p; return; }
            rotate(t, dir);
            erase(t->ch[!dir], sta, id);
            t->update();
            return;
        }
        bool dir = !(sta < t->val);
        erase(t->ch[dir], sta, id);
        t->update();
    }
    void insert(Sta sta, int id) {
        insert(root, sta, id);
    }
    void erase(Sta sta, int id) {
        erase(root, sta, id);
    }
    int calckth(int k) {
        if (k <= 0 || k > root->sz) return -1;
        bool dir;
        for (node* t = root; t != null; t = t->ch[dir]) {
            int num = t->ch[0]->sz;
            if (k == num+1) return *(t->s.begin());
            else if (k <= num) dir = 0;
            else {
                k -= (num + t->cnt);
                if (k <= 0) return -1;
                else dir = 1;
            }
        }
    }
    int find(node*& t, Sta sta) {
        if (t->val == sta) return t->ch[0]->sz + 1;
        bool d = !(sta < t->val);
        if (d == 0) return find(t->ch[d], sta);
        else return t->ch[0]->sz + t->cnt + find(t->ch[d], sta);
    }
    void clear(node*& t) {
        if (t->ch[0] != null) clear(t->ch[0]);
        if (t->ch[1] != null) clear(t->ch[1]);
        delete t; t = null;
    }
    void clear() { clear(root); }
    int find(Sta sta) { return find(root, sta); }
    int size() { return root->sz; }
}* treap = new Treap;
int readint() {
    char c;
    while((c = getchar()) && !(c >= '0' && c <= '9'));
    int ret = c - '0';
    while((c = getchar()) && c >= '0' && c <= '9')
        ret = ret * 10 + c - '0';
    return ret;
}
char readc() {
    char c;
    while((c = getchar()) && !isalpha(c));
    return c;
}
int n, m, kas;
void work() {
    memset(cnt, 0, sizeof(cnt));
    memset(pen, 0, sizeof(pen));
    memset(solve, 0, sizeof(solve));
    memset(last, -1, sizeof(last));
    memset(trial, 0, sizeof(trial));
    memset(lstacc, -1, sizeof(lstacc));
    if (treap->root != null) treap->clear();

    for (int i = 0; i < n; ++i) treap->insert(Sta(0, 0), i);
    char op[20];
    int order = 0;

    while (scanf("%s", op) && op[0] != 'C') {
        ++order;
        int k, x;
        if (op[0] == 'S') {
            int time = readint(), team = readint(), prob = readc()-'A', stat = readint();
            if (!solve[team][prob] && (last[team] == -1 || time - last[team] >= 5)) {
                if (stat != 1) { last[team] = time; ++trial[team][prob]; continue; }
                Sta sta1(cnt[team], pen[team]);
                treap->erase(sta1, team);
                solve[team][prob] = true, ++cnt[team];
                pen[team] += time + trial[team][prob] * 20;
                last[team] = time;
                lstacc[team] = order;
                Sta sta2(cnt[team], pen[team]);
                treap->insert(sta2, team);
                printf("[%d][%c]\n", team, prob+'A');
            }
        }
        else if (op[0] == 'T') {
            scanf("%d", &k);
            printf("%d\n", treap->calckth(k));
        }
        else if (op[0] == 'R') {
            scanf("%d", &x);
            Sta sta(cnt[x], pen[x]);
            printf("%d\n", treap->find(sta));
        }
    }
    scanf("%s", op);
    printf("\n");
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
