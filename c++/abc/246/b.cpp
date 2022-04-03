#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  double a,b;
  cin >> a >> b;

  double x = sqrt(pow(a, 2)+pow(b, 2));

  cout << setprecision(10) << a/x << " " << b/x << endl;
}