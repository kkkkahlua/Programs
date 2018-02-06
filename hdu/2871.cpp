#include <bits/stdc++.h>
#define maxn 50010
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
struct node {
    int l,r,ml,mr,mx,len,flag;
}tr[maxn * 4];
vector<pair<int,int> > v;
bool cmp(pair<int, int> u, pair<int, int> v) { return u.first < v.first; }
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r, tr[rt].len = r-l+1, tr[rt].flag = -1;
    tr[rt].ml = tr[rt].mr = tr[rt].mx = tr[rt].len;
    if (l == r) return;
    int mid = tr[rt].l + tr[rt].r >> 1;
    build(lson, l, mid); build(rson, mid+1, r);
}
void push_down(int rt) {
    if (tr[rt].flag != -1) {
        tr[lson].flag = tr[rson].flag = tr[rt].flag;
        tr[lson].ml = tr[lson].mr = tr[lson].mx = tr[rt].flag ? tr[lson].len : 0;
        tr[rson].ml = tr[rson].mr = tr[rson].mx = tr[rt].flag ? tr[rson].len : 0;
        tr[rt].flag = -1;
    }
}
void push_up(int rt) {
    tr[rt].ml = tr[lson].ml; if (tr[lson].ml == tr[lson].len) tr[rt].ml += tr[rson].ml;
    tr[rt].mr = tr[rson].mr; if (tr[rson].mr == tr[rson].len) tr[rt].mr += tr[lson].mr;
    tr[rt].mx = max(max(tr[lson].mx, tr[rson].mx), tr[lson].mr+tr[rson].ml);
}
int query(int rt, int len) {
    if (tr[rt].l == tr[rt].r && tr[rt].mx == len) return tr[rt].l;
    push_down(rt);
    if (tr[lson].mx >= len) return query(lson, len);
    else if (tr[lson].mr + tr[rson].ml >= len) return tr[lson].r-tr[lson].mr+1;
    else if (tr[rson].mx >= len) return query(rson, len);
    else return 0;
}
void modify(int rt, int l, int r, int x) {
    if (tr[rt].l == l && tr[rt].r == r) {
        tr[rt].ml = tr[rt].mr = tr[rt].mx = x ? tr[rt].len : 0;
        tr[rt].flag = x;
        return;
    }
    push_down(rt);
    int mid = tr[rt].l + tr[rt].r >> 1;
    if (r <= mid) modify(lson, l, r, x);
    else if (l > mid) modify(rson, l, r, x);
    else { modify(lson, l, mid, x); modify(rson, mid+1, r, x); }
    push_up(rt);
}
int m, n;
void work() {
    build(1, 1, n);
    v.clear();
    while (m--) {
        char s[10];
        scanf("%s", s);
        char c = s[0];
        if (c == 'R') {
            modify(1, 1, n, 1); v.clear();
            printf("Reset Now\n");
            continue;
        }
        int x;
        scanf("%d", &x);
//        for (auto temp : v) printf("%d %d\n", temp.first, temp.second);
        if (c == 'N') {
            int p = query(1, x);
            if (p) {
                modify(1, p, p+x-1, 0);
                pair<int, int> pr(p, p+x-1);
                auto it = lower_bound(v.begin(), v.end(), pr, cmp);
                v.insert(it, pr);
                printf("New at %d\n", p);
            }
            else printf("Reject New\n");
        }
        else if (c == 'F') {
            pair<int, int> pr(x, x);
            auto it = upper_bound(v.begin(), v.end(), pr, cmp);
            if (it == v.begin()) printf("Reject Free\n");
            else {
                --it;
                if (it->second >= x) {
                    modify(1, it->first, it->second, 1);
                    printf("Free from %d to %d\n", it->first, it->second);
                    v.erase(it);
                }
                else printf("Reject Free\n");
            }
        }
        else if (c == 'G') {
            if (x > v.size()) printf("Reject Get\n");
            else printf("Get at %d\n", v[x-1].first);
        }
    }
    printf("\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
