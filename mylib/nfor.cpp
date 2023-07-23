void nCr(vector<int> &store, int n, int r, int start = 0) {
  if (store.size() == r) {
    print(store);
    return;
  }
  rep2(i, start, n) {
    store.push_back(i);
    nCr(store, n, r, i + 1);
    store.pop_back();
  }
}