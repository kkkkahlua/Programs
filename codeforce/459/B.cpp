#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s1,s2,s3;
map<string,string> mp;
int main() {
//    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n,&m);
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        mp[s2] = s1;
//        cout << s1 << s2 << mp[s2] << endl;
    }
    while (m--) {
        cin >> s1 >> s2;
        s2[s2.size()-1] = '\0';
        s3 = s2.substr(0, s2.size()-1);
//        cout << s1 << endl << s3 << endl;
        cout << s1 << " " << s3 << "; #" << mp[s3] << endl;
    }
    return 0;
}
