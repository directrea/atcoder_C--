struct SegmentTree {
  vector<int> dat = vector<int>(3000000, 0);
  int siz = 1;
  SegmentTree(int n) {
    while (n > siz) siz <<= 1;
  }

  void update(int pos, int x) {
    pos += siz - 1;
    dat[pos] = x;
    while (pos >= 2) {
      pos /= 2;
      dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
    }
  }
  int query(int tl, int tr, int l, int r, int u = 1) {
    if (tr <= l || r <= tl) return INT32_MIN;
    if (tl <= l && r <= tr) return dat[u];
    int mid = (l + r) / 2;
    int lmax = query(tl, tr, l, mid, u * 2);
    int rmax = query(tl, tr, mid, r, u * 2 + 1);
    return max(lmax, rmax);
  }
};