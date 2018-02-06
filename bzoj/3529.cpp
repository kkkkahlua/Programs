#include <bits/stdc++.h>
#define maxn 100000
#define maxm maxn + 10
using namespace std;
typedef long long LL;
int mu[maxm], prime[maxm], id[maxm], id2[maxm], n[maxm], m[maxm], a[maxm];
LL sum[maxm], t[maxm], mx[maxm], rec[maxm], c[maxm];
bool check[maxm];
const LL mod = (1 << 31) - 1;
int ptr = 1;
void mobius() {
    int tot = 0;
    sum[1] = mu[1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            mu[i] = -1;
            sum[i] = i + 1, mx[i] = i, t[i] = i + 1;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                mx[i * prime[j]] = mx[i] * prime[j];
                t[i * prime[j]] = (t[i] + mx[i * prime[j]]) % mod;
                sum[i * prime[j]] = sum[i] / t[i] * t[i * prime[j]] % mod;
                break;
            }
            mu[i * prime[j]] = -mu[i];
            mx[i * prime[j]] = prime[j];
            t[i * prime[j]] = prime[j] + 1;
            sum[i * prime[j]] = sum[i] * (prime[j] + 1) % mod;
        }
    }
}
int lowbit(int x) { return x & (-x); }
void add(int x, LL y) {
    for (int i = x; i <= maxn; i += lowbit(i)) c[i] += y;
}
LL query(int x) {
    if (x == 0) return 0;
    LL ret = 0;
    for (int i = x; i; i -= lowbit(i)) ret += c[i];
    return ret;
}
void work(int idx) {
    int nn = n[id[idx]], mm = m[id[idx]], aa = a[id[idx]];
    for (; ptr <= maxn && sum[id2[ptr]] <= aa; ++ptr) {
        for (int k = 1; k * id2[ptr] <= maxn; ++k) {
            add(k * id2[ptr], mu[k] * sum[id2[ptr]]);
        }
    }
    int lim = min(nn, mm), le, ri;
    LL ans = 0;
    for (int i = 1; i <= lim; i = ri + 1) {
        le = i, ri = min(nn / (nn / i), mm / (mm / i));
        ans += (query(ri) - query(le - 1)) * (nn / i) * (mm / i);
    }
    rec[id[idx]] = ans;
}
bool cmp(int i, int j) { return a[i] < a[j]; }
bool cmp2(int i, int j) { return sum[i] < sum[j]; }
int main() {
    mobius();
//    for (int i = 1; i <= 20; ++i) printf("%lld ", sum[i]); printf("\n");
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d%d%d", &n[i], &m[i], &a[i]);
        id[i] = i;
    }
    sort(id, id + T, cmp);
    for (int i = 1; i <= maxn; ++i) id2[i] = i;
    sort(id2 + 1, id2 + maxn + 1, cmp2);
    for (int i = 0; i < T; ++i) work(i);
    for (int i = 0; i < T; ++i) printf("%lld\n", rec[i] & 0x7FFFFFFF);
    return 0;
}
