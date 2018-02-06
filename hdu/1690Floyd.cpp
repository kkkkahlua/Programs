#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#define MAXN 40010
#define MAX 10100
#define INF 1e18
using namespace std;
typedef long long LL;
int n, m, k;
int kase = 0, a[110];
LL L1,L2,L3,L4,C1,C2,C3,C4,dist[110][110];
void printArray(LL a[], LL len) {
    for (int i = 0; i < len; ++i) printf("%I64d ", a[i]);
    printf("\n");
}
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
LL eval(LL s, LL t) {
    LL x = labs(a[t] - a[s]);
    if (x == 0) return 0;
    if (x <= L1) return C1;
    if (x <= L2) return C2;
    if (x <= L3) return C3;
    if (x <= L4) return C4;
    return -1;
}

void work() {
    printf("Case %d:\n", ++kase);
    scanf("%d%d", &n, &m);
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = eval(i, j);
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int s = 0; s < n; ++s) {
            if (dist[s][k] == -1) continue;
            for (int t = 0; t < n; ++t) {
                if (s == t) continue;
                if (dist[k][t] == -1) continue;
                LL cost = dist[s][k] + dist[k][t];
//                printf("%d %d %d %d\n", s, k, t, cost);
                if (dist[s][t] == -1 || cost < dist[s][t]) {
                    dist[s][t] = dist[t][s] = cost;
                }
            }
        }
//        for (int i = 0; i < n; ++i) printArray(dist[i], n);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        LL cost = dist[u-1][v-1];
//        if (cost != -1) printf("The minimum cost between station %d and station %d is %I64d.\n", u, v, cost);
//        else printf("Station %d and station %d are not attainable.\n", u, v);
        if (cost != -1) cout << "The minimum cost between station " << u << " and station " << v << " is " << cost << ".\n";
        else printf("Station %d and station %d are not attainable.\n", u, v);
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (cin >> L1 >>L2 >>L3 >> L4 >> C1 >> C2 >> C3 >> C4) work();
    return 0;
}
