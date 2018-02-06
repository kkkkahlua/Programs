//A

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
const int MAX = 1e9 + 7;
using namespace std;
int n, m;
typedef long long LL;
struct qnode {
	int v, c;
	qnode(int vv = 0, int cc = 0) : v(vv), c(cc) {}
	bool operator < (const qnode& r) const { return c > r.c; }
};
priority_queue<qnode> que;
bool vis[55];
int dist[55], deg[55], a[55][55];
void BFS(int src) {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n; ++j) {
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
	memset(vis, 0, sizeof(vis));
	memset(deg, 0, sizeof(deg));
	for (int i = 0; i < n; ++i) dist[i] = 10010;
	while (!que.empty()) que.pop();
	vis[src] = 1; dist[src] = 0;
	que.push(qnode(src, 0));
	int i;
	for (src, i = 1; i < n; ++i) {
//		cout << "src : " << src << endl;
		for (int j = 0; j < n; ++j) {
			if (a[src][j] == 0) continue;
			int temp = dist[src] + a[src][j];
			if (temp == dist[j]) ++deg[j];
			if (!vis[j] && temp < dist[j]) {
				deg[j] = 1; dist[j] = temp;
				que.push(qnode(j, dist[j]));
			}
		}
		while (!que.empty() && vis[que.top().v]) que.pop();
		if (que.empty()) break;
		vis[src = que.top().v] = 1;
		que.pop();
//	for (int i = 0; i < n; ++i) cout << deg[i] << " ";
//	cout << endl;		
	}

}
void work() {
	char s[60];
	for (int i = 0; i < n; ++i) {
		gets(s);
		for (int j = 0; s[j] != '\0'; ++j) a[i][j] = s[j] - '0';
	}
	BFS(0);
	LL ans = 1;
	for (int i = 1; i < n; ++i) ans = (ans * (LL)deg[i]) % MAX;
	printf("%I64d\n", ans);
}	
int main() {
	int T;
	scanf("%d", &T);
	while (scanf("%d\n", &n) != EOF) work();
	return 0;
}
