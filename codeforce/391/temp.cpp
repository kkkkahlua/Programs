#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX(a,b,c) max(a,max(b,c))

const int INF=0x7f7f7f7f;
const int MOD=1e9+7;
const int N=100;
int num[N][N];
int dp[N][(1<<20)+10];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        for(int j=i,k=0;j<n;j++)
        if((k=(k<<1)+s[j]-'0')>20)break;
        else num[i][j]=k;
    }

    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
        for(int j=0;j<(1<<20);j++)
        if(dp[i][j])
        {
            for(int k=i;k<n;k++)
            {
                if(num[i][k])dp[k+1][j|(1<<num[i][k]-1)]=(dp[k+1][j|(1<<num[i][k]-1)]+dp[i][j])%MOD;
            }
        }
    }

    int ans=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=20;j++)
        ans=(ans+dp[i][(1<<j)-1])%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
