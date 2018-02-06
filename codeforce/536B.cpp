#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
set<int> st;
int f[maxn], n, m, a[maxn], len;
char s[maxn], P[maxn];
LL poww(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) (ret *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ret;
}
void getfail() {
    f[0] = f[1] = 0;
    for (int i = 1; i < len; ++i) {
        int j = f[i];
        while (j && P[j] != P[i]) j = f[j];
        f[i+1] = P[i] == P[j] ? j+1 : 0;
    }
    int temp = len;
    while (f[temp]) {
        st.insert(len - f[temp]);
        temp = f[temp];
    }
}
void getdata() {
    printf("%s\n", P);
    for (int i = 0; i < m; ++i) printf("%d ", a[i]+1);
}
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d%s", &n, &m, P);
    len = strlen(P);
    getfail();
//    for (auto x : st) printf("%d\n", x);
    int cur = 0, emp = 0;
    bool flag = false;
    for (int i = 0; i < m; ++i) scanf("%d", &a[i]), --a[i];
    for (int i = 0; i < m; ++i) {
        if (cur <= a[i]) {
            emp += a[i] - cur;
            cur = a[i] + len;
        }
        else {
            if (st.count(len-(cur-a[i]))) cur = a[i] + len;
            else {
                flag = true;
                break;
            }
        }
//        printf("%d %d\n", emp, cur);
    }
    emp += n - cur;
    if (flag) printf("0\n");
    else printf("%I64d\n", poww(26, emp));
    return 0;
}
