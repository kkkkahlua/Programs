#include <bits/stdc++.h>
#define SIZE 26
#define maxn 32
using namespace std;
typedef unsigned long long ULL;
int cnt;
typedef struct {
    ULL mat[maxn<<1][maxn<<1];
    void init(ULL x, int cnt){
        memset(mat, 0, sizeof(mat));
        for(int i=0; i<cnt; i++) mat[i][i] = x;
    }
    void print(int cnt) const {
        for (int i = 0; i < cnt; ++i) {
            for (int j = 0; j < cnt; ++j) printf("%lld ", mat[i][j]); printf("\n");
        }
    }
} Matrix;
Matrix m0, m1, m2;
ULL add(ULL a, ULL b) { return a + b; }
ULL mul(ULL a, ULL b) { return a * b; }
Matrix mulm(const Matrix& a, const Matrix& b, int cnt) {
    Matrix temp;
    temp.init(0, cnt);
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            for (int k = 0; k < cnt; ++k) temp.mat[i][j] = add(temp.mat[i][j], mul(a.mat[i][k], b.mat[k][j]));
        }
    }
    return temp;
}
Matrix addm(const Matrix& a, const Matrix& b, int cnt) {
    Matrix temp;
    temp.init(0, cnt);
    for (int i = 0; i < cnt; ++i) for (int j = 0; j < cnt; ++j) temp.mat[i][j] = add(a.mat[i][j], b.mat[i][j]);
    return temp;
}
Matrix poww(Matrix m, ULL n, int cnt) {
    Matrix a = m, ret;
    ret.init(1, cnt);
    while (n) {
        if (n & 1) ret = mulm(ret, a, cnt);
        a = mulm(a, a, cnt);
        n >>= 1;
    }
    return ret;
}
int son[maxn][SIZE], fail[maxn], tot;
ULL mat[maxn][maxn];
bool flag[maxn];
void insert(char* s, int len) {
    int p = 0;
    for (int i = 0; i < len; ++i) {
        if (son[p][s[i]-'a'] == -1) {
            flag[++tot] = 0;
            for (int j = 0; j < SIZE; ++j) son[tot][j] = -1;
            son[p][s[i]-'a'] = tot;
        }
        p = son[p][s[i]-'a'];
    }
    flag[p] = true;
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
    flag[tot = 0] = 0;
    memset(mat, 0, sizeof mat);
    memset(m0.mat, 0, sizeof m0.mat);
    memset(m1.mat, 0, sizeof m1.mat);
    memset(m2.mat, 0, sizeof m2.mat);
    for (int i = 0; i < SIZE; ++i) son[0][i] = -1;
}

int n, l;
char s[10];
int mp[maxn];
void work() {
    init();
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        insert(s, strlen(s));
    }
    build();

    cnt = 0;
    for (int i = 0; i <= tot; ++i) if (!flag[i]) mp[cnt++] = i;
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            m0.mat[i][j] = mat[mp[i]][mp[j]];
        }
    }

    for (int i = 0; i < cnt; ++i) m0.mat[i+cnt][i] = m0.mat[i+cnt][i+cnt] = 1;
    Matrix fnl = poww(m0, l, cnt<<1);
    for (int i = cnt; i < (cnt<<1); ++i) {
        for (int j = 0; j < cnt; ++j) {
            m1.mat[i-cnt][j] = fnl.mat[i][j];
            m2.mat[i-cnt][j] = fnl.mat[i][j+cnt];
        }
    }
    Matrix ret = addm(mulm(m1, m0, cnt), m2, cnt);
    ULL sub = 0;
    for (int i = 0; i < cnt; ++i) sub = add(sub, ret.mat[0][i]);

    Matrix mm;
    mm.mat[0][0] = 26, mm.mat[0][1] = 0, mm.mat[1][0] = 1, mm.mat[1][1] = 1;
    Matrix mmfnl = poww(mm, l, 2);
    ULL sum = add(mul(26, mmfnl.mat[1][0]), mmfnl.mat[1][1]);
    ULL ans = add(sum, -sub);
    printf("%I64u\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &l) != EOF) work();
    return 0;
}
