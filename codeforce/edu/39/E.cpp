#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200010
using namespace std;
typedef long long LL;
int pre[maxn][10], non[maxn], a[10], len;
char s[maxn];
bool check(int x) {
    int cnt=0;
    F2(i, 0, 9) if (pre[x][i]&1) a[cnt++]=i;
    int p=len-cnt;
    if (p<=x) return false;
    if (non[p-1]-non[x]) return true;
    F(i, p, len) {
        if (s[i]-'0'>a[i-p]) return true;
        else if (s[i]-'0'<a[i-p]) return false;
    }
    return false;
}
void work() {
    scanf("%s", s);
    len=strlen(s);
    F2(i, 0, 9) pre[0][i]=0;
    ++pre[0][s[0]-'0'];
    non[0]=s[0]=='0'?0:1;
    F(i, 1, len) {
        F2(j, 0, 9) pre[i][j]=pre[i-1][j];
        ++pre[i][s[i]-'0'];
        non[i]=non[i-1]+(s[i]!='0');
    }
//    F(i, 0, len) printf("%d ", non[i]); puts("");
//    F(i, 0, len) {
//        F2(j, 0, 9) printf("%d ", pre[i][j]); puts("");
//    }
    F(i, 0, len) {
        if (!check(i)) {
//            printf("%d\n", i);
            if (!i&&s[i]=='1') { F(j, 0, len-2) putchar('9'); puts(""); return; }
            if (i) {
                int cnt=0;
                F2(x, 0, 9) if (pre[i-1][x]&1) ++cnt;
                if (len-i==cnt) {
                    dF2(x, s[i]-1-'0', 0) {
                        if (pre[i-1][x]&1) {
                            s[i]='0'+x, pre[i-1][x]=0;
                            break;
                        }
                    }
                    int p=len-1;
                    F2(x, 0, 9) if (pre[i-1][x]&1) s[p--]='0'+x;
                    puts(s); return;
                }
            }
            --pre[i][s[i]-'0'];
            ++pre[i][--s[i]-'0'];
            int p=len-1;
            F2(x, 0, 9) if (pre[i][x]&1) s[p--]='0'+x;
            while (p>i) s[p--]='9';
            puts(s); return;
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
