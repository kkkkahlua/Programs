/* HDU 1003 Max Sum --- 经典DP */
#include <cstdio>
#include <cstring>

int dp[100005];

int main()
{
#ifdef _LOCAL
    freopen("D:\\input.txt", "r", stdin);
#endif
    freopen("in.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    int t, n;
    int kase = 0;
    int fst, lst, maxSum; //记录首位位置以及最大和
    int start; //start是用于记录中间变化的起点的
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
            scanf("%d", dp + i);
        }//for(i)

        start = fst = lst = 0;
        maxSum = dp[0];
        for (int i = 1; i < n; ++i){
            //dp[i] = MAX(dp[i - 1] + dp[i], dp[i]);
            //由于是从前往后更新的，可以省下一个dp数组
            if (dp[i-1] >= 0){
                dp[i] = dp[i - 1] + dp[i];
            }
            else{
                start = i; //抛弃dp[i-1]，则起点发生变化
            }

            if (dp[i] > maxSum){
                //若当前求得的子序列和最大，进行更新
                maxSum = dp[i];
                fst = start;
                lst = i;
            }
        }
        if (kase){
            printf("\n");
        }
        printf("Case %d:\n", ++kase);
        printf("%d %d %d\n", maxSum, fst+1, lst+1);
    }

    return 0;
}
