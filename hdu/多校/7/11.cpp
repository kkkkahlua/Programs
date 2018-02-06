#include <bits/stdc++.h>
#include <vector>
#define maxn 10000000
int a[maxn + 10];
using namespace std;
vector<int> G;
typedef long long LL;
void init2(){
    G[0] = 1, G[1] = 2, G[2] = 2;
    for(int sp = 2; G.size() < 50; ++ sp){
        int tmp = G[G.size() - 1];
        for(int i=1;i<=G[sp];++i) G.push_back(3 - tmp);
    }
}
void init() {
    int tot = 2, i = 2, j = 2;
    a[0] = 1, a[1] = 2, a[2] = 2;
        while (i >= j) {
//            printf("%d %d\n", i, j);
            int temp = a[j];
            if (temp == 1) {
                a[i + 1] = 3 - a[i];
                i += 1;
            }
            else {
                    a[i + 1] = a[i + 2] = 3 - a[i];
                    i += 2;
            }
            j += 1;
        if (i >= 1e7) break;
        }
}
void work() {
    int n;
    scanf("%d", &n);
    printf("%d\n", a[n-1]);
}
int main() {
//    freopen("in.txt", "r", stdin);
    init();
//    for (int i = 0; i < 20; ++i) printf("%d ", a[i]); printf("\n");
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
