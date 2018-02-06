#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[5010];
bool dp[5010][5010];
bool ok(int l, int r) {
    if (s[l]=='(') {
        if (s[r]==')' || s[r]=='?') return true;
    }
    else if (s[l]=='?') {
        if (s[r]==')' || s[r]=='?') return true;
    }
    return false;
}
vector<int> l[5010], r[5010];
int main() {
    freopen("in.txt", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%s", s);
    int len = strlen(s), cnt=0;
    for (int i = 0; i <= len-2; ++i) {
        if (ok(i,i+1)) {
//            printf("%d %d\n", i, i+1);
            dp[i][i+1] = true, ++cnt;
            r[i+1].push_back(i);
            l[i].push_back(i+1);
        }
    }
    for (int i = 2; i <= len; i += 2) {
        for (int s = 0; ; ++s) {
            int t = s+i-1;
            if (t >= len) break;
            if (dp[s][t]) {
                if (t+1 < len && !l[t+1].empty()) {
                    for (auto x : l[t+1]) {
                        if (!dp[s][x]) {
                            dp[s][x] = true;
                            ++cnt;
                            l[s].push_back(x); r[x].push_back(s);
                        }
                    }
                }
                if (s-1 >= 0 && !r[s-1].empty()) {
                    for (auto x : r[s-1]) {
                        if (!dp[x][t]) {
                            dp[x][t] = true;
                            ++cnt;
                            l[x].push_back(t); r[t].push_back(x);
                        }
                    }
                }
                if (s-1 >= 0 && t+1 < len && ok(s-1,t+1)) {
                    if (!dp[s-1][t+1]) {
                        dp[s-1][t+1] = true;
                        ++cnt;
                        l[s-1].push_back(t+1); r[t+1].push_back(s-1);
                    }
                }
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
