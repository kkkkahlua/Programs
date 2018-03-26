#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int main() {
    ifstream fin("in.txt");
    ifstream fin2("out.txt");
    int n;
    fin >> n;
    vector<LL> v(n, 0);
    F(i, 0, n) fin >> v[i];
    LL sum;
    int m;
    fin2 >> sum >> m;
    F(i, 0, m) {
        int x;
        fin2 >> x; --x;
        printf("%d %d %d\n", i, x, v.size());
        if (!x) v.erase(v.begin());
        else if (x==v.size()-1) {
            v.erase(v.begin()+x);
        }
        else v[x]=v[x-1]+v[x+1], v.erase(v.begin()+x-1), v.erase(v.begin()+x);
        for (auto mm : v) printf("%d ", mm); puts("");
    }
    assert(v.size()==1);
    assert(v[0]==sum);
    return 0;
}
