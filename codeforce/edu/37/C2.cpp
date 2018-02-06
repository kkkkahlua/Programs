#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
char s[maxn];
int a[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("%s", s);
    int l = -1; bool flag = false;
    for (int i = 0; i < n-1; ++i) {
        if (flag && s[i]=='0') {
            sort(a+l, a+i+1);
            flag = false;
        }
        else if (!flag && s[i]=='1') l = i, flag = true;
    }
    if (flag) sort(a+l, a+n);
    for (int i = 0; i < n; ++i) if (a[i]!=i+1) { puts("NO"); return 0; }
    puts("YES");
    return 0;
}
