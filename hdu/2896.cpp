#include <bits/stdc++.h>
#define maxn 10010
#define maxm 100010
using namespace std;
typedef long long LL;
int son[maxm][128], fail[maxm], flag[maxm], tot;
char s[maxn];
vector<int> v;
void add(char* s, int len, int id) {
    int p = 0;
    for (int i = 0; i < len; ++i) {
        if (son[p][s[i]] == -1) {
            flag[++tot] = 0;
            for (int j = 0; j < 128; ++j) son[tot][j] = -1;
            son[p][s[i]] = tot;
        }
        p = son[p][s[i]];
    }
    flag[p] = id;
}
void build() {
    queue<int> que;
    fail[0] = 0;
    for (int i = 0; i < 128; ++i) {
        if (son[0][i] == -1) son[0][i] = 0;
        else {
            fail[son[0][i]] = 0;
            que.push(son[0][i]);
        }
    }
    while (!que.empty()) {
        int x = que.front(); que.pop();
        for (int i = 0; i < 128; ++i) {
            if (son[x][i] == -1) son[x][i] = son[fail[x]][i];
            else {
                fail[son[x][i]] = son[fail[x]][i];
                que.push(son[x][i]);
            }
        }
    }
}
int query(char* s, int len) {
    int p = 0;
    for (int i = 0; i < len; ++i) {
        p = son[p][s[i]];
        int temp = p;
        while (temp) {
//            printf("%d %d\n", temp, flag[temp]);
            if (flag[temp]) {
                v.push_back(flag[temp]);
            }
            temp = fail[temp];
        }
    }
    return v.size();
}
void init() {
    fail[tot = 0] = 0;
    for (int i = 0; i < 128; ++i) son[0][i] = -1;
}
int main() {
    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; ++i) scanf("%s", s), add(s, strlen(s), i);
    build();

    int ans=0;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        v.clear();
        scanf("%s", s);
        int num = query(s, strlen(s));
        if (num) {
            ++ans;
            printf("web %d:", i);
            sort(v.begin(), v.end());
            for (auto x : v) printf(" %d", x); puts("");
        }
    }
    printf("total: %d\n", ans);
    return 0;
}
