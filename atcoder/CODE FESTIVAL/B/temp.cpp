#include <bits/stdc++.h>

using namespace std;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using llint = int;

const int N = 4010, B = 1e9 + 7;

llint c[N][N];
llint d[N][N];
llint tmp[N][N];
llint tmpd[N][N];

void add(llint &a, llint b) {
  a = (a + b) % B;
  if (a < 0) a += B;
}

llint mul(llint a, llint b) {
  a %= B;
  b %= B;
  return 1ll * a * b % B;
}

void run() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0) c[i][j] = 1;
      else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % B;
    }
  }
  //debug(c[2][0], c[2][1]);

  for (int i = 0; i < N; ++i) {
    d[i][0] = c[i][0];
    for (int j = 1; j < N; ++j) {
      d[i][j] = (d[i][j - 1] + c[i][j]) % B;
    }
  }

  for (int q = 0; q < N; ++q) {
    for (int s = 1; s < N; ++s) {
      tmp[q][s] = d[q - 1][min(s - 1, q - 1)];
    }
  }

  for (int q = 0; q < N; ++q) {
    for (int s = 1; s < N; ++s) {
      tmpd[q][s] = (tmpd[q][s - 1] + tmp[q][s]) % B;
    }
  }
  debug(d[2][1]);
  debug(tmp[3][2]);
  debug(tmpd[3][2]);

  int a, b;
  scanf("%d%d", &a, &b);

  llint ans = 0;

  for (int p = 0; p <= a; ++p) {
    for (int q = 0; q <= b - 1; ++q) {
      if (p + q <= a) {
        if (q == 0) add(ans, 1);
        else {
          //t = p + q + 1
          //debug(p, q, c[b - 1][q], tmpd[q][p + 1], mul(c[b - 1][q], tmpd[q][p + 1]));
          add(ans, mul(c[b - 1][q], tmpd[q][p + 1]));
        }
      }
    }
  }

    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) printf("%d ", tmp[i][j]); printf("\n");
    }
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) printf("%d ", tmpd[i][j]); printf("\n");
    }

  printf("%d\n", ans);
}

int main() {
  run();
  return 0;
}
