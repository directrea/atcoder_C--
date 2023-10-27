using ll long long;
ll modpow(ll n, ll k, ll mod = 2147483647) {
  ll res = 1;
  while (k > 0) {
    if (k & 1) res = res * n % mod;
    k >>= 1;
    n = n * n % mod;
  }
  return res;
}

ll modinv(ll a, ll mod) { return modpow(a, mod - 2, mod); }