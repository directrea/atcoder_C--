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
void random_generate(int N, vector<int>& A) {
  // rand() % N + 1
  for (int i = 0; i < N; i++) A[i] = i + 1;
  shuffle(A.begin(), A.end(), mt19937(0));
}

vector<int> solve(int N, vector<int> a) { return vec<int>; }

vector<int> solveSimple(int n, vector<int> a) { return vec<int>; }

int main() {
  for (int i = 0; i < 1000; i++) {
    int N = 10;
    vector<int> A(N);
    random_generate(N, A);
    auto j1 = solve(N, A);
    auto j2 = solveSimple(N, A);
    if (!equal(j1.begin(), j1.end(), j2.begin())) {
      print(A);
    }
  }

  return 0;
}