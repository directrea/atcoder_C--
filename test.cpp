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

std::default_random_engine gen;
int random(int low, int high) {
  std::uniform_int_distribution<> dist(low, high);
  return dist(gen);
}

int main() {
  ll n, m, p;
  cin >> n >> m >> p;

  vec<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  auto solve1 = [&]() -> ll {
    sort(all(b));
    vec<ll> psumb(b.size() + 1);
    rep(i, m) psumb[i + 1] = psumb[i] + b[i];

    ll ans = 0;
    for (ll sc : a) {
      ll tmp = p - sc;
      int bidx = lower_bound(all(b), tmp) - b.begin();
      ans += sc * bidx + psumb[bidx] + p * (b.size() - bidx);
    }
    return ans;
  };

  print(solve1());

  return 0;
}