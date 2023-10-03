#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define vec vector
using ll = long long;
template <class T> void print(T out, string end = "\n") { cout << out << end; }
template <class T> void print(vec<T> &v) { rep(i, v.size()) cout << v[i] << " \n"[i == (int)v.size() - 1]; }

void Rotater90(vec<vec<char>> &vv) {
  vec<vec<char>> res;
  rep(j, vv[0].size()) {
    vec<char> tmp;
    rep(i, vv.size()) tmp.push_back(vv[vv.size() - 1 - i][j]);
    res.push_back(tmp);
  }
  vv = res;
}
bool canPut(vec<vec<char>> &vv, int r, int c) {
  rep(i, vv.size()) {
    rep(j, vv[i].size()) {
      if (vv[i][j] != '#') continue;
      if (!(i + r >= 0 && i + r < 4 && j + c >= 0 && j + c < 4)) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  vec<vec<vec<char>>> ps(3, vec<vec<char>>(4, vec<char>(4)));
  rep(i, 3) rep(j, 4) rep(k, 4) cin >> ps[i][j][k];

  vec<vec<int>> cnt(4, vec<int>(4));
  auto dfs = [&](auto self, int idx) -> bool {
    if (idx == 3) {
      rep(i, 4) rep(j, 4) if (cnt[i][j] == 0 || cnt[i][j] > 1) return false;
      return true;
    }
    rep2(i, -3, 4) {
      rep2(j, -3, 4) {
        if (canPut(ps[idx], i, j)) {
          rep(k, 4) rep(l, 4) if (ps[idx][k][l] == '#') cnt[k + i][l + j]++;
          if (self(self, idx + 1)) return true;
          rep(k, 4) rep(l, 4) if (ps[idx][k][l] == '#') cnt[k + i][l + j]--;
        }
      }
    }
    return false;
  };
  bool ansb = false;
  rep(i, 4) {
    Rotater90(ps[1]);
    rep(j, 4) {
      Rotater90(ps[2]);
      ansb |= dfs(dfs, 0);
    }
  }
  if (ansb)
    print("Yes");
  else
    print("No");

  return 0;
}