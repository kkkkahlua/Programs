#include <cstdio>
#include <cmath>
#include <cstring>
#define mod 1000000007
#define maxn 100000
typedef long long LL;
int kas, n, lenn[30], tot[30][maxn + 10];
char s[maxn + 10];
bool exist[maxn + 10];
bool lessthan(int x, int y) {
    if (lenn[x] > lenn[y]) return false;
    if (lenn[x] < lenn[y]) return true;
    int len = lenn[x];
    for (int i = len; i >= 0; --i) {
        if (tot[x][i] > tot[y][i]) return false;
        else if (tot[x][i] < tot[y][i]) return true;
    }
    return false;
}
LL poww(LL x, LL y) {
    LL ret = 1;
    while (y) {
        if (y & 1) { ret *= x; ret %= mod; }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return ret;
}
void swapp(int x, int y) {
    for (int i = 0; i <= maxn; ++i) {
        int temp = tot[x][i];
        tot[x][i] = tot[y][i];
        tot[y][i] = temp;
    }
    int temp = lenn[x];
    lenn[x] = lenn[y];
    lenn[y] = temp;
    bool t = exist[x];
    exist[x] = exist[y];
    exist[y] = t;
}
LL calc(int zero) {
    LL ans = 0, x = 26, xx;
    for (int i = 0; i < 26; ++i) {
        if (zero == i) xx = 0;
        else { --x; xx = x; }
        LL mul = 0;
        for (int j = 0; j <= lenn[i]; ++j) {
            mul += (poww(26, j) * (LL)tot[i][j]) % mod;
            mul %= mod;
        }
        mul *= xx;
        mul %= mod;
        ans += mul;
        ans %= mod;
    }
    return ans;
}
void work() {
    memset(tot, 0, sizeof(tot));
    memset(exist, 0, sizeof(exist));
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int len = strlen(s);
        for (int j = 0; j < len; ++j) ++tot[s[j] - 'a'][len - j - 1];
        exist[s[0] - 'a'] = true;
    }
    for (int i = 0; i < 26; ++i) {
        int j;
        for (j = maxn; j >= 0; --j) {
            if (tot[i][j] > 0) break;
        }
        lenn[i] = j;
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j <= lenn[i]; ++j) {
            if (tot[i][j] >= 26) {
                tot[i][j + 1] += tot[i][j] / 26;
                tot[i][j] %= 26;
            }
        }
        while (tot[i][lenn[i] + 1] > 0) ++lenn[i];
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            if (lessthan(i, j)) {
                swapp(i, j);
            }
        }
    }

//    for (int i = 0; i < 26; ++i) {
//        for (int j = 0; j <= lenn[i]; ++j) {
//            printf("%d ", tot[i][j]);
//        }
//        if (lenn[i] >= 0) printf("\n");
//    }
//    printf("%d\n", zero);

    int zero = -1;
    if (lenn[25] >= 0) {
        for (int j = 25; j >= 0; --j) {
            if (!exist[j] || lenn[j] == 0) {
                zero = j;
                break;
            }
        }
    }
    LL ans = calc(zero);

    printf("Case #%d: %lld\n", ++kas, ans % mod);
}
int main() {
    while (scanf("%d\n", &n) != EOF) work();
    return 0;
}
