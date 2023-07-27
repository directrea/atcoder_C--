long long pow(long long n, long long k, long long mod = 2147483647) {
  long long res = 1;
  while (k > 0) {
    if (k & 1) res = res * n % mod;
    k >>= 1;
    n = n * n % mod;
  }
  return res;
}