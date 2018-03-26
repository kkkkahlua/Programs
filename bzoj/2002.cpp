#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200010
using namespace std;
typedef long long LL;
int a[maxn], n, blo, bl[maxn], num;
struct node { int cnt, p; }v[maxn];
void init() {
    F(i, 0, num) {
        int ed = min((i+1)*blo-1, n-1),
            st = i*blo;
        dF2(j, ed, st) {
            int ne = j+a[j];
            if (ne>ed) v[j] = {1, ne};
            else v[j] = v[ne], ++v[j].cnt;
        }
    }
}
void modify(int x, int c) {
    a[x] = c;
    int st = bl[x]*blo, ed = min((bl[x]+1)*blo-1, n-1);
    dF2(i, x, st) {
        int ne = i+a[i];
        if (ne > ed) v[i] = {1, ne};
        else v[i] = v[ne], ++v[i].cnt;
    }
}
int query(int x) {
    int ret=0;
    while (x < n) {
        ret += v[x].cnt;
        x = v[x].p;
    }
    return ret;
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n); blo = sqrt(n);
    F(i, 0, n) {
        scanf("%d", &a[i]);
        bl[i] = i/blo;
    }
    num = bl[n-1]+1;
    init();
    int m;
    scanf("%d", &m);
    F(i, 0, m) {
        int op, x, y;
        scanf("%d", &op);
        if (op==1) {
            scanf("%d",&x);
            printf("%d\n", query(x));
        }
        else {
            scanf("%d%d", &x,&y);
            modify(x,y);
        }
    }
    return 0;
}
