/* HDU 1003 Max Sum --- ����DP */
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
    int fst, lst, maxSum; //��¼��λλ���Լ�����
    int start; //start�����ڼ�¼�м�仯������
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
            //�����Ǵ�ǰ������µģ�����ʡ��һ��dp����
            if (dp[i-1] >= 0){
                dp[i] = dp[i - 1] + dp[i];
            }
            else{
                start = i; //����dp[i-1]������㷢���仯
            }

            if (dp[i] > maxSum){
                //����ǰ��õ������к���󣬽��и���
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
