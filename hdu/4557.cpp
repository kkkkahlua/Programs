#include <bits/stdc++.h>
using namespace std;
queue<int> q[22];
map<int, int> mp;
char op[20], name[1010][15];
void work() {
    for (int i = 1; i <= 20; ++i) while (!q[i].empty()) q[i].pop();
    mp.clear();
    int n;
    scanf("%d", &n);
    int num = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", op);
        int x;
        if (op[0] == 'A') {
            ++num; printf("%d\n", num);
            scanf("%s%d", name[i], &x);
            q[x].push(i);
            ++mp[x];
        }
        else if (op[0] == 'F') {
            scanf("%d", &x);
            auto it = mp.lower_bound(x);
            if (it == mp.end()) printf("WAIT...\n");
            else {
                printf("%s\n", name[q[it->first].front()]);
                q[it->first].pop();
                --num, --mp[it->first];
                if (mp[it->first] == 0) mp.erase(it);
            }
        }
    }
}
int kas;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d:\n", ++kas);
        work();
    }
    return 0;
}
