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
  string s;
  cin >> s;
  auto f = [&](int l, int r) -> bool {
    bool res = true;
    map<char, int> mpcnt;
    for (int i = l; i <= r; i++) mpcnt[s[i]]++;
    for (auto &[key, val] : mpcnt)
      if (val % 2 == 1) res = false;
    return res;
  };
  ll ans = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      print(vec{i, j});
      if (f(i, j)) ans++;
    }
  }
  print(ans);
  return 0;
}