#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
#define LL long long
#define MAX 100010
using namespace std;

typedef pair<LL, int> p;
LL a[MAX], t, ans, tmp, b;
int n, k, l, u, st, en;
p sum[MAX];

LL myabs(LL x)
{
    return x>=0? x:-x;
}

int main()
{
    freopen("2566.in", "r", stdin);
    freopen("25663.out", "w", stdout);
    while (scanf("%d %d", &n, &k), n+k){
        sum[0] = p(0, 0);
        for (int i = 1; i <= n; i++){
            scanf("%I64d", a+i);
            sum[i] = p(sum[i-1].first+a[i], i);
        }
        sort(sum, sum+1+n);
        while (k--){
            scanf("%I64d", &t);
            tmp = INF; st = 0, en = 1;
            while(en <= n){
                b = sum[en].first-sum[st].first;
                if(myabs(t-b) < tmp){
                    tmp = myabs(t-b);
                    ans = b;
                    l = sum[st].second; u = sum[en].second;
                }
                if(b > t) st++;
                else if(b < t) en++;
                else break;
                if(st == en) en++;
            }
            if (u < l) swap(u, l);
            printf("%I64d %d %d\n", ans, l+1, u);
        }
    }
    return 0;
}
