bool isPrime(int n) {
  for (int i = 2; i < n; i++) {
    if (i * i > n) break;
    if (n % i == 0) return false;
  }
  return true;
}