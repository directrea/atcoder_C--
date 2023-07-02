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
void print(vector<T> v, string sep = " ") {
  for (unsigned long i = 0; i < v.size(); i++) {
    if (i == 0)
      cout << v[i];
    else
      cout << sep << v[i];
  }
  cout << endl;
}
vector<char> snuke{'s', 'n', 'u', 'k', 'e'};
vec<vec<char>> grid;
vec<vec<bool>> went;

int main() {
  int h, w;
  cin >> h >> w;

  grid = vec<vec<char>>(h, vec<char>(w));
  rep(i, h) rep(j, w) cin >> grid[i][j];
  went = vec<vec<bool>>(h, vec<bool>(w));

  return 0;
}
