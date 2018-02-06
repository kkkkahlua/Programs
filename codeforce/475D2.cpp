#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
int gcd[maxn][32], a[maxn], n, Log[maxn], bin[32];
map<int, LL> mp;
int Gcd(int a, int b) { return b ? Gcd(b, a%b) : a; }
void rmqInit() {
    Log[0] = -1; bin[0] = 1;
    for (int i = 1; i < 20; ++i) bin[i] = bin[i-1] << 1;
    for (int i = 1; i <= n; ++i) Log[i] = Log[i>>1] + 1, gcd[i][0] = a[i];
    for (int j = 1; bin[j] <= n; ++j) {
        for (int i = 1; i + bin[j-1] - 1 <= n; ++i) {
            gcd[i][j] = Gcd(gcd[i][j-1], gcd[i + bin[j-1]][j-1]);
        }
    }
}
int query(int l, int r) {
    int k = Log[r-l+1];
    return Gcd(gcd[l][k], gcd[r-bin[k]+1][k]);
}
int bi(int i, int l, int r, int x) {
    while (r-l>1) {
        int mid = l+r >> 1, val = query(i, mid);
        if (val >= x) l = mid;
        else r = mid - 1;
    }
    return query(i, r) == x ? r : l;
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    rmqInit();
    for (int i = 1; i <= n; ++i) {
        int l = i;
        while (true) {
            if (l == n+1) break;
            int val = query(i, l);
            int r = bi(i, l, n, val);
            mp[val] += r-l+1;
            l = r+1;
        }
    }
    int q, x;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        printf("%I64d\n", mp[x]);
    }
    return 0;
}
