#include <bits/stdc++.h>
#define maxn 1010
#define maxm 100010
#define maxl 2000010
#define SIZE 128
using namespace std;
typedef long long LL;
int son[maxn*55][SIZE], fail[maxn*55], cnt[maxn*55], ans[maxn], tot;
char ss[maxl], s[maxn][55];
void add(char* s, int len, int id) {
    int p = 0;
    for (int i = 0; i < len; ++i) {
        if (son[p][s[i]] == -1) {
            cnt[++tot] = 0;
            for (int j = 0; j < SIZE; ++j) son[tot][j] = -1;
            son[p][s[i]] = tot;
        }
        p = son[p][s[i]];
    }
    cnt[p] = id;
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
    }
    while (!que.empty()) {
        int x = que.front(); que.pop();
        for (int i = 0; i < SIZE; ++i) {
            if (son[x][i] == -1) son[x][i] = son[fail[x]][i];
            else {
                fail[son[x][i]] = son[fail[x]][i];
                que.push(son[x][i]);
            }
        }
    }
}
void query(char* s, int len) {
    int p = 0;
    for (int i = 0; i < len; ++i) {
        p = son[p][s[i]];
        int temp = p;
        while (temp) {
            if (cnt[temp]) ++ans[cnt[temp]];
            temp = fail[temp];
        }
    }
}
void init() {
    cnt[tot = 0] = 0;
    for (int i = 0; i < SIZE; ++i) son[0][i] = -1;
    memset(ans, 0, sizeof ans);
}
int n;
void work() {
    init();
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i]);
        add(s[i], strlen(s[i]), i);
    }
    build();
    scanf("%s", ss);
    query(ss, strlen(ss));
    for (int i = 1; i <= n; ++i) if (ans[i]) printf("%s: %d\n", s[i], ans[i]);
}
int main() {
//    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
