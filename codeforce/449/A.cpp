#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
//    freopen("in.txt","r", stdin);
    int n, m, s,t ; char c1, c2;
    char ss[110];
    scanf("%d%d", &n, &m);
    scanf("%s", ss+1);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d %c %c", &s, &t, &c1, &c2);
        for (int j = s; j <= t; ++j) {
            if (ss[j] == c1) ss[j] = c2;
        }
    }
    printf("%s\n", ss+1);
    return 0;
}
