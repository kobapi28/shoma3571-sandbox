#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<bool> v(2*n+2);

  for (int i=1; i<2*n+2; i++) {
    v[i] = false;
  }

  while (true) {
    for (int i=1; i<2*n+2; i++) {
      if (v[i] == false) {
        v[i] = true;
        cout << i << endl << flush;
        break;
      }
    }
    // 相手側
    int x;
    cin >> x;
    if (x == 0) {
      return 0;
    }
    v[x] = true;
  }
}