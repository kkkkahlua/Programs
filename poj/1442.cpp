#include <cstdio>
#include <iostream>
#include <queue>
#define maxn 30010
using namespace std;
priority_queue<int, vector<int>, greater<int> > q2;
priority_queue<int> q1;
int n, m, a[maxn];
void work() {
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
    for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
    int p = 0, k = 1;
    while (n--) {
        int x;
        scanf("%d", &x);
        while (q1.size() < k && !q2.empty()) {
            q1.push(q2.top());
            q2.pop();
        }
        while (p < x) {
            int y = a[p++];
            if (q1.size() < k) q1.push(y);
            else {
                int temp = q1.top();
                if (temp <= y) q2.push(y);
                else {
                    q1.pop();
                    q1.push(y);
                    q2.push(temp);
                }
            }
        }
        ++k;
        printf("%d\n", q1.top());
    }
}
int main() {
    while (scanf("%d%d", &m, &n) != EOF) work();
    return 0;
}
