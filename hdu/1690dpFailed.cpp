#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#define MAXN 40010
#define MAX 10100
using namespace std;
typedef long long LL;
int n, m, k;
struct node { int p, id; }pos[110];
bool cmp(node u, node v) { return u.p < v.p; }
int kase = 0, L1,L2,L3,L4, p[110];
LL C1,C2,C3,C4,dist[110][110];
void printArray(int a[], int len) {
    for (int i = 0; i < len; ++i) printf("%d ", a[i]);
    printf("\n");
}
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
LL eval(int x) {
    if (x == 0) return 0;
    if (x <= L1) return C1;
    if (x <= L2) return C2;
    if (x <= L3) return C3;
    if (x <= L4) return C4;
}
LL calc(int s, int t) {
//    cout << s <<t <<endl;
    if (dist[s][t]) return dist[s][t];
    int sum = 0;
    s = p[s], t = p[t];
    for (int i = s + 1; i <= t; ++i) {
        LL minn, p2 = pos[i].p;
        bool flag = false;
        for (int j = s; j < i; ++j) {
            int p1 = pos[j].p;
            printf("%d %d\n", p1, p2);
            if (p2 - p1 > L4) continue;
            if (!flag) minn = eval(p2 - p1) + dist[pos[s].id][pos[j].id];
            else minn = eval(p2 - p1) + dist[pos[s].id][pos[j].id] < minn ? eval(p2 - p1) + dist[pos[s].id][pos[j].id] : minn;
            flag = true;
        }
        if (!flag) return -1;
        dist[pos[s].id][pos[i].id] = minn;
        printf("%d %d %I64d\n", s, i, dist[s][i]);
    }
    return dist[pos[s].id][pos[t].id];
}
void work() {
    printf("Case %d:\n", ++kase);
    scanf("%d%d", &n, &m);
    memset(dist, 0, sizeof(dist));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pos[i].p);
        pos[i].id = i + 1;
    }
    sort(pos, pos + n, cmp);
    for (int i = 0; i < n; ++i) p[pos[i].id] = i;

//    printArray(p + 1, n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        int ou = u, ov = v;
        if (p[u] > p[v]) swap(u, v);
        LL cost = calc(u, v);
//        if (cost != -1) printf("The minimum cost between station %d and station %d is %I64d.\n", ou, ov, cost);
//        else printf("Station %d and station %d are not attainable.\n", ou, ov);
        if (cost != -1) cout << "The minimum cost between station " << ou << " and station " << ov << " is " << cost << ".\n";
        else printf("Station %d and station %d are not attainable.\n", ou, ov);
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (scanf("%d%d%d%d%I64d%I64d%I64d%I64d", &L1, &L2, &L3, &L4, &C1, &C2, &C3, &C4) != EOF) work();
    return 0;
}
