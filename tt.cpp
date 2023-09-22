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
  int N, M;
  cin >> N >> M;

  vec<vec<tuple<int, int, int>>> G(N);
  rep(i, M) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    a--, b--;
    G[a].push_back({b, x, y});
    G[b].push_back({a, -x, -y});
  }
  vec<bool> visited(N);
  vec<pair<int, int>> pos(N);
  auto dfs = [&](auto self, int now, ll nowx, ll nowy) {
    visited[now] = true;
    pos[now] = {nowx, nowy};
    for (auto &[next, x, y] : G[now]) {
      if (visited[next]) continue;
      self(self, next, nowx + x, nowy + y);
    }
  };

  dfs(dfs, 0, 0, 0);

  return 0;
}