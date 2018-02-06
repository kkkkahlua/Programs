#include <bits/stdc++.h>
#define PI acos(-1.0)
#define maxn 140010
#define maxl 50010
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
struct Complex {
    double real, image;
    Complex(double _real = 0, double _image = 0) : real(_real), image(_image) {}
};
Complex operator + (const Complex& c1, const Complex& c2) { return Complex(c1.real + c2.real, c1.image + c2.image); }
Complex operator - (const Complex& c1, const Complex& c2) { return Complex(c1.real - c2.real, c1.image - c2.image); }
Complex operator * (const Complex& c1, const Complex& c2) { return Complex(c1.real * c2.real - c1.image * c2.image, c1.real * c2.image + c2.real * c1.image); }
ostream& operator << (ostream& out, Complex c) { out << c.real << "+ i * " << c.image << endl;}
Complex a[maxn], b[maxn], A[maxn];
char s1[maxl], s2[maxl];
int ans[maxn];
int rev(int x, int len) {
    int ret = 0, mask = 1;
    for (int i = 0; i < len; ++i) {
        ret <<= 1;
        if (mask & x) ret |= 1;
        mask <<= 1;
    }
    return ret;
}
void dft(Complex* a, int len, int D) {
    int h = (int)((double)log(len) / log(2) + 0.5);
    for (int i = 0; i < len; ++i) {
        A[rev(i, h)] = a[i];
    }
//    for (int i = 0; i < len; ++i) cout << A[i]; cout << "\n";
    for (int s = 1; s <= h; ++s) {
        int m = 1 << s;
        Complex wm = Complex(cos(D * 2 * PI / m), sin(D * 2 * PI / m));
        for (int k = 0; k < len; k += m) {
            Complex w = Complex(1, 0);
            for (int j = 0; j < (m >> 1); ++j) {
                Complex temp = w * A[k + j + (m >> 1)];
                Complex ori = A[k + j];
                A[k + j] = ori + temp;
                A[k + j + (m >> 1)] = ori - temp;
                w = w * wm;
            }
        }
    }
    if (D == -1) {
        for (int i = 0; i < len; ++i) A[i].real /= len, A[i].image /= len;
    }
    for (int i = 0; i < len; ++i) a[i] = A[i];
}
void work() {
    int len1 = strlen(s1), len2 = strlen(s2), len = len1 + len2;
    int n = 1;
    while (n < len) n <<= 1;
    len = n;
    memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
    for (int i = 0; i < len1; ++i) a[i] = Complex(s1[len1 - 1 - i] - '0', 0);
    for (int i = 0; i < len2; ++i) b[i] = Complex(s2[len2 - 1 - i] - '0', 0);
    dft(a, len, 1); dft(b, len, 1);
    for (int i = 0; i < len; ++i) a[i] = a[i] * b[i];
    dft(a, len, -1);
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < len; ++i) ans[i] = (int)(a[i].real + 0.5);
    for (int i = 0; i < len; ++i) {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    if (ans[len]) ++len;
    int i = len - 1;
    while (i >= 0 && !ans[i]) --i;
    if (i == -1) { printf("0\n"); return; }
    for (; i >= 0; --i) printf("%d", ans[i]);
    printf("\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%s%s", s1, s2) != EOF) work();
    return 0;
}
