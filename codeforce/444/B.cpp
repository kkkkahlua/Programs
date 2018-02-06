#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[10][10], n;
bool exist[10][10];
bool check(int x) {
    if (x<10) {
        for (int i = 0; i < n; ++i) if (exist[i][x]) return true;
        return false;
    }
    if (x<100) {
        int hi=x/10, lo=x%10;
        if (n==1) return false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i==j) continue;
                if (exist[i][hi] && exist[j][lo]) return true;
            }
        }
        return false;
    }
    int x1=x/100, x2=x%100/10, x3=x%10;
    if (n<=2) return false;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            for (int k=0; k<n; ++k) {
                if (i==j || i==k || j==k) continue;
                if (exist[i][x1] && exist[j][x2] && exist[k][x3]) return true;
            }
        }
    }
    return false;
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) scanf("%d", &a[i][j]), exist[i][a[i][j]] = true;
    }
    int i = 1;
    for (; i <= 999; ++i) {
        if (!check(i)) break;
    }
    printf("%d\n", i-1);
    return 0;
}
