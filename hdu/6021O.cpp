#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
inline LL GCD(LL a, LL b){
    if(b == 0) return a;
    return GCD(b, a%b);
}
inline LL LCM(LL a, LL b){
    return a / GCD(a, b) * b;
}
LL Pow_Mod(LL a, LL b){
    LL ans = 1;
    while(b){
        if(b & 1) ans = (ans * a) % MOD;
        b>>=1LL;
        a = (a * a) % MOD;
    }
    return ans;
}
char str[30];
int a[30], vis[30], p[30];
/**
vis: 字母是否被标记过
a: 第 i 个字母将其转化为数字
p[i]:  字母经过 i 次可以变为本身的环的个数
*/
vector< pair<int, int> > vec;///first: 环的循环节长度 second: 循环节长度的个数
int main(){
    int T, cnt = 0;
    scanf("%d",&T);
    while(T--){
        LL n;
        scanf("%lld%s",&n, str+1);
        memset(vis, 0, sizeof(vis));
        memset(p, 0, sizeof(p));
        for(int i=1; i<27; i++) a[i] = (str[i] - 'a') + 1;
        vec.clear();
        for(int i=1; i<27; i++){
            if(!vis[i]){
                vis[i] = 1, cnt = 1;
                int tmp = i;
                while(a[tmp] != i){
                    tmp = a[tmp];
                    cnt++;
                    vis[tmp] = 1;
                }
                p[cnt]++;
            }
        }
        for(int i=1; i<27; i++) if(p[i]) vec.push_back(make_pair(i, p[i]));
        LL ans = 0; int m = vec.size();
        vector<int> vec1;///环中有多少个字母被选择
        for(int i=1; i<(1<<m); i++){
            LL ans1 = 1;
            vec1.clear();
            for(int j=0; j<m;  j++)
                if(i & (1<<j))
                    ans1 = LCM(ans1, vec[j].first), vec1.push_back(vec[j].first*vec[j].second);
            int mm = vec1.size();
            if(mm > n) continue;///剪枝
            LL ans2 = 0;
            for(int ii=1; ii<(1<<mm); ii++){
                int num = 0;    LL sum = 0;
                for(int jj=0; jj<mm; jj++)
                    if(ii & (1<<jj))    num++, sum += vec1[jj];
                if(num & 1)    ans2 += Pow_Mod(sum, n);
                else    ans2 -= Pow_Mod(sum, n);
                ans2 = (ans2 % MOD + MOD) % MOD;
            }
            if(mm & 1)
                ans = ans + ans1 * ans2 % MOD;
            else
                ans = ans - ans1 * ans2 % MOD;
            ans = (ans % MOD + MOD) % MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
