#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<pair<int, int>> a(n);
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    a[i] = make_pair(x, i+1);
  }

  sort(a.begin(), a.end());
  cout << a[n-2].second << endl;
}