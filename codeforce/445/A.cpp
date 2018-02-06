#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[6];
int main() {
//    freopen("in.txt", "r", stdin);
    int sum=0;
    for (int i = 0; i < 6; ++i) scanf("%d", &a[i]), sum += a[i];
    for (int i = 0; i < 6; ++i) {
        for (int j = i+1; j < 6; ++j) {
            for (int k = j+1; k <6; ++k) if ((a[i]+a[j]+a[k])<<1==sum)  { puts("YES"); exit(0); }
        }
    }
    puts("NO");
    return 0;
}
