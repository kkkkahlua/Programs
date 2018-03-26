#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200010
using namespace std;
char s1[maxn], s2[maxn];
int pos1[maxn], pos2[maxn];
bool flag[maxn];
vector<int> v[maxn];
typedef long long LL;
int main() {
    freopen("in.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    scanf("%s", s1);
    int len1=strlen(s1), len2=0, cnt=-1;
    F(i, 0, len1) pos1[i] = i;
    while (true) {
        if (len1==0) {
            printf("%d\n", cnt+1);
            for (int i = 0; i <= cnt; ++i) {
                printf("%d ", v[i].size());
                for (auto x : v[i]) printf("%d ", x+1);
                puts("");
            }
            break;
        }
        flag[len1-1] = s1[len1-1]=='1';
        dF2(i, len1-2, 0) flag[i] = flag[i+1] & (s1[i]=='1');
        int cur=0; ++cnt;
        F(i, 0, len1) {
//            printf("in : %c %d\n", s1[i], cur);
            if (s1[i]-'0'==cur && !(cur==1&&flag[i])) {
                v[cnt].push_back(pos1[i]), cur = !cur;
            }
            else s2[len2] = s1[i], pos2[len2++] = pos1[i];
        }
//        for (auto x : v[cnt]) printf("%d ", x); puts("");
        if (v[cnt].empty()) { puts("-1"); return 0; }
        swap(s1, s2), len1=len2, len2=0;
        swap(pos1, pos2);
//        for (int i = 0; i < len1; ++i) printf("%c", s1[i]); puts("");
//        for (int i = 0; i < len1; ++i) printf("%d ", pos1[i]); puts("");
    }
    return 0;
}
