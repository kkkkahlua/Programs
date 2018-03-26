#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
using namespace std;
typedef long long LL;
char s[maxn];
int mp[256], ch[30], a[maxn];
bool vis[256];
int main() {
//    freopen("in.txt", "r", stdin);
    int n, k, tot=0;
    scanf("%d%d", &n,&k);
    scanf("%s",s);
    int len = strlen(s);
    F(i, 0, len) {
        if (tot==26) break;
        if (!vis[s[i]]) {
            ch[tot++] = s[i];
            vis[s[i]] = true;
        }
    }
    sort(ch, ch+tot);
    F(i, 0, tot) mp[ch[i]] = i;
    if (k>len) {
        while (len<k) s[len++] = ch[0];
        s[len] = '\0';
        puts(s);
        return 0;
    }
    s[k] = '\0';
    F(i, 0, k) a[i] = mp[s[i]];
    int i = k-1;
    while (true) {
        ++a[i];
        if (a[i]<tot) break;
        a[i--] = 0;
    }
    F(i, 0, k) s[i] = ch[a[i]];
    puts(s);
    return 0;
}
