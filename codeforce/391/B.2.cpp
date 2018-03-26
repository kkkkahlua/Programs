#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100000
using namespace std;
typedef long long LL;
int num[maxn+10], cnt[maxn+10], prime[maxn], tot;
bool vis[maxn+10];
void work(int x) {
    for (int i = 1; ; ++i) {
        if (i*x>maxn) break;
        cnt[x] += num[i*x];
    }
}
void init() {
    F2(i, 2, maxn) {
        if (!vis[i]) prime[tot++] = i;
        work(i);
        F(j, 0, tot) {
            if (i*prime[j]>maxn) break;
            vis[i*prime[j]]=true;
            if (i%prime[j]==0) break;
        }
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    int n, x, ans=0;
    scanf("%d", &n);
    F(i, 0, n) {
        scanf("%d", &x);
        ++num[x];
    }
    init();
    F2(i, 0, maxn) ans = max(ans, cnt[i]);
    printf("%d\n", ans?ans:1);
    return 0;
}
