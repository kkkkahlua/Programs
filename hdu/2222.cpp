#include <bits/stdc++.h>
#define maxn 1000010
#define maxm 55*10010
using namespace std;
char s2[maxn], s1[110];
int son[maxm][26], fail[maxm], cnt[maxm], tot;
void init() {
    cnt[tot = 0] = 0;
    for (int i = 0; i < 26; ++i) son[0][i] = -1;
}
void add(char* s, int len) {
    int p = 0;
    for (int i = 0; i < len; ++i) {
        if (son[p][s[i]-'a'] == -1) {
            cnt[++tot] = 0;
            for (int j = 0; j < 26; ++j) son[tot][j] = -1;
            son[p][s[i]-'a'] = tot;
        }
        p = son[p][s[i]-'a'];
    }
    ++cnt[p];
}
void build() {
    queue<int> que;
    fail[0] = 0;
    for (int i = 0; i < 26; ++i) {
        if (son[0][i] == -1) son[0][i] = 0;
        else {
            fail[son[0][i]] = 0;
            que.push(son[0][i]);
        }
    }
    while (!que.empty()) {
        int x = que.front(); que.pop();
        for (int i = 0; i < 26; ++i) {
            if (son[x][i] == -1) son[x][i] = son[fail[x]][i];
            else {
                fail[son[x][i]] = son[fail[x]][i];
                que.push(son[x][i]);
            }
        }
    }
}
int query(char* s, int len) {
    int p = 0, ret = 0;
    for (int i = 0; i < len; ++i) {
        p = son[p][s[i]-'a'];
        int temp = p;
        while (temp) {
            if (cnt[temp] == -1) break;
            ret += cnt[temp];
            cnt[temp] = -1;
            temp = fail[temp];
        }
    }
    return ret;
}
void work() {
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s1);
        add(s1, strlen(s1));
    }
    build();
    scanf("%s", s2);
    printf("%d\n", query(s2, strlen(s2)));
}
int main() {
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
