#include <bits/stdc++.h>
#define maxn 100010
typedef long long LL;
char ans[maxn], s[maxn];
int a[26][26], in[26], out[26], tot, to[26];
bool exist[26];
using namespace std;
void dfs(int u) {
    exist[u] = false;
    ans[tot++] = 'a'+u;
    if (~to[u]) dfs(to[u]);
}
int main() {
    memset(to, -1, sizeof to);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int len = strlen(s);
        for (int j = 0; j < len-1; ++j) {
            int u = s[j]-'a', v = s[j+1]-'a';
            if (a[u][v]) continue;
            a[u][v] = true;
            to[u] = v;
            ++out[u], ++in[v];
            exist[v] = true;
        }
        exist[s[0]-'a'] = true;
    }
    for (int i = 0; i < 26; ++i) if (in[i] > 1 || out[i] > 1) { puts("NO"); exit(0); }
    for (int i = 0; i < 26; ++i) {
        if (!in[i] && exist[i]) dfs(i);
    }
    for (int i = 0; i < 26; ++i) if (exist[i]) { puts("NO"); exit(0); }
    ans[tot++] = '\0';
    puts(ans);
    return 0;
}
