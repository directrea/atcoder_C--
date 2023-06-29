#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define endl "\n"
using ll = long long;
template <class T>
void print(T out, string end = "\n") {
  cout << out << end;
}
template <class T>
void print(vector<T> v, string sep = " ") {
  for (unsigned long i = 0; i < v.size(); i++) {
    if (i == 0)
      cout << v[i];
    else
      cout << sep << v[i];
  }
  cout << endl;
}

int main() {
  vector<int> v{1, 2, 3, 4};
  print(v);

  return 0;
}