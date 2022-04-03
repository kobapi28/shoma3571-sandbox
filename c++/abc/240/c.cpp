#include <iostream>
#include <vector>
using namespace std;

int f(int a, int b, int x) {
  if (a + b >= x) return -1;
  else return a + b;
}

int main() {
  int n,x;
  cin >> n >> x;
  vector<int> a(n), b(n);
  for (int i=0; i<n; i++) {
    cin >> a[i] >> b[i];
  }

  // vector<int> vc{a[0], b[0]};
  // for (int i=1; i<n; i++) {
  //   int vcsize = vc.size();
  //   for (int j=0; j<vcsize; j++) {
  //     int y = vc[j];
  //     if (y+a[i] <= x) vc.push_back(y+a[i]);
  //     if (y+b[i] <= x) vc.push_back(y+b[i]);
  //   }
  //   vc.erase(vc.begin(), vc.begin()+vcsize);
  // }

  // for (int i=0; i<vc.size(); i++) {
  //   if (vc[i] == x) {
  //     cout << "Yes" << endl;
  //     return 0;
  //   }
  // }

  // cout << "No" << endl;
  // return 0;
}