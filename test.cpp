#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec vector
using ll = long long;
template <class T>
void print(T out, string end = "\n") {
  cout << out << end;
}
template <class T>
void print(vector<T> v) {
  for (unsigned long i = 0; i < v.size(); i++)
    cout << v[i] << " \n"[i == v.size() - 1];
}

bool isPrime(int n) {
  rep2(i, 2, n) {
    if (i * i > n) break;
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  ll n;
  cin >> n;

  ll ans = 0;
  vec<int> primes;
  rep2(i, 2, pow(10, 6)) if (isPrime(i)) primes.push_back(i);
  rep(i, primes.size()) {
    int top = i + 1, tail = primes.size();
    if (primes[i] * pow(primes[top], 3) > n) break;
    while (top + 1 < tail) {
      int mid = (top + tail) / 2;
      if (primes[i] * pow(primes[mid], 3) <= n)
        top = mid;
      else
        tail = mid;
    }
    ans += top - i;
  }
  print(ans);

  return 0;
}