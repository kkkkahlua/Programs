#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[110];
int cnt[110];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        for (int j = 0; j < m; ++j) ++cnt[s[j]-'a'];
    }
    int t2=0, t4=0;
    for (int i = 0; i < 26; ++i) {
        t4 += cnt[i]/4, t2 += cnt[i]%4/2;
    }
    if (!(n&1) && !(m&1)) {
        if (t4 >= n*m/4) printf("Yes\n");
        else printf("No\n");
    }
    else if (n&1 && m&1) {
        if (t4 >= (n-1)*(m-1)/4) {
            t2 += (t4-(n-1)*(m-1)/4)*2;
            if (t2 >= (n+m-2)/2) printf("Yes\n");
            else printf("No\n");
        }
        else printf("No\n");
    }
    else {
        if (n&1) swap(n, m);
        if (t4 >= n*(m-1)/4) {
            t2 += (t4-n*(m-1)/4)*2;
            if (t2 >= n/2) printf("Yes\n");
            else printf("No\n");
        }
        else printf("No\n");
    }
    return 0;
}
