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

int main() {
  int n;
  cin >> n;

  ll start = 0;
  ll all = 0;
  vec<pair<ll, ll>> vp;
  rep(i, n) {
    ll x, y, z;
    cin >> x >> y >> z;
    all += z;
    if (x > y)
      start += z;
    else
      vp.push_back({(x + y) / 2 + 1 - x, z});
  }
  vec<vec<ll>> dp(vp.size() + 1, vec<ll>(all + 1, INT64_MAX));
  dp[0][start] = 0;
  rep(i, vp.size()) {
    auto& [dis, z] = vp[i];
    rep(j, dp[i].size()) {
      if (dp[i][j] == INT64_MAX) continue;
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      int next = min(all, j + z);
      dp[i + 1][next] = min(dp[i + 1][next], dp[i][j] + dis);
    }
  }
  ll ans = INT64_MAX;
  rep2(i, all / 2 + 1, dp[0].size()) { ans = min(ans, dp[dp.size() - 1][i]); }
  print(ans);

  return 0;
}