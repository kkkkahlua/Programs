#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxl 10010
#define inf 0x3f3f3f3f
char s[maxl];
int l[maxl], r[maxl], val[maxl], bl[maxl];
using namespace std;
typedef long long LL;
int num=0, p=0, pl, mi;
bool flag;
struct node { int maxx, minn; }dp[maxl][110];
void build(int cur) {
    if (isdigit(s[p])) { val[cur] = s[p]-'0'; return; }
    ++p;
    build(l[cur] = ++num);
    p += 2;
    build(r[cur] = ++num);
    ++p;
    return;
}
//void print(int cur) {
//    printf("%d\n", cur);
//    if (~l[cur]) {
//        puts("lb");
//        print(l[cur]);
//        puts("le");
//        puts("rb");
//        print(r[cur]);
//        puts("re");
//    }
//}
void dfs(int cur) {
    if (l[cur]==-1) {
        bl[cur] = 0;
        dp[cur][0] = {val[cur], val[cur]};
        return;
    }
    dfs(l[cur]); dfs(r[cur]);
    bl[cur] = bl[l[cur]] + bl[r[cur]] + 1;
    F2(i, 0, pl-1) {
        int pll = i, mii = bl[cur]-1-pll;
        if (mii<0 || mii>mi) continue;
        F2(j, 0, i) {
            if (j>bl[l[cur]]) break;
            if (flag) {
                node& ndl = dp[l[cur]][j],
                    & ndr = dp[r[cur]][pll-j],
                    & nd = dp[cur][pll+1];
                nd.maxx = max(nd.maxx, ndl.maxx+ndr.maxx);
                nd.minn = min(nd.minn, ndl.minn+ndr.minn);
            }
            else {
                node& ndl = dp[l[cur]][bl[l[cur]]-j],
                    & ndr = dp[r[cur]][bl[r[cur]]-pll+j],
                    & nd = dp[cur][bl[cur]-pll-1];
                nd.maxx = max(nd.maxx, ndl.maxx+ndr.maxx);
                nd.minn = min(nd.minn, ndl.minn+ndr.minn);
            }
        }
    }
    F2(i, 0, pl) {
        int pll = i, mii = bl[cur]-1-pll;
        if (mii<0 || mii>=mi) continue;
        F2(j, 0, i) {
            if (j>bl[l[cur]]) break;
            if (flag) {
                node& ndl = dp[l[cur]][j],
                    & ndr = dp[r[cur]][pll-j],
                    & nd = dp[cur][pll];
                nd.maxx = max(nd.maxx, ndl.maxx-ndr.minn);
                nd.minn = min(nd.minn, ndl.minn-ndr.maxx);
            }
            else {
                node& ndl = dp[l[cur]][bl[l[cur]]-j],
                    & ndr = dp[r[cur]][bl[r[cur]]-pll+j],
                    & nd = dp[cur][bl[cur]-pll];
                nd.maxx = max(nd.maxx, ndl.maxx-ndr.minn);
                nd.minn = min(nd.minn, ndl.minn-ndr.maxx);
            }
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    scanf("%s", s);
    int len = strlen(s);
    build(0);
//    print(0);
    scanf("%d%d", &pl, &mi);
    if (pl <= mi) flag = true;
    else flag = false;
    F2(i, 0, num) F2(j, 0, flag?pl:mi) dp[i][j] = {-inf, inf};
    dfs(0);
    int ans = -inf;
    F2(i, 0, pl) ans = max(ans, dp[0][i].maxx);
    printf("%d\n", ans);
    return 0;
}
