void Rotater90(vec<vec<char>> &vv) {
  vec<vec<char>> res;
  rep(j, vv[0].size()) {
    vec<char> tmp;
    rep(i, vv.size()) { tmp.push_back(vv[vv.size() - 1 - i][j]); }
    res.push_back(tmp);
  }
  vv = res;
}