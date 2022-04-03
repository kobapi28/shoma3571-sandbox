#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int v,a,b,c;
  cin >> v >> a >> b >> c;

  while(true) {
    v = v-a;
  if (v < 0) {
    cout << "F" << endl;
    return 0;
  }

  v = v-b;
  if (v<0) {
    cout << "M" << endl;
    return 0;
  }

  v = v-c;
  if (v<0) {
    cout << "T" << endl;
    return 0;
  }
  }
}