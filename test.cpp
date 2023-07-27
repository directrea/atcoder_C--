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

struct SegmentTree {
  vec<int> dat = vec<int>(3000000, 0);
  int siz = 1;
  SegmentTree(int n) {
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

int main() {
  int n, qn;
  cin >> n >> qn;
  vec<tuple<int, int, int>> qs(qn);
  for (auto&& [q, l, r] : qs) {
    cin >> q >> l >> r;
  }
  auto seg = SegmentTree(n);
  for (tuple<int, int, int> q : qs) {
    if (get<0>(q) == 1)
      seg.update(get<1>(q), get<2>(q));
    else
      print(seg.query(get<1>(q), get<2>(q), 1, seg.siz + 1));
  }

  return 0;
}