#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define vec vector
using ll = long long;
template <class T> void print(T out, string end = "\n") { cout << out << end; }
template <class T> void print(vec<T> v) { rep(i, v.size()) cout << v[i] << " \n"[i == (int)v.size() - 1]; }

int main() {
  ll x, a, d, n;
  cin >> x >> a >> d >> n;

  auto solve = [&]() -> ll {
    ll ans = INT64_MAX;
    ans = min(ans, abs(x - a));
    ans = min(ans, abs(x - (a + d * (n - 1))));

    ll top = 0, tail = n;
    while (top + 1 < tail) {
      ll mid = (top + tail) / 2;
      ll tmp = abs(x - (a + d * mid));
      if (ans > tmp) {
        top = mid;
        ans = min(ans, tmp);
      } else
        tail = mid;
    }
    return ans;
  };
  print(solve());

  return 0;
}