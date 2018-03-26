#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 110
using namespace std;
typedef long long LL;
struct Point {
    int x,y,type;
    bool operator < (const Point& p) const { return x < p.x; }
}a[maxn<<1];
set<int> st;
int main() {
    int n;
    scanf("%d", &n);
    F(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y), a[i].type=0;
    F(i, 0, n) scanf("%d%d", &a[n+i], &a[n+i].y), a[n+i].type=1;
    sort(a, a+(n<<1));
    int ans=0;
    F(i, 0, n<<1) {
        if (a[i].type) {
            auto it = st.lower_bound(a[i].y);
            if (it==st.begin()) continue;
            else st.erase(--it), ++ans;
        }
        else {
            st.insert(a[i].y);
        }
    }
    printf("%d\n", ans);
    return 0;
}
