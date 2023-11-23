#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec vector
using ll = long long;
ll mod = 2147483647;
template <class T> void print(T out, string end = "\n") { cout << out << end; }
template <class T> void print(vector<T> v) {
  for (unsigned long i = 0; i < v.size(); i++) cout << v[i] << " \n"[i == v.size() - 1];
}

int myrand(int low, int high) { return low + rand() % (high - low); }

int main() {
  rep(i, 10) print(myrand(1, 2));
  return 0;
}