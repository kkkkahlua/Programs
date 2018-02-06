#include <bits/stdc++.h>
#define maxn 210
using namespace std;
typedef long long LL;
int n, k;
int x[maxn];
void work() {
    scanf("%d%d", &n,&k);
    for (int i = 0; i < k; ++i) scanf("%d", &x[i]);
    sort(x,x+k);
    int maxx = max(x[0], n-x[k-1]+1);
    for (int i = 0; i < k-1; ++i) {
        maxx = max(maxx, (x[i+1]-x[i]+2)/2);
    }
    printf("%d\n", maxx);
}
int main() {
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
