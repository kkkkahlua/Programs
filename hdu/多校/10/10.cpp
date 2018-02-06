#include <bits/stdc++.h>
#include <queue>
#define maxn 100010
typedef long long LL;
using namespace std;
int cnt[maxn];
namespace fastIO {
    #define BUF_SIZE 100000
    //fread -> read
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
    #undef BUF_SIZE
};
using namespace fastIO;
struct node {
    int s, t;
}a[maxn], m[maxn];
bool cmp(node u, node v) {
    return u.s < v.s || (u.s == v.s && u.t < v.t);
}
//struct qnode {
//    int id, time, cnt;
//    qnode(int a = 0, int b = 0, int c = 0): id(a), time(b), cnt(c) {}
//    bool operator < (const qnode nd) const { return time < nd.time; }
//};
struct qnode {
    int s, t;
    qnode(int a = 0, int b = 0) : s(a), t(b) {}
    bool operator < (const qnode nd) const { return t < nd.t; }
};
multiset<qnode> s;
priority_queue<qnode> pq;
void work() {
    s.clear();
    int n;
    read(n);
    for (int i = 0; i < n; ++i) { read(a[i].s); read(a[i].t); }
    sort(a, a + n, cmp);
    s.insert(qnode(a[0].s, a[0].t));
    for (int i = 1; i < n; ++i) {
        bool flag = true;
        set<qnode>::iterator p;
        int maxx = -1;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (it->t > a[i].s) break;
            if (it->s > maxx) p = it, maxx = it->s;
        }
        if (maxx == -1) s.insert(qnode(a[i].s, a[i].t));
        else {
            s.insert(qnode(p->s, a[i].t));
            s.erase(p);
        }
    }
    int k = s.size();
    LL ans = 0;
    for (auto it = s.begin(); it != s.end(); ++it) {
        ans += (LL)(it->t - it->s);
    }
    printf("%d %lld\n", k, ans);

//    int tot = 1; cnt[0] = 1;
//    pq.push(qnode(0, a[0].t, 1));
//    for (int i = 1; i < n; ++i) {
//        while (pq.top().cnt != cnt[pq.top().id]) pq.pop();
//        qnode nd = pq.top();
//        if (nd.time <= a[i].s) {
//            pq.pop();
//            pq.push(qnode(nd.id, a[i].t, nd.cnt+1));
//            ++cnt[nd.id];
//        }
//        else {
//            pq.push(qnode(tot, a[i].t, 1));
//            cnt[tot++] = 1;
//        }
//    }
//    printf("%d\n", tot);



//    int tot = 0;
//    m[tot++] = a[0];
//    for (int i = 1; i < n; ++i) {
//        int idx = -1;
//        for (int j = 0; j < tot; ++j) {
//            if (m[j].t <= a[i].s) {
//                if (idx == -1 || m[j].s > m[idx].s) idx = j;
//            }
//        }
//        if (idx == -1) m[tot++] = a[i];
//        else m[idx].t = a[i].t;
//    }
//    LL ans = 0;
//    for (int i = 0; i < tot; ++i) ans += (LL)(m[i].t - m[i].s);
//    printf("%d %lld\n", tot, ans);
}
int main() {
//    s.insert(qnode(1,3,2));
//    s.insert(qnode(2,1,3));
//    s.insert(qnode(1,2,2));
//    for (auto it = s.begin(); it != s.end(); ++it) printf("%d\n", it->time);
//
//    printf("%d\n", s.begin()->time);
//    set<qnode>::iterator p;
//    for (auto it = s.begin(); it != s.end(); ++it) {
//        if (it->time == 2) p = it;
//    }
//    s.insert(qnode(p->id, 4, p->cnt));
//    s.erase(p);
//
//    for (auto it = s.begin(); it != s.end(); ++it) printf("%d\n", it->time);
//
//    printf("%d\n", s.begin()->time);

    freopen("in.txt", "r", stdin);
    int T;
    read(T);
//    scanf("%d", &T);
    while (T--) work();
    return 0;
}
