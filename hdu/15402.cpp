#include <bits/stdc++.h>
#define maxn 50010
using namespace std;
stack<int> s;
bool brok[maxn];
set<int> st;
int n, m;
void work() {
    while (!s.empty()) s.pop();
    st.clear();
    memset(brok, 0, sizeof brok);
    while (m--) {
        char c; int x;
        scanf("\n%c", &c);
        if (c == 'D') {
            scanf("%d", &x);
            if (!brok[x]) {
                brok[x] = true;
                st.insert(x);
            }
            s.push(x);
        }
        else if (c == 'R') {
            if (s.empty()) continue;
            int x = s.top();
            if (brok[x]) {
                brok[x] = false;
                st.erase(x);
            }
            s.pop();
        }
        else {
            scanf("%d", &x);
            int ans;
            if (st.empty()) ans = n;
            else {
                auto p = lower_bound(st.begin(), st.end(), x);
                if (p == st.end()) ans = n - *(--p);
                else if (*p == x) ans = 0;
                else {
                    if (p == st.begin()) ans = *p - 1;
                    else ans = *p - *(--p) - 1;
                }
            }
            printf("%d\n", ans);
        }
    }
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
