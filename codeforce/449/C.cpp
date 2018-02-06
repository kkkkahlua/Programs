#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[110] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char A[110] = "What are you doing while sending \"";
char B[110] = "\"? Are you busy? Will you send \"";
char C[110] = "\"?";
int l1 = 34, l2 = 32, l3 = 2;
LL arr[60] = {75,218,504,1076,2220,4508,9084,18236,36540,73148,146364,292796,585660,1171388,2342844,4685756,9371580,18743228,37486524,74973116,149946300,299892668,599785404,1199570876,2399141820,4798283708,9596567484,19193135036,38386270140,76772540348,153545080764,307090161596,614180323260,1228360646588,2456721293244,4913442586556,9826885173180,19653770346428,39307540692924,78615081385916,157230162771900,314460325543868,628920651087804,1257841302175676,2515682604351420,5031365208702908,10062730417405884,20125460834811836,40250921669623740,80501843339247548,161003686678495164,322007373356990396,644014746713980860,1288029493427961788};
int main() {
//    freopen("in.txt", "r", stdin);
    int q;
    scanf("%d", &q);
    while (q--) {
        int n; LL k;
        scanf("%d%I64d", &n, &k);

        if (n > 53) {
            LL len = (n-53) * l1;
            if (k <= len) {
                k = (k-1) % l1 + 1;
                cout << A[k-1]; continue;
            }
            else {
                k -= len;
                n = 53;
            }
        }
        if (k > arr[n]) { cout << '.';  continue; }

        while (true) {
            if (n == 0) { cout << s[k-1]; break; }
            LL len1 = arr[n], len2 = arr[n-1];
            if (k <= l1) { cout << A[k-1]; break; }
            else if (k >= len1-l3+1) { cout << C[k-len1+l3-1]; break; }
            else if (k > l1+len2 && k <= l1+len2+l2) { cout << B[k-l1-len2-1]; break; }
            else {
                --n;
                if (k <= l1+len2) k -= l1;
                else k -= (l1+len2+l2);
            }
        }
    }
    puts("");
    return 0;
}
