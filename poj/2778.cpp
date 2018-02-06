#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#define SIZE 4
#define maxn 110
using namespace std;
typedef long long LL;
char s[12];
int son[maxn][4], fail[maxn], flag[maxn], mp[maxn], mp2[maxn], tot, mat[maxn][maxn];
void add(char* s, int len) {
    int p = 0;
    for (int i = 0; i < len; ++i) {
        if (son[p][mp[s[i]]] == -1) {
            flag[++tot] = 0;
            for (int j = 0; j < SIZE; ++j) son[tot][j] = -1;
            son[p][mp[s[i]]] = tot;
        }
        p = son[p][mp[s[i]]];
    }
    flag[p] = 1;
}
void build() {
    queue<int> que;
    fail[0] = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (son[0][i] == -1) son[0][i] = 0;
        else {
            fail[son[0][i]] = 0;
            que.push(son[0][i]);
        }
        ++mat[0][son[0][i]];
    }
    while (!que.empty()) {
        int x = que.front(); que.pop();
        for (int i = 0; i < SIZE; ++i) {
            if (son[x][i] == -1) son[x][i] = son[fail[x]][i];
            else {
                fail[son[x][i]] = son[fail[x]][i];
                flag[son[x][i]] |= flag[fail[son[x][i]]];
                que.push(son[x][i]);
            }
            ++mat[x][son[x][i]];
        }
    }
}
void init() {
    mp['A'] = 0, mp['T'] = 1, mp['C'] = 2, mp['G'] = 3;
    flag[tot = 0] = 0;
    for (int i = 0; i < SIZE; ++i) son[0][i] = -1;
}
int cnt;
const LL mod = 100000;
typedef struct {
    LL mat[maxn][maxn];
    void init(LL x){
        memset(mat, 0, sizeof(mat));
        for(int i=0; i<cnt; i++) mat[i][i] = x;
    }
} Matrix;
Matrix m0;
LL addl(LL a, LL b) { return (a + b + mod) % mod; }
LL mull(LL a, LL b) { return a * b % mod; }
Matrix mulm(const Matrix& a, const Matrix& b) {
    Matrix temp;
    temp.init(0);
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            for (int k = 0; k < cnt; ++k) temp.mat[i][j] = addl(temp.mat[i][j], mull(a.mat[i][k], b.mat[k][j]));
        }
    }
    return temp;
}
Matrix poww(LL n) {
    Matrix a = m0, ret;
    ret.init(1);
    while (n) {
        if (n & 1) ret = mulm(ret, a);
        a = mulm(a, a);
        n >>= 1;
    }
    return ret;
}
int main() {
//    freopen("in.txt", "r", stdin);
    int m; LL n;
    scanf("%d%lld", &m, &n);
    init();
    for (int i = 0; i < m; ++i) {
        scanf("%s", &s);
        add(s, strlen(s));
    }
    build();
    cnt=0;
    for (int i = 0; i <= tot; ++i) if (!flag[i]) mp2[cnt++] = i;
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            m0.mat[i][j] = mat[mp2[i]][mp2[j]];
        }
    }

    Matrix fnl = poww(n);
    LL ans=0;
    for (int i = 0; i < cnt; ++i) ans = addl(ans, fnl.mat[0][i]);
    printf("%lld\n", ans);
    return 0;
}
