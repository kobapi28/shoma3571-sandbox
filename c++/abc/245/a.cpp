#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (a==c && b==d) {
    cout << "Takahashi" << endl;
  } else if (a==c && b < d) {
    cout << "Takahashi" << endl;
  } else if (a < c) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }
}