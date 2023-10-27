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
  ll n;
  cin >> n;
  ll ans = 0, mod = 998244353;
  ll bias = 1;
  while (bias <= n / 10) {
    ll lf = (bias * 10 - bias) % mod;
    ans += lf * (lf + 1) / 2;
    ans %= mod;
    bias *= 10;
  }
  ans += ((n - bias + 1) % mod) * ((n - bias + 1 + 1) % mod) / 2;
  print(ans % mod);
  return 0;
}