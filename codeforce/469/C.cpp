#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 400010
using namespace std;
char s[maxn];
set<int> st[2];
vector<int> v[maxn];
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    scanf("%s", s);
    int len = strlen(s);
    F(i, 0, len) {
        if (s[i]=='0') st[0].insert(i);
        else st[1].insert(i);
    }
    int cnt=-1;
    int count=0, temp=-1;
    while (true) {
        if (st[1].size()==temp || !st[0].size() || !st[1].size()) {
            if (st[1].size()) puts("-1");
            else {
                printf("%d\n", cnt+1+st[0].size());
                F2(i, 0, cnt) {
                    printf("%d ", v[i].size());
                    for (auto x : v[i]) printf("%d ", x+1); puts("");
                }
                for (auto x : st[0]) printf("%d %d\n", 1, x+1);
            }
            break;
        }
        temp = st[1].size();
        int cur=0, x=-1;
        ++cnt;
        while (true) {
            auto it = st[cur].lower_bound(x);
            if (it == st[cur].end()) {
                if (cur==0) {
                    st[1].insert(x);
                    v[cnt].pop_back();
                }
                break;
            }
            else {
                v[cnt].push_back(*it);
                x = *it;
                st[cur].erase(it);
                cur = !cur;
            }
        }
    }
    return 0;
}
