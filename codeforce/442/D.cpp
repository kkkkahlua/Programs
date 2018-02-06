#include <bits/stdc++.h>
#define maxn 1010
struct node { int x, y; };
int dr[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
char s[maxn];
using namespace std;
typedef long long LL;
bool mp[maxn][maxn];
int v[maxn][maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s+1);
        for (int j = 1; j <= m; ++j) {
            if (s[j] == '.') mp[i][j] = 0;
            else mp[i][j] = 1;
        }
    }
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1==x2&&y1==y2) { puts("0"); exit(0); }
    queue<node> q;
    while (!q.empty()) q.pop();
    q.push({x1,y1});
    while (!q.empty()) {
        node nd = q.front(); q.pop();
//        printf("%d %d\n", nd.x, nd.y);
        for (int i = 0; i < 4; ++i) {
            node temp = nd;
            int step = 0;
            while (step < k) {
                ++step;
                temp.x += dr[i][0], temp.y += dr[i][1];
                if (temp.x <= 0 || temp.x > n || temp.y <= 0 || temp.y > m || mp[temp.x][temp.y]) break;
                if (temp.x == x2 && temp.y == y2) { printf("%d\n", v[nd.x][nd.y]+1); exit(0); }
                if (!(temp.x==x1&&temp.y==y1) && !v[temp.x][temp.y]) v[temp.x][temp.y] = v[nd.x][nd.y] + 1, q.push({temp.x, temp.y});
            }
        }
    }
    printf("-1\n");
    return 0;
}
