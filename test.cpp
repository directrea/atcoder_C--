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

void Rotater90(vec<vec<char>> &vv) {
  vec<vec<char>> res;
  rep(j, vv[0].size()) {
    vec<char> tmp;
    rep(i, vv.size()) { tmp.push_back(vv[vv.size() - 1 - i][j]); }
    res.push_back(tmp);
  }
  vv = res;
}
bool in(int r, int c) { return r >= 0 && r < 4 && c >= 0 && c < 4; }
bool canPut(vec<vec<char>> &vv, int r, int c) {
  rep(i, vv.size()) {
    rep(j, vv[i].size()) if (vv[i][j] == '#' && !in(i + r, j + c)) return false;
  }
  return true;
}
bool dfs(vec<vec<vec<char>>> &ps, vec<vec<int>> &used, int psi) {
  if (psi == 3) {
    bool resb = true;
    for (auto v : used)
      for (auto sc : v)
        if (sc == 0 || sc > 1) resb = false;
    return resb;
  }
  rep2(i, -3, 4) {
    rep2(j, -3, 4) {
      if (canPut(ps[psi], i, j)) {
        rep(k, 4) rep(l, 4) if (ps[psi][k][l] == '#') used[k + i][l + j]++;
        if (dfs(ps, used, psi + 1)) return true;
        rep(k, 4) rep(l, 4) if (ps[psi][k][l] == '#') used[k + i][l + j]--;
      }
    }
  }
  return false;
}
int main() {
  vec<vec<vec<char>>> ps(3, vec<vec<char>>(4, vec<char>(4)));
  rep(i, 3) rep(j, 4) rep(k, 4) cin >> ps[i][j][k];

  vec<vec<int>> used(4, vec<int>(4));
  bool ansb = false;
  rep(i, 4) {
    Rotater90(ps[1]);
    rep(j, 4) {
      Rotater90(ps[2]);
      vec<vec<int>> used(4, vec<int>(4));
      ansb |= dfs(ps, used, 0);
    }
  }

  if (ansb)
    print("Yes");
  else
    print("No");

  return 0;
}