bool isPrime(ll n) {
  for (ll i = 2; i < n; i++) {
    if (i * i > n) break;
    if (n % i == 0) return false;
  }
  return true;
}