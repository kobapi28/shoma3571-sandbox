#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  double a,b,c,x;
  cin >> a >> b >> c >> x;

  if (x <= a) {
    // 確実にもらえる範囲
    cout << 1 << endl;
  } else if (x <= b) {
    cout << (c/(b-a)) << endl;
  } else {
    cout << 0 << endl;
  }
}