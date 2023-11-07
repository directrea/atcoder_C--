#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define vec vector
using ll = long long;
template <class T> void print(T out, string end = "\n") { cout << out << end; }
template <class T> void print(vec<T> &v) { rep(i, v.size()) cout << v[i] << " \n"[i == (int)v.size() - 1]; }

int main() {
  int n, q;
  cin >> n >> q;
  vec<int> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));

  rep(i, q) {
    int x;
    cin >> x;
    print(a.end() - lower_bound(all(a), x));
  }

  return 0;
}