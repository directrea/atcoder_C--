#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec vector
using ll = long long;
ll mod = 2147483647;
template <class T>
void print(T out, string end = "\n") {
  cout << out << end;
}
template <class T>
void print(vector<T> v) {
  for (unsigned long i = 0; i < v.size(); i++)
    cout << v[i] << " \n"[i == v.size() - 1];
}

struct RMQ {  //[l, r)の最大値
  vector<int> dat = vector<int>(3000000, 0);
  int siz = 1;
  RMQ(int n) {
    while (n > siz) siz <<= 1;
  }

  void update(int pos, int x) {
    pos += siz - 1;
    dat[pos] = x;
    while (pos >= 2) {
      pos /= 2;
      dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
    }
  }
  int query(int tl, int tr, int l, int r, int u = 1) {
    if (tr <= l || r <= tl) return INT32_MIN;
    if (tl <= l && r <= tr) return dat[u];
    int mid = (l + r) / 2;
    int lmax = query(tl, tr, l, mid, u * 2);
    int rmax = query(tl, tr, mid, r, u * 2 + 1);
    return max(lmax, rmax);
  }
};
void random_generate(int N, vector<int>& A) {
  // rand() % N + 1
  for (int i = 0; i < N; i++) A[i] = i + 1;
  shuffle(A.begin(), A.end(), mt19937(0));
}

vector<int> solve(int N, vector<int> a) {
  vec<int> res;
  auto seg = RMQ(N);
  rep(i, N) {
    int head = 1, tail = i + 1;
    while (head + 1 < tail) {
      int mid = (head + tail) / 2;
      if (seg.query(mid, i + 1, 1, seg.siz + 1) > a[i])
        head = mid;
      else
        tail = mid;
    }
    if (seg.query(head, i + 1, 1, seg.siz + 1) <= a[i])
      res.push_back(-1);
    else
      res.push_back(head);
    seg.update(i + 1, a[i]);
  }
  return res;
}

vector<int> solveSimple(int n, vector<int> a) {
  vector<int> res;
  for (int d = 0; d < n; d++) {
    int ans = -1;
    for (int i = d - 1; 0 <= i; i--) {
      if (a[i] > a[d]) {
        ans = i + 1;
        break;
      }
    }
    res.push_back(ans);
  }
  return res;
}

int main() {
  // for (int i = 0; i < 1000; i++) {
  //   int N = 10;
  //   vector<int> A(N);
  //   random_generate(N, A);
  //   auto j1 = solve(N, A);
  //   auto j2 = solveSimple(N, A);
  //   if (j1.size() == j2.size() && !equal(j1.begin(), j1.end(), j2.begin())) {
  //     print(A);
  //     print(j1);
  //     print(j2);
  //   }
  // }

  int n;
  cin >> n;
  vec<int> a(n);
  rep(i, n) cin >> a[i];
  auto j1 = solve(n, a);
  print(j1);
  return 0;
}
